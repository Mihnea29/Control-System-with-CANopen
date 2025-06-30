#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


extern "C" {
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_rtc.h"
#include "CO_app_STM32.h"
extern CO_SDO_abortCode_t
read_SDO(CO_SDOclient_t* SDO_C, uint8_t nodeId, uint16_t index, uint8_t subIndex, uint8_t* buf, size_t bufSize,
		size_t* readSize);
extern CO_SDO_abortCode_t
write_SDO(CO_SDOclient_t* SDO_C, uint8_t nodeId, uint16_t index, uint8_t subIndex, uint8_t* data, size_t dataSize);
extern RTC_HandleTypeDef hrtc;
extern CANopenNodeSTM32 canOpenNodeSTM32;
extern CO_t *CO;
}


uint32_t LED_CONTROL = 0; // 1   2  4   6  8  16
uint16_t HBconsTimeout =1500;
uint16_t HBprodTime = 0;
bool HBprodTimeValid = false;

#define POZ_LUMINI_POZITII 			0
#define POZ_SEMNALIZARE_STINGA 		1
#define POZ_SEMNALIZARE_DREAPTA 	2
#define POZ_FAZA_LUNGA 				3
#define POZ_FAZA_LUNGA_FLASH 		4


#define MASK_LUMINI_POZITII 		0x00000001
#define MASK_SEMNALIZARE_STINGA 	0x00000002
#define MASK_SEMNALIZARE_DREAPTA 	0x00000004
#define MASK_FAZA_LUNGA 			0x00000008
#define MASK_FAZA_LUNGA_FLASH 		0x00000010

#define GET_LUMINI_POZITII(val) 	    (val & 0x00000001)
#define GET_SEMNALIZARE_STINGA(val) 	((val & 0x00000002) >> 1 )
#define GET_SEMNALIZARE_DREAPTA(val) 	((val & 0x00000004) >> 2 )
#define GET_FAZA_LUNGA(val) 	        ((val & 0x00000008) >> 3 )
#define GET_FAZA_LUNGA_FLASH(val) 	    ((val & 0x00000010) >> 4 )

#define TOGGLE_LUMINI_POZITII(val) 	    val ^= 0x00000001;
#define TOGGLE_SEMNALIZARE_STINGA(val) 	    val ^= 0x00000002;
#define TOGGLE_SEMNALIZARE_DREAPTA(val) 	    val ^= 0x00000004;
#define TOGGLE_FAZA_LUNGA(val) 	    val ^= 0x00000008;
#define TOGGLE_FAZA_LUNGA_FLASH(val) 	    val ^= 0x00000010;




Model::Model() : modelListener(nullptr)
{
}

void Model::tick()
{
	static uint32_t counter = 0;
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	modelListener->updateCANID(CO->NMT->nodeId);
	//    	   for(int i = 0 ; i < HB_CONS_NODES ; i++)
	//    	   {
	modelListener->setHBconsumerTimeout(7, HBconsTimeout);
	//    	   }

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	modelListener->updateTime(
			sTime.Hours,
			sTime.Minutes,
			sTime.Seconds
	);
	modelListener->updateData(
			sDate.WeekDay,
			sDate.Date,
			sDate.Month,
			sDate.Year
	);

	for(int i = 0 ; i < HB_CONS_NODES ; i++)
	{
		modelListener->setNodeInfo( i, CO->HBconsMonitoredNodes[i].nodeId, CO->HBconsMonitoredNodes[i].HBstate , CO->HBconsMonitoredNodes[i].NMTstate);
	}

	if(counter%100 == 0)
		modelListener->setLight( GET_LUMINI_POZITII( LED_CONTROL ),
				(GET_SEMNALIZARE_STINGA(LED_CONTROL) & ((counter % 200) / 100)),
				(GET_SEMNALIZARE_DREAPTA(LED_CONTROL) & ((counter % 200) / 100)),
				GET_FAZA_LUNGA_FLASH(LED_CONTROL) ? (GET_FAZA_LUNGA_FLASH(LED_CONTROL) & ((counter % 500) / 250))
						: GET_FAZA_LUNGA(LED_CONTROL)    );

	counter++;
}



void Model::HBconsTimeoutInc(int index)
{
	HBconsTimeout += 100;
	modelListener->setHBconsumerTimeout(7, HBconsTimeout);
}

void Model::HBconsTimeoutDec(int index)
{
	if(HBconsTimeout > 100)
		HBconsTimeout -= 100;
	modelListener->setHBconsumerTimeout(7, HBconsTimeout);
}

void Model::getHBprodTime(int index)
{
	size_t bytesRead = 0;
	uint16_t HB_VALUE = 0;
	// SDO read
	read_SDO(canOpenNodeSTM32.canOpenStack->SDOclient, CO->HBconsMonitoredNodes[index].nodeId, 0x1017, 0x00, (uint8_t*)&HB_VALUE, sizeof(HB_VALUE), &bytesRead);
	if(bytesRead == 2) {
		HBprodTime = HB_VALUE;
		HBprodTimeValid = true;
		modelListener->updateHBprodTime(index, HBprodTime);
	}

}

void Model::setHBprodTime(int index)
{
	//SDE write
	write_SDO(canOpenNodeSTM32.canOpenStack->SDOclient, CO->HBconsMonitoredNodes[index].nodeId, 0x1017, 0x00, (uint8_t*)&HBprodTime, sizeof(HBprodTime));
	//..........
}


void Model::HBprodTimeInc(int index)
{
	if( HBprodTimeValid )
	{
		HBprodTime +=100;
		modelListener->updateHBprodTime(index, HBprodTime);
	}
}

void Model::HBprodTimeDec(int index)
{
	if( HBprodTimeValid && HBprodTime >=100 )
	{
		HBprodTime -=100;
		modelListener->updateHBprodTime(index, HBprodTime);
	}
}
