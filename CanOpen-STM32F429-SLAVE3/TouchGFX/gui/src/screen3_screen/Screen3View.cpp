#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
    presenter->getNodeInfo();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}


//typedef enum {
//    CO_NMT_UNKNOWN = -1,           /**< -1, Device state is unknown (for heartbeat consumer) */
//    CO_NMT_INITIALIZING = 0,      /**< 0, Device is initializing */
//    CO_NMT_PRE_OPERATIONAL = 127,   /**< 127, Device is in pre-operational state */
//    CO_NMT_OPERATIONAL = 5,       /**< 5, Device is in operational state */
//    CO_NMT_STOPPED = 4            /**< 4, Device is stopped */
//} CO_NMT_internalState_t;

char CO_NMT_internalState_Text_[][20] = { "Unknown",
                                            "Initializing",
                                            "Pre Operational",
                                            "Operational",
                                            "Stoped" };

char* CO_NMT_internalState2Text(CO_NMT_internalState_t state)
{
    int index;
    switch (state) {
        case CO_NMT_UNKNOWN:
            index = 0; break;
        case CO_NMT_INITIALIZING:
            index = 1; break;
        case CO_NMT_PRE_OPERATIONAL:
            index = 2; break;
        case CO_NMT_OPERATIONAL:
            index = 3; break;
        case CO_NMT_STOPPED:
            index = 4; break;
        default: index = 0;
    }
    return CO_NMT_internalState_Text_[index];
}


void Screen3View::updateHeartbeatTime(uint8_t CAN_ID, CO_NMT_internalState_t NMTstate, uint32_t HeartbeatTime)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", CAN_ID);
	Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%s", CO_NMT_internalState2Text(NMTstate));
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", HeartbeatTime);

	textArea1.invalidate();
	textArea3.invalidate();
	textArea2.invalidate();
}

void Screen3View::changeScreen(int ecran)
{
	if( ecran == 1)
		application().gotoScreen1ScreenWipeTransitionWest();
	if( ecran == 2)
	    application().gotoScreen2ScreenWipeTransitionWest();
	if( ecran == 3)
	    application().gotoScreen3ScreenWipeTransitionEast();
}
