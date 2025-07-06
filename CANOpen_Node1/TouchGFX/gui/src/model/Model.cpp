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
	for(int i = 0 ; i < HB_CONS_NODES; i++)
	{
	    HBconsTimeout[i] = 2500;
	    HBprodTime[i] = 0;
	    HBprodTimeValid[i] = false;
	}
}

void Model::tick()
{
    static uint8_t prev_hours = 0, prev_minutes = 0, prev_seconds = 0;
	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;

	//Screen2 - CLOCK & TIMESTAMP
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    if( (prev_hours != sTime.Hours || prev_minutes != sTime.Minutes) || prev_seconds != sTime.Seconds)
    {
    	modelListener->updateTime(
    			sTime.Hours,
    			sTime.Minutes,
    			sTime.Seconds
    	);
        prev_hours = sTime.Hours; prev_minutes = sTime.Minutes; prev_seconds = sTime.Seconds;
    }
	modelListener->updateData(
			sDate.WeekDay,
			sDate.Date,
			sDate.Month,
			sDate.Year
	);


	//Screen3 - HEARTBEAT
	modelListener->setCANID(CO->NMT->nodeId, CO->NMT->operatingState);
	for(int i = 0 ; i < HB_CONS_NODES ; i++)
	{
		modelListener->setNodeInfo( i, CO->HBconsMonitoredNodes[i].nodeId, CO->HBconsMonitoredNodes[i].HBstate);
	}

}

void Model::getTimeDate()
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


}


void Model::getNodeInfoDetail(int index)
{
	modelListener->setNodeInfoDetail( index,
			CO->HBconsMonitoredNodes[index].nodeId,
			CO->HBconsMonitoredNodes[index].HBstate ,
			CO->HBconsMonitoredNodes[index].NMTstate,
			HBconsTimeout[index],
			HBprodTime[index],
			HBprodTimeValid[index] );
}


void Model::HBconsTimeoutInc(int index)
{
	HBconsTimeout[index] += 100;
	modelListener->setNodeInfoDetail( index,
			CO->HBconsMonitoredNodes[index].nodeId,
			CO->HBconsMonitoredNodes[index].HBstate ,
			CO->HBconsMonitoredNodes[index].NMTstate,
			HBconsTimeout[index],
			HBprodTime[index],
			HBprodTimeValid[index] );}

void Model::HBconsTimeoutDec(int index)
{
	if(HBconsTimeout[index] > 100)
		HBconsTimeout[index] -= 100;
	    modelListener->setNodeInfoDetail( index,
			CO->HBconsMonitoredNodes[index].nodeId,
			CO->HBconsMonitoredNodes[index].HBstate ,
			CO->HBconsMonitoredNodes[index].NMTstate,
			HBconsTimeout[index],
			HBprodTime[index],
			HBprodTimeValid[index] );
}

void Model::getHBprodTime(int index)
{
	size_t bytesRead = 0;
	uint16_t HB_VALUE = 0;

	// SDO read
	read_SDO(canOpenNodeSTM32.canOpenStack->SDOclient, CO->HBconsMonitoredNodes[index].nodeId, 0x1017, 0x00, (uint8_t*)&HB_VALUE, sizeof(HB_VALUE), &bytesRead);

	if(bytesRead == 2) {
		HBprodTime[index] = HB_VALUE;
		HBprodTimeValid[index] = true;
		modelListener->setNodeInfoDetail( index,
				CO->HBconsMonitoredNodes[index].nodeId,
				CO->HBconsMonitoredNodes[index].HBstate ,
				CO->HBconsMonitoredNodes[index].NMTstate,
				HBconsTimeout[index],
				HBprodTime[index],
				HBprodTimeValid[index] );
	}
}

void Model::setHBprodTime(int index)
{
	//SDE write
	write_SDO(canOpenNodeSTM32.canOpenStack->SDOclient, CO->HBconsMonitoredNodes[index].nodeId, 0x1017,
			0x00, (uint8_t*)&(HBprodTime[index]), sizeof(HBprodTime[index]));
}


void Model::HBprodTimeInc(int index)
{
	if( HBprodTimeValid[index] )
	{
		HBprodTime[index] +=100;
		modelListener->setNodeInfoDetail( index,
				CO->HBconsMonitoredNodes[index].nodeId,
				CO->HBconsMonitoredNodes[index].HBstate ,
				CO->HBconsMonitoredNodes[index].NMTstate,
				HBconsTimeout[index],
				HBprodTime[index],
				HBprodTimeValid[index] );
	}
}

void Model::HBprodTimeDec(int index)
{
	if( HBprodTimeValid[index] && HBprodTime[index] >=100 )
	{
		HBprodTime[index] -=100;
		modelListener->setNodeInfoDetail( index,
				CO->HBconsMonitoredNodes[index].nodeId,
				CO->HBconsMonitoredNodes[index].HBstate ,
				CO->HBconsMonitoredNodes[index].NMTstate,
				HBconsTimeout[index],
				HBprodTime[index],
				HBprodTimeValid[index] );
	}
}


void Model::toggleButton(int buttonNumber)
{
    static uint32_t current_leds = 0;
    static uint32_t saved_signals = 0;

    switch(buttonNumber) {
        case 1:
            current_leds ^= LED_LEFT_SIGNAL_MASK;
            break;
        case 2:
            current_leds ^= LED_RIGHT_SIGNAL_MASK;
            break;
        case 3:
            if ((current_leds & LED_LEFT_SIGNAL_MASK) && (current_leds & LED_RIGHT_SIGNAL_MASK)) {
                current_leds &= ~(LED_LEFT_SIGNAL_MASK | LED_RIGHT_SIGNAL_MASK);
                current_leds |= saved_signals;
            } else {
                saved_signals = current_leds & (LED_LEFT_SIGNAL_MASK | LED_RIGHT_SIGNAL_MASK);
                current_leds |= (LED_LEFT_SIGNAL_MASK | LED_RIGHT_SIGNAL_MASK);
            }
            break;
        case 4:
            current_leds ^= LED_HEADLIGHT_MASK;
            break;
        case 5:
            current_leds ^= LED_HIGH_BEAM_MASK;
            break;
        case 6:
            current_leds ^= LED_FLASH_MASK;
            break;
        default:
            return;
    }

    OD_set_u32(OD_find(OD, 0x6000), 0x00, current_leds, false);
}
