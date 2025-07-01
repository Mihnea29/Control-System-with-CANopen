#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


extern "C" {
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_rtc.h"
#include "CO_app_STM32.h"
#include "main.h"
#include "CANopen.h"
#include "OD.h"
extern CO_SDO_abortCode_t
read_SDO(CO_SDOclient_t* SDO_C, uint8_t nodeId, uint16_t index, uint8_t subIndex, uint8_t* buf, size_t bufSize,
		size_t* readSize);
extern CO_SDO_abortCode_t
write_SDO(CO_SDOclient_t* SDO_C, uint8_t nodeId, uint16_t index, uint8_t subIndex, uint8_t* data, size_t dataSize);
extern RTC_HandleTypeDef hrtc;
extern CANopenNodeSTM32 canOpenNodeSTM32;
extern CO_t *CO;
#define log_printf(macropar_message, ...) printf(macropar_message, ##__VA_ARGS__)
}


Model::Model() : modelListener(nullptr)
{
	current_idx = 7;
	for(int i = 0 ; i < HB_CONS_NODES; i++)
	{
	    HBconsTimeout[i] = 2500;
	    HBprodTime[i] = 0;
	    HBprodTimeValid[i] = false;
	}
}

void Model::tick()
{
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	//Screen2 - CLOCK & TIMESTAMP
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


	//Screen3 - HEARTBEAT
	modelListener->setCANID(CO->NMT->nodeId);
	for(int i = 0 ; i < HB_CONS_NODES ; i++)
	{
		modelListener->setNodeInfo( i, CO->HBconsMonitoredNodes[i].nodeId, CO->HBconsMonitoredNodes[i].HBstate);
	}

	modelListener->setNodeInfoDetail( current_idx, CO->HBconsMonitoredNodes[current_idx].HBstate ,
			CO->HBconsMonitoredNodes[current_idx].NMTstate,
			HBconsTimeout[current_idx],
			HBprodTime[current_idx],
			HBprodTimeValid[current_idx] );

}



void Model::HBconsTimeoutInc(int index)
{
	current_idx = index;
	HBconsTimeout[current_idx] += 100;
	modelListener->setNodeInfoDetail( current_idx, CO->HBconsMonitoredNodes[current_idx].HBstate ,
			CO->HBconsMonitoredNodes[current_idx].NMTstate,
			HBconsTimeout[current_idx],
			HBprodTime[current_idx],
			HBprodTimeValid[current_idx] );
}

void Model::HBconsTimeoutDec(int index)
{
	current_idx = index;
	if(HBconsTimeout[current_idx] > 100)
		HBconsTimeout[current_idx] -= 100;
	modelListener->setNodeInfoDetail( current_idx, CO->HBconsMonitoredNodes[current_idx].HBstate ,
			CO->HBconsMonitoredNodes[current_idx].NMTstate,
			HBconsTimeout[current_idx],
			HBprodTime[current_idx],
			HBprodTimeValid[current_idx] );
}

void Model::getHBprodTime(int index)
{
	size_t bytesRead = 0;
	uint16_t HB_VALUE = 0;

	current_idx = index;

	// SDO read
	read_SDO(canOpenNodeSTM32.canOpenStack->SDOclient, CO->HBconsMonitoredNodes[index].nodeId, 0x1017, 0x00, (uint8_t*)&HB_VALUE, sizeof(HB_VALUE), &bytesRead);

	if(bytesRead == 2) {
		HBprodTime[current_idx] = HB_VALUE;
		HBprodTimeValid[current_idx] = true;
		modelListener->setNodeInfoDetail( current_idx, CO->HBconsMonitoredNodes[current_idx].HBstate ,
				CO->HBconsMonitoredNodes[current_idx].NMTstate,
				HBconsTimeout[current_idx],
				HBprodTime[current_idx],
				HBprodTimeValid[current_idx] );
	}

}

void Model::setHBprodTime(int index)
{
	//SDE write
	write_SDO(canOpenNodeSTM32.canOpenStack->SDOclient, CO->HBconsMonitoredNodes[index].nodeId, 0x1017, 0x00, (uint8_t*)&HBprodTime[index], sizeof(HBprodTime[index]));
}


void Model::HBprodTimeInc(int index)
{
	current_idx = index;
	if( HBprodTimeValid[current_idx] )
	{
		HBprodTime[current_idx] +=100;
		modelListener->setNodeInfoDetail( current_idx, CO->HBconsMonitoredNodes[current_idx].HBstate ,
				CO->HBconsMonitoredNodes[current_idx].NMTstate,
				HBconsTimeout[current_idx],
				HBprodTime[current_idx],
				HBprodTimeValid[current_idx] );
	}
}

void Model::HBprodTimeDec(int index)
{
	current_idx = index;
	if( HBprodTimeValid[current_idx] && HBprodTime[current_idx] >=100 )
	{
		HBprodTime[current_idx] -=100;
		modelListener->setNodeInfoDetail( current_idx, CO->HBconsMonitoredNodes[current_idx].HBstate ,
				CO->HBconsMonitoredNodes[current_idx].NMTstate,
				HBconsTimeout[current_idx],
				HBprodTime[current_idx],
				HBprodTimeValid[current_idx] );
	}
}


void Model::toggleButton(int index)
{
	if(index == 1)
	{
        OD_set_u32(OD_find(OD, 0x6000), 0x00, LED_LEFT_SIGNAL_MASK, false);
	}
}
