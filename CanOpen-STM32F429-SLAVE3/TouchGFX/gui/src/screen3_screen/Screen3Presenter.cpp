#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::updateHeartbeatTime(uint8_t CAN_ID, uint32_t HeartbeatTime)
{
	view.updateHeartbeatTime(CAN_ID, HeartbeatTime);
}

void Screen3Presenter::changeScreen(int ecran)
{
     view.changeScreen(ecran);
}

