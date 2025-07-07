#include <gui/screen3_screen/Screen3View.hpp>
#include <touchgfx/Color.hpp>

#define InitPointers(i)             NodeCANID[i] = &(Node##i##CANID); \
                                    NodeCANIDBuffer[i] = Node##i##CANIDBuffer; \
                                    NodeStatus[i] = &(Node##i##Status); \
                                    NodeStatusPainter[i] = &(Node##i##StatusPainter);

int idx = 0;

Screen3View::Screen3View()
{
	InitPointers(0);
	InitPointers(1);
	InitPointers(2);
	InitPointers(3);
	InitPointers(4);
	InitPointers(5);
	InitPointers(6);
	InitPointers(7);
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
    sliderIndex.setValue(idx);
	presenter->getNodeInfoDetail(idx);
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}


//typedef enum {
//    CO_HBconsumer_UNCONFIGURED = 0x00U, /**< Consumer entry inactive */
//    CO_HBconsumer_UNKNOWN = 0x01U,      /**< Consumer enabled, but no heartbeat received yet */
//    CO_HBconsumer_ACTIVE = 0x02U,       /**< Heartbeat received within set time */
//    CO_HBconsumer_TIMEOUT = 0x03U,      /**< No heatbeat received for set time */
//} CO_HBconsumer_state_t;
char HBconsumer_state_Text_[][20] = { "Unconfigured",
                                            "Unknown",
                                            "Active",
                                            "Timeout" };
										//    R,   G,   B
uint8_t HBconsumer_state_colorRGB[][3] = { {  0,   0,   0},     // black
                                           {127, 127, 127},     // gray
                                           {  0, 255,   0},     // green
										   {237, 127,  16}      // orange
										};
char* HBconsumer_state2Text(CO_HBconsumer_state_t state)
{
    if ((state >= CO_HBconsumer_UNCONFIGURED) && (state <= CO_HBconsumer_TIMEOUT))
        return HBconsumer_state_Text_[state];
    return HBconsumer_state_Text_[CO_HBconsumer_UNKNOWN];
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


void Screen3View::setCANID(uint8_t CAN_ID, CO_NMT_internalState_t NMTstate)
{
	Unicode::snprintf(textCANIDBuffer, TEXTCANID_SIZE, "%d", CAN_ID);
	Unicode::strncpy(textNMTStateBuffer, CO_NMT_internalState2Text(NMTstate), TEXTNMTSTATE_SIZE);

	textCANID.invalidate();
	textNMTState.invalidate();
}

#define NODE_CANID_SIZE     20
void Screen3View::setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate)
{
	bool bVisible3 = false;

	if( CAN_ID != 0 && CAN_ID < 0x100 )
	{
		Unicode::snprintf(NodeCANIDBuffer[index], NODE_CANID_SIZE, "%d", CAN_ID);
	    NodeStatusPainter[index]->setColor(touchgfx::Color::getColorFromRGB(HBconsumer_state_colorRGB[HBstate][0],
	    																	HBconsumer_state_colorRGB[HBstate][1],
																			HBconsumer_state_colorRGB[HBstate][2]) );
	    if( idx == index )
	    {
	    	Unicode::strncpy(NodeXHBconsStateBuffer, HBconsumer_state2Text(HBstate), NODEXHBCONSSTATE_SIZE);
	    	Unicode::strncpy( NodeXNMTStateBuffer, CO_NMT_internalState2Text(NMTstate), NODEXNMTSTATE_SIZE );
	    	if( HBstate == CO_HBconsumer_ACTIVE )
	    	{
	    		bVisible3 = true;
	    		NodeXNMTState.setVisible(bVisible3);
	    	}
    		NodeXHBconsState.invalidate();
    	    NodeXNMTState.invalidate();
	    }
	}
	else
	{
    	Unicode::strncpy(NodeCANIDBuffer[index], "*", NODE_CANID_SIZE);
	    NodeStatusPainter[index]->setColor(touchgfx::Color::getColorFromRGB(HBconsumer_state_colorRGB[0][0],
	    																	HBconsumer_state_colorRGB[0][1],
																			HBconsumer_state_colorRGB[0][2]) );
	}

    NodeCANID[index]->invalidate();
    NodeStatus[index]->invalidate();
}


#define NODE_NMTSTATE_SIZE  20

void Screen3View::setNodeInfoDetail( int index, uint8_t CANID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate,
		uint16_t timeoutTime, uint16_t HBprodTime, bool HBprodTimeValid )
{
	bool bVisible1 = false, bVisible2 = false, bVisible3 = false;
	idx  = index;

    if(CANID != 0 && CANID <= 0x100)
    {
        Unicode::snprintf(NodeXCANIDBuffer, NODEXCANID_SIZE, "%d", CANID);

        bVisible1 = true;
        Unicode::strncpy(NodeXHBconsStateBuffer, HBconsumer_state2Text(HBstate), NODEXHBCONSSTATE_SIZE);
    	Unicode::strncpy( NodeXNMTStateBuffer, CO_NMT_internalState2Text(NMTstate), NODEXNMTSTATE_SIZE );
    	if( HBstate == CO_HBconsumer_ACTIVE )
    	{
    		bVisible3 = true;
    	}
    	Unicode::snprintf( NodeXHBconsTimeoutBuffer, NODEXHBCONSTIMEOUT_SIZE, "%d", timeoutTime);
		if( HBprodTimeValid )
		{
			Unicode::snprintf(NodeXHBprodTimeBuffer, NODEXHBPRODTIME_SIZE, "%d", HBprodTime);
			bVisible2 = true;
		}
    }
    else
    {
    	Unicode::strncpy(NodeXCANIDBuffer, "*", NODEXCANID_SIZE);
    }

	NodeXHBconsState.setVisible(bVisible1);
	textArea3.setVisible(bVisible1);
    NodeXHBconsTimeout.setVisible(bVisible1);
    buttonNodeXHBcTDec.setVisible(bVisible1);
	buttonNodeXHBcTInc.setVisible(bVisible1);
	textArea1.setVisible(bVisible1);
	buttonNodeXHBpTGet.setVisible(bVisible1);

    NodeXNMTState.setVisible(bVisible3);

    NodeXHBprodTime.setVisible(bVisible2);
    buttonNodeXHBpTInc.setVisible(bVisible2);
	buttonNodeXHBpTDec.setVisible(bVisible2);
	buttonNodeXHBpTSet.setVisible(bVisible2);

	NodeXCANID.invalidate();

	NodeXHBconsState.invalidate();
    NodeXNMTState.invalidate();
    NodeXHBconsTimeout.invalidate();
    buttonNodeXHBcTDec.invalidate();
	buttonNodeXHBcTInc.invalidate();

	textArea1.invalidate();
	buttonNodeXHBpTGet.invalidate();
    NodeXHBprodTime.invalidate();
    buttonNodeXHBpTInc.invalidate();
	buttonNodeXHBpTDec.invalidate();
	buttonNodeXHBpTSet.invalidate();
}


void Screen3View::indexChangeValue(int value)
{
    // Override and implement this function in Screen3
	idx  = value;
	presenter->getNodeInfoDetail(idx);
}
