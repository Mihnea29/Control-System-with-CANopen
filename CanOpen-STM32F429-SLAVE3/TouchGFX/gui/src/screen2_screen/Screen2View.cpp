#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::updateTime(uint8_t hour, uint8_t minute, uint8_t second)
{
	analogClock.setTime24Hour(hour, minute, second);
	analogClock.invalidate();

	digitalClock.setTime24Hour(hour, minute, second);
	digitalClock.invalidate();

}


const char DayOfWeek[8][20] = {
		"Unknown",
		"Luni",
		"Marti",
		"Miercuri",
		"Joi",
		"Vineri",
		"Sambata",
		"Duminica"
};

const char MonthOfYear[13][20] = {
		"Unk",
		"Ian",
		"Feb",
		"Mar",
		"Apr",
		"Mai",
		"Iun",
		"Iul",
		"Aug",
		"Sep",
		"Oct",
		"Noe",
		"Dec"
};



void Screen2View::updateData(uint8_t WeekDay, uint8_t Date, uint8_t Month, uint8_t Year)
{
	Unicode::UnicodeChar bufferDayOfWeek[20];
	Unicode::UnicodeChar bufferMonthOfYear[20];

	Unicode::strncpy(bufferDayOfWeek, DayOfWeek[WeekDay], 20);
	Unicode::strncpy(bufferMonthOfYear, MonthOfYear[Month], 20);

	Unicode::snprintf(textDataBuffer, TEXTDATA_SIZE, "%s, %2d %s %4d", bufferDayOfWeek, (int)Date, bufferMonthOfYear, (int)(Year+1984));
	textData.invalidate();
}
