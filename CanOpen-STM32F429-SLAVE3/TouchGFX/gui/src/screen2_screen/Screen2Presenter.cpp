#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::updateTime(uint8_t hour, uint8_t minute, uint8_t second)
{
	view.updateTime(hour, minute, second);
}

void Screen2Presenter::updateData(uint8_t WeekDay, uint8_t Date, uint8_t Month, uint8_t Year)
{
	view.updateData(WeekDay, Date, Month, Year);
}

void Screen2Presenter::changeScreen(int ecran)
{
     view.changeScreen(ecran);
}
