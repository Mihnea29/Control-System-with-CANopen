#include <gui/screen4_screen/Screen4View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>

Screen4Presenter::Screen4Presenter(Screen4View& v)
    : view(v)
{

}

void Screen4Presenter::activate()
{

}

void Screen4Presenter::deactivate()
{

}


void Screen4Presenter::setLight(bool LUMINI_POZITII, bool SEMNALIZARE_STINGA, bool SEMNALIZARE_DREAPTA, bool FAZA_LUNGA)
{
	view.setLight(LUMINI_POZITII, SEMNALIZARE_STINGA, SEMNALIZARE_DREAPTA, FAZA_LUNGA );
}
