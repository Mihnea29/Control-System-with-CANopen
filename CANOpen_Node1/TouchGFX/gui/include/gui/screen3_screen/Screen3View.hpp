#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
extern "C" {
#include "CANopen.h"
}
#define NODE_NR 8
#define NODE_NMTSTATE_SIZE  10
#define NODE_CANID_SIZE     10

//======================================
/**
 * Heartbeat state of a node
 */
//typedef enum {
//    CO_HBconsumer_UNCONFIGURED = 0x00U, /**< Consumer entry inactive */
//    CO_HBconsumer_UNKNOWN = 0x01U,      /**< Consumer enabled, but no heartbeat received yet */
//    CO_HBconsumer_ACTIVE = 0x02U,       /**< Heartbeat received within set time */
//    CO_HBconsumer_TIMEOUT = 0x03U,      /**< No heatbeat received for set time */
//} CO_HBconsumer_state_t;
//
////======================================
//
///**
// * Internal network state of the CANopen node
// */
//typedef enum {
//    CO_NMT_UNKNOWN = -1,           /**< -1, Device state is unknown (for heartbeat consumer) */
//    CO_NMT_INITIALIZING = 0,      /**< 0, Device is initializing */
//    CO_NMT_PRE_OPERATIONAL = 127,   /**< 127, Device is in pre-operational state */
//    CO_NMT_OPERATIONAL = 5,       /**< 5, Device is in operational state */
//    CO_NMT_STOPPED = 4            /**< 4, Device is stopped */
//} CO_NMT_internalState_t;


class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate);
protected:

    touchgfx::TextAreaWithOneWildcard* NodeNMTState[NODE_NR];
    touchgfx::Unicode::UnicodeChar* NodeNMTStateBuffer[NODE_NR];
    touchgfx::TextAreaWithOneWildcard* NodeCANID[NODE_NR];
    touchgfx::Unicode::UnicodeChar* NodeCANIDBuffer[NODE_NR];
    touchgfx::Circle* NodeStatus[NODE_NR];
    touchgfx::PainterRGB565* NodeStatusPainter[NODE_NR];
};

#endif // SCREEN3VIEW_HPP
