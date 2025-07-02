#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeScreen(int ecran);

    void updateTime(uint8_t hour, uint8_t minute, uint8_t second);
    void updateData(uint8_t WeekDay, uint8_t Date, uint8_t Month, uint8_t Year);
protected:
};

#endif // SCREEN2VIEW_HPP
