#include <gui/screen4_screen/Screen4View.hpp>

#include <touchgfx/Color.hpp>

Screen4View::Screen4View()
{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}

//                     OFF        ON
uint32_t colorTable[][2] = { {0x00404040, 0x00B0B0B0 },				// LUMINI_POZITII
						{0x00404040, 0x00B0B0B0 },				// SEMNALIZARE
						{0x00404040, 0x00FFFFFF }				// FAZA_LUNGA
};




void Screen4View::setLight(bool LUMINI_POZITII, bool SEMNALIZARE_STINGA, bool SEMNALIZARE_DREAPTA, bool FAZA_LUNGA )
{
	uint32_t color;
	uint8_t r, g, b;

	color = colorTable[0][LUMINI_POZITII]; r = color & 0x000000FF; g = (color & 0x0000FF00) >> 8; b = (color & 0x00FF0000) >> 16;
    lumini_poz_drPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); 	lumini_poz_dr.invalidate();
    lumini_poz_stPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); 	lumini_poz_st.invalidate();
    poz_drPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); 			poz_dr.invalidate();
    poz_stPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); 			poz_st.invalidate();


	color = colorTable[1][SEMNALIZARE_DREAPTA]; r = color & 0x000000FF; g = (color & 0x0000FF00) >> 8; b = (color & 0x00FF0000) >> 16;
	semnalizare_fata_drPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); semnalizare_fata_dr.invalidate();
	semnalizare_spate_drPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); semnalizare_spate_dr.invalidate();

	color = colorTable[1][SEMNALIZARE_STINGA]; r = color & 0x000000FF; g = (color & 0x0000FF00) >> 8; b = (color & 0x00FF0000) >> 16;
	semnalizare_fata_stPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); semnalizare_fata_st.invalidate();
	semnalizare_spate_stPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b)); semnalizare_spate_st.invalidate();

	color = colorTable[2][FAZA_LUNGA]; r = color & 0x000000FF; g = (color & 0x0000FF00) >> 8; b = (color & 0x00FF0000) >> 16;
	faza_lunga_drPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));    faza_lunga_dr.invalidate();
	faza_lunga_stPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));    faza_lunga_st.invalidate();

}
