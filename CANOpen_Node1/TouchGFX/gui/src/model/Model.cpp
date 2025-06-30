#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


extern "C" {
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_rtc.h"
extern RTC_HandleTypeDef hrtc;
extern CO_t *CO;
}

Model::Model() : modelListener(nullptr)
{
}

void Model::tick()
{
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;
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

//    modelListener->setNodeInfo( 0, 3, CO_HBconsumer_ACTIVE, CO_NMT_OPERATIONAL);
//    modelListener->setNodeInfo( 1, 1, CO_HBconsumer_TIMEOUT, CO_NMT_UNKNOWN);
//    modelListener->setNodeInfo( 2, 2, CO_HBconsumer_ACTIVE, CO_NMT_PRE_OPERATIONAL);
//    modelListener->setNodeInfo( 3, 4, CO_HBconsumer_UNCONFIGURED, CO_NMT_INITIALIZING);
//    modelListener->setNodeInfo( 4, 0, CO_HBconsumer_ACTIVE, CO_NMT_PRE_OPERATIONAL);
//    modelListener->setNodeInfo( 5, 0, CO_HBconsumer_ACTIVE, CO_NMT_PRE_OPERATIONAL);
//    modelListener->setNodeInfo( 6, 0, CO_HBconsumer_ACTIVE, CO_NMT_PRE_OPERATIONAL);
//    modelListener->setNodeInfo( 7, 0, CO_HBconsumer_ACTIVE, CO_NMT_PRE_OPERATIONAL);

   for(int i = 0 ; i < HB_CONS_NODES ; i++)
   {
	   modelListener->setNodeInfo( i, CO->HBconsMonitoredNodes[i].nodeId, CO->HBconsMonitoredNodes[i].HBstate , CO->HBconsMonitoredNodes[i].NMTstate);
	   modelListener->setHBconsumerTimeout(i, 1500);
   }

   modelListener->setHBconsumerTimeout(7, 1500);
}
