/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoScreen1ScreenNoTransition();
    }

    // Screen1
    void gotoScreen1ScreenNoTransition();

    void gotoScreen1ScreenWipeTransitionWest();

    // Screen2
    void gotoScreen2ScreenWipeTransitionEast();

    void gotoScreen2ScreenWipeTransitionWest();

    // Screen3
    void gotoScreen3ScreenWipeTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();

    void gotoScreen1ScreenWipeTransitionWestImpl();

    // Screen2
    void gotoScreen2ScreenWipeTransitionEastImpl();

    void gotoScreen2ScreenWipeTransitionWestImpl();

    // Screen3
    void gotoScreen3ScreenWipeTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
