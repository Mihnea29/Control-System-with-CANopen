#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


extern "C" {
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_rtc.h"
extern RTC_HandleTypeDef hrtc;

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
}
