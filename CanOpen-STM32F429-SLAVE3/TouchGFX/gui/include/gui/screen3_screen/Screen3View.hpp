#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeScreen(int ecran);

    virtual void updateHeartbeatTime(uint8_t CAN_ID, uint32_t HeartbeatTime);
protected:

};

#endif // SCREEN3VIEW_HPP
