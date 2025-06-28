#include <gui/screen3_screen/Screen3View.hpp>
#include <touchgfx/Color.hpp>

#define NodeXNMTState(i)    		Node##i##NMTState
#define NodeXNMTStateBuffer(i)    	Node##i##NMTStateBuffer
#define NodeXCANID(i)   			Node##i##CANID
#define NodeXCANIDBuffer(i)    		Node##i##CANIDBuffer
#define NodeXStatus(i)    			Node##i##Status
#define NodeXStatusPainter(i)    	Node##i##StatusPainter

#define InitPointers(i)             NodeNMTState[i] = &(Node##i##NMTState); \
                                    NodeNMTStateBuffer[i] = Node##i##NMTStateBuffer; \
                                    NodeCANID[i] = &(Node##i##CANID); \
                                    NodeCANIDBuffer[i] = Node##i##CANIDBuffer; \
                                    NodeStatus[i] = &(Node##i##Status); \
                                    NodeStatusPainter[i] = &(Node##i##StatusPainter);


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

 /*    int i = 0;
         NodeNMTState[i] = &(NodeXNMTState(0));
         NodeNMTStateBuffer[i] = NodeXNMTStateBuffer(0);
         NodeCANID[i] = &(NodeXCANID(0));
         NodeCANIDBuffer[i] = NodeXCANIDBuffer(0);
         NodeStatus[i] = &(NodeXStatus(0));
         NodeStatusPainter[i] = &(NodeXStatusPainter(0));  i++;
*/
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
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
uint8_t HBconsumer_state_colorRGB[][3] = { {0, 0, 0},     // R, G, B
                                           {127, 127, 127},
                                           {0, 255, 0},
										   {237, 127, 16}      };

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

#define NODE_NMTSTATE_SIZE  10
#define NODE_CANID_SIZE     10

void Screen3View::setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate)
{
	Unicode::UnicodeChar bufferNMTstate[20];

	if( CAN_ID != 0 && CAN_ID != 0x100 )
	{
	    NodeStatusPainter[index]->setColor(touchgfx::Color::getColorFromRGB(HBconsumer_state_colorRGB[HBstate][0],
	    																	HBconsumer_state_colorRGB[HBstate][1],
																			HBconsumer_state_colorRGB[HBstate][2]) );
	    Unicode::snprintf(NodeCANIDBuffer[index], NODE_CANID_SIZE, "%d", CAN_ID);

    	Unicode::strncpy(bufferNMTstate, CO_NMT_internalState2Text(HBstate == CO_HBconsumer_ACTIVE? NMTstate : CO_NMT_UNKNOWN), 20);
    	Unicode::snprintf(NodeNMTStateBuffer[index], NODE_NMTSTATE_SIZE, "%s", bufferNMTstate);
	    NodeNMTState[index]->setVisible(true);
	    NodeStatus[index]->setVisible(true);
	}
	else
	{
	    Unicode::snprintf(NodeCANIDBuffer[index], NODE_CANID_SIZE, "%s", "not used");
	    NodeNMTState[index]->setVisible(false);
	    NodeStatus[index]->setVisible(false);
	}

    NodeNMTState[index]->invalidate();
    NodeCANID[index]->invalidate();
    NodeStatus[index]->invalidate();
}
