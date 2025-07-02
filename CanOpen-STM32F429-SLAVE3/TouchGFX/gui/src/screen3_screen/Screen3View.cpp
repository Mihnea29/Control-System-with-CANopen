#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::updateHeartbeatTime(uint8_t CAN_ID, uint32_t HeartbeatTime)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", CAN_ID);
	textArea1.invalidate();

    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", HeartbeatTime);
	textArea2.invalidate();
}

void Screen3View::changeScreen(int ecran)
{
	if( ecran == 0)
		application().gotoScreen1ScreenWipeTransitionWest();
	if( ecran == 1)
	    application().gotoScreen2ScreenWipeTransitionWest();
//	if( ecran == 2)
//	    application().gotoScreen3ScreenWipeTransitionWest();
}
