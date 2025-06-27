#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C" {
#include "CANopen.h"
extern CO_t *CO;
}

#include <stm32f4xx_hal.h>

static bool bisect(uint16_t y) {
    return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
}

void ConvertDaysSince1984(uint32_t daysSince1984,
                         uint8_t* yearOffset,
                         uint8_t* month,
                         uint8_t* date,
                         uint8_t* weekday)
{
    // 1.1.1984 e duminica => weekday = 0
    const uint8_t baseWeekday = 0;

    uint32_t days = daysSince1984;
    uint16_t fullYear = 1984;
    while (true) {
        uint16_t dy = bisect(fullYear) ? 366 : 365;
        if (days < dy) break;
        days -= dy;
        ++fullYear;
    }

    static uint8_t monthLen[12] = {
        31,28,31,30,31,30,31,31,30,31,30,31
    };
    uint8_t m = 1;
    for (int i = 0; i < 12; i++) {
        uint8_t ml = monthLen[i];
        if (i == 1 && bisect(fullYear)) ml = 29;
        if (days < ml) break;
        days -= ml;
        ++m;
    }

    uint8_t d = days + 1;

    uint8_t w = (baseWeekday + daysSince1984) % 7;

    *yearOffset = (fullYear >= 1984) ? (fullYear - 1984) : 0;
    *month = m;
    *date = d;
    *weekday = w;
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    uint32_t ms = CO->TIME->ms;   // ms de la miezul noptii
    uint32_t days = CO->TIME->days; // zile de la 1.1.1984

    static uint8_t prev_hours = 0, prev_minutes = 0, prev_seconds = 0;
    uint8_t yearOffset,  month, date, weekday;
    uint8_t hours, minutes, seconds;

    hours = ms / 3600000;
    minutes = (ms % 3600000) / 60000;
    seconds = (ms % 60000) / 1000;
    if( (prev_hours != hours || prev_minutes != minutes) || prev_seconds != seconds)
    {
        modelListener->updateTime(hours, minutes, seconds);
        prev_hours = hours; prev_minutes = minutes; prev_seconds = seconds;
    }

    ConvertDaysSince1984(days, &yearOffset, &month, &date, &weekday);
    modelListener->updateData(weekday, date, month, yearOffset);

    modelListener->updateHeartbeatTime(10, 1020);
}
