/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image_bg.setXY(0, 0);
    image_bg.setBitmap(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_BACKGROUNDS_240X320_PUZZLE_ID));
    add(image_bg);

    label_Aplication.setPosition(16, 13, 206, 27);
    label_Aplication.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    label_Aplication.setLinespacing(0);
    label_Aplication.setWideTextAction(WIDE_TEXT_WORDWRAP);
    label_Aplication.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GXKT));
    add(label_Aplication);

    buttoNext.setXY(204, 284);
    buttoNext.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID));
    buttoNext.setLabelText(touchgfx::TypedText(T___SINGLEUSE_0KU0));
    buttoNext.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttoNext.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttoNext.setAction(buttonCallback);
    add(buttoNext);

    textETTI.setPosition(12, 266, 178, 53);
    textETTI.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textETTI.setLinespacing(0);
    textETTI.setWideTextAction(WIDE_TEXT_WORDWRAP);
    textETTI.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PMK7));
    add(textETTI);

    textAutor1.setXY(10, 100);
    textAutor1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAutor1.setLinespacing(0);
    textAutor1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JS9Q));
    add(textAutor1);

    textAutor2.setXY(10, 204);
    textAutor2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAutor2.setLinespacing(0);
    textAutor2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QTJB));
    add(textAutor2);

    textIndrumator.setXY(10, 142);
    textIndrumator.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textIndrumator.setLinespacing(0);
    textIndrumator.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O324));
    add(textIndrumator);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttoNext)
    {
        //Scrren1Next
        //When buttoNext clicked change screen to Screen2
        //Go to Screen2 with screen transition towards East
        application().gotoScreen2ScreenWipeTransitionEast();
    }
}
