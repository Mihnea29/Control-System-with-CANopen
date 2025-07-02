#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/common/FrontendApplication.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::changeScreen(int ecran)
{
	if( ecran == 0)
		application().gotoScreen1ScreenWipeTransitionWest();
	if( ecran == 1)
	    application().gotoScreen2ScreenWipeTransitionWest();
//	if( ecran == 2)
//	    application().gotoScreen3ScreenWipeTransitionWest();
}
