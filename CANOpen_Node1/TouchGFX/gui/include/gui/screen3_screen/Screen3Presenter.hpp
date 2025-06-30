#ifndef SCREEN3PRESENTER_HPP
#define SCREEN3PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen3View;

class Screen3Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen3Presenter(Screen3View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen3Presenter() {}

    virtual void setNodeInfo(int index, uint8_t CAN_ID, CO_HBconsumer_state_t HBstate, CO_NMT_internalState_t NMTstate);
    virtual void setHBconsumerTimeout( int index, uint16_t timeoutTime);
private:
    Screen3Presenter();

    Screen3View& view;
};

#endif // SCREEN3PRESENTER_HPP
