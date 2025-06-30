#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>


class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void updateCANID(uint8_t CAN_ID);

    virtual void setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate);
    virtual void setHBconsumerTimeout( int index, uint16_t timeoutTime);
    virtual void updateHBprodTime(int index, uint16_t HBprodTime);

protected:

    touchgfx::TextAreaWithOneWildcard* NodeNMTState[HB_CONS_NODES];
    touchgfx::Unicode::UnicodeChar* NodeNMTStateBuffer[HB_CONS_NODES];
    touchgfx::TextAreaWithOneWildcard* NodeCANID[HB_CONS_NODES];
    touchgfx::Unicode::UnicodeChar* NodeCANIDBuffer[HB_CONS_NODES];
    touchgfx::Circle* NodeStatus[HB_CONS_NODES];
    touchgfx::PainterRGB565* NodeStatusPainter[HB_CONS_NODES];
};

#endif // SCREEN3VIEW_HPP
