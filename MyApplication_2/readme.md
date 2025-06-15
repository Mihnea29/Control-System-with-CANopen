# STM32F769I_DISCO TBS

The default IDE is set to STM32CubeIDE, to change IDE open the STM32F769I_DISCO.ioc with STM32CubeMX and select from the supported IDEs (EWARM, MDK-ARM, and STM32CubeIDE). Supports flashing of the STM32F769I_DISCO board directly from TouchGFX Designer using GCC and STM32CubeProgrammer.Flashing the board requires STM32CubeProgrammer which can be downloaded from the ST webpage.

This TBS is configured for 480 x 800 pixels 16bpp screen resolution.

Video Decoding Orientation is configured to "Rotated" in STM32CubeMX X-CUBE-TOUCHGFX. This means that video will work when the display is rotated to be landscape mode in TouchGFX Designer. If you want to use video with the display in the native portrait orientation, the Video Decoding Orientation in STM32CubeMX X-CUBE-TOUCHGFX must be changed to "Native".

Performance testing can be done using the GPIO pins designated with the following signals:
- VSYNC_FREQ  - Pin PC6(D1)
- RENDER_TIME - Pin PC7(D0)
- FRAME_RATE  - Pin PJ1(D2)
- MCU_ACTIVE  - Pin PF6(D3)
