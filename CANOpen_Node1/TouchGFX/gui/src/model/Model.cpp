#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


extern "C" {
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_rtc.h"
extern RTC_HandleTypeDef hrtc;
extern CO_t *CO;
}


uint32_t LED_CONTROL = 0;


#define POZ_LUMINI_POZITII 			0
#define POZ_SEMNALIZARE_STINGA 		1
#define POZ_SEMNALIZARE_DREAPTA 	2
#define POZ_FAZA_LUNGA 				3
#define POZ_FAZA_LUNGA_FLASH 		4


#define MASK_LUMINI_POZITII 		0x00000001
#define MASK_SEMNALIZARE_STINGA 	0x00000002
#define MASK_SEMNALIZARE_DREAPTA 	0x00000004
#define MASK_FAZA_LUNGA 			0x00000008
#define MASK_FAZA_LUNGA_FLASH 		0x00000010

#define GET_LUMINI_POZITII(val) 	    (val & 0x00000001)
#define GET_SEMNALIZARE_STINGA(val) 	((val & 0x00000002) >> 1 )
#define GET_SEMNALIZARE_DREAPTA(val) 	((val & 0x00000004) >> 2 )
#define GET_FAZA_LUNGA(val) 	        ((val & 0x00000008) >> 3 )
#define GET_FAZA_LUNGA_FLASH(val) 	    ((val & 0x00000010) >> 4 )

#define TOGGLE_LUMINI_POZITII(val) 	    val ^= 0x00000001;
#define TOGGLE_SEMNALIZARE_STINGA(val) 	    val ^= 0x00000002;
#define TOGGLE_SEMNALIZARE_DREAPTA(val) 	    val ^= 0x00000004;
#define TOGGLE_FAZA_LUNGA(val) 	    val ^= 0x00000008;
#define TOGGLE_FAZA_LUNGA_FLASH(val) 	    val ^= 0x00000010;




Model::Model() : modelListener(nullptr)
{
}

void Model::tick()
{
	static uint32_t counter = 0;
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    modelListener->updateTime(
        sTime.Hours,
        sTime.Minutes,
        sTime.Seconds
    );
    modelListener->updateData(
        sDate.WeekDay,
        sDate.Date,
        sDate.Month,
        sDate.Year
    );

   for(int i = 0 ; i < HB_CONS_NODES ; i++)
   {
	   modelListener->setNodeInfo( i, CO->HBconsMonitoredNodes[i].nodeId, CO->HBconsMonitoredNodes[i].HBstate , CO->HBconsMonitoredNodes[i].NMTstate);
	   modelListener->setHBconsumerTimeout(i, 1500);
   }

   modelListener->setHBconsumerTimeout(7, 1500);

   if(counter%100 == 0)
	   modelListener->setLight( GET_LUMINI_POZITII( LED_CONTROL ),
		   (GET_SEMNALIZARE_STINGA(LED_CONTROL) & ((counter % 200) / 100)),
		   (GET_SEMNALIZARE_DREAPTA(LED_CONTROL) & ((counter % 200) / 100)),
		   GET_FAZA_LUNGA_FLASH(LED_CONTROL) ? (GET_FAZA_LUNGA_FLASH(LED_CONTROL) & ((counter % 500) / 250))
		   	   	   	   	   	   	   : GET_FAZA_LUNGA(LED_CONTROL)    );

   counter++;
}
