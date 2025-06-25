#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void getCANOpenTimeAndDate(uint8_t* hours, uint8_t* minutes, uint8_t* secs, uint8_t* day, uint8_t* date, uint8_t* mounth, uint8_t* year)
{
	static uint16_t CANOpentime = 1000, CANOpenDate = 250;

    *secs = CANOpentime % 60;
    *minutes = (CANOpentime % 3600) / 60;
    *hours = CANOpentime / 3600;

    *day = 6;
    *date = 24;
    *mounth = 7;
    *year = 16+25;

	CANOpentime++;
}

void Model::tick()
{
	uint8_t hours, minutes, secs, day, date, mounth, year;
	getCANOpenTimeAndDate(&hours, &minutes, &secs, &day, &date, &mounth, &year);
	modelListener->updateTime(hours, minutes, secs);
	modelListener->updateData(day, date, mounth, year);
}
