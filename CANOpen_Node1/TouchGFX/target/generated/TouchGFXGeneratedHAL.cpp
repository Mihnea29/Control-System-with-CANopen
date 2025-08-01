/**
  ******************************************************************************
  * File Name          : TouchGFXGeneratedHAL.cpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.25.0. Please, do not edit!
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include <TouchGFXGeneratedHAL.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <gui/common/FrontendHeap.hpp>

#include <touchgfx/widgets/canvas/CWRVectorRenderer.hpp>

#include <DirectFrameBufferVideoController.hpp>

#include <SoftwareMJPEGDecoder.hpp>
uint32_t lineBuffer[800];

SoftwareMJPEGDecoder mjpegdecoder1((uint8_t*)lineBuffer);

namespace
{
DirectFrameBufferVideoController<1, Bitmap::RGB565> videoController;
}

//Singleton Factory
VideoController& VideoController::getInstance()
{
    return videoController;
}

namespace touchgfx
{
VectorRenderer* VectorRenderer::getInstance()
{
    static CWRVectorRendererRGB565 renderer;

    return &renderer;
}
} // namespace touchgfx

#include "stm32f7xx.h"
#include "stm32f7xx_hal_ltdc.h"

using namespace touchgfx;

namespace
{
// Use the section "TouchGFX_Framebuffer" in the linker script to specify the placement of the buffer
LOCATION_PRAGMA_NOLOAD("TouchGFX_Framebuffer")
uint32_t frameBuf[(480 * 800 * 2 + 3) / 4 * 2] LOCATION_ATTRIBUTE_NOLOAD("TouchGFX_Framebuffer");
static uint16_t lcd_int_active_line;
static uint16_t lcd_int_porch_line;
}

void TouchGFXGeneratedHAL::initialize()
{
    HAL::initialize();
    registerEventListener(*(Application::getInstance()));
    setFrameBufferStartAddresses((void*)frameBuf, (void*)(frameBuf + sizeof(frameBuf) / (sizeof(uint32_t) * 2)), (void*)0);

    /*
     * Add software decoder to video controller
     */
    videoController.addDecoder(mjpegdecoder1, 0);

}

void TouchGFXGeneratedHAL::configureInterrupts()
{
    NVIC_SetPriority(DMA2D_IRQn, 9);
    NVIC_SetPriority(LTDC_IRQn, 9);
}

void TouchGFXGeneratedHAL::enableInterrupts()
{
    NVIC_EnableIRQ(DMA2D_IRQn);
    NVIC_EnableIRQ(LTDC_IRQn);
}

void TouchGFXGeneratedHAL::disableInterrupts()
{
    NVIC_DisableIRQ(DMA2D_IRQn);
    NVIC_DisableIRQ(LTDC_IRQn);
}

void TouchGFXGeneratedHAL::enableLCDControllerInterrupt()
{
    lcd_int_active_line = (LTDC->BPCR & LTDC_BPCR_AVBP_Msk) - 1;
    lcd_int_porch_line = (LTDC->AWCR & LTDC_AWCR_AAH_Msk) - 1;

    /* Sets the Line Interrupt position */
    LTDC->LIPCR = lcd_int_active_line;
    /* Line Interrupt Enable            */
    LTDC->IER |= LTDC_IER_LIE;
}

bool TouchGFXGeneratedHAL::beginFrame()
{
    return HAL::beginFrame();
}

void TouchGFXGeneratedHAL::endFrame()
{
    HAL::endFrame();
}

uint16_t* TouchGFXGeneratedHAL::getTFTFrameBuffer() const
{
    return (uint16_t*)LTDC_Layer1->CFBAR;
}

void TouchGFXGeneratedHAL::setTFTFrameBuffer(uint16_t* adr)
{
    LTDC_Layer1->CFBAR = (uint32_t)adr;

    /* Reload immediate */
    LTDC->SRCR = (uint32_t)LTDC_SRCR_IMR;
}

void TouchGFXGeneratedHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    HAL::flushFrameBuffer(rect);
}

bool TouchGFXGeneratedHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
    return HAL::blockCopy(dest, src, numBytes);
}

void TouchGFXGeneratedHAL::InvalidateCache()
{
    // Because DMA2D access main memory directly, the DCache must be invalidated
    // becuase it could hold a wrong image of the framebuffer. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable
    // "CPU Cache" in the "System Core" settings for "Cortex M7" in CubeMX
    // in order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

void TouchGFXGeneratedHAL::FlushCache()
{
    // If the framebuffer is placed in Write-Back cached memory (e.g. SRAM) then
    // the DCache must be flushed prior to DMA2D accessing it. That's done
    // using the function SCB_CleanInvalidateDCache(). Remember to enable
    // "CPU Cache" in the "System Core" settings for "Cortex M7" in CubeMX in
    // order for this function call to work.
    if (SCB->CCR & SCB_CCR_DC_Msk)
    {
        SCB_CleanInvalidateDCache();
    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
