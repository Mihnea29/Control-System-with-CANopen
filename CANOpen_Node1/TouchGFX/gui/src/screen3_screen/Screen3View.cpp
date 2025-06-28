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


void Screen3View::setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate)
{
    Unicode::snprintf(NodeNMTStateBuffer[index], NODE_NMTSTATE_SIZE, "%s", CO_NMT_internalState2Text(NMTstate));
    Unicode::snprintf(NodeCANIDBuffer[index], NODE_CANID_SIZE, "%d", CAN_ID);
    NodeStatusPainter[index]->setColor(touchgfx::Color::getColorFromRGB(HBconsumer_state_colorRGB[HBstate][0],
    																	HBconsumer_state_colorRGB[HBstate][1],
																		HBconsumer_state_colorRGB[HBstate][2]) );

    NodeNMTState[index]->invalidate();
    NodeCANID[index]->invalidate();
    NodeStatus[index]->invalidate();
}
