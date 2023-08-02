# lib_ili9488

ILI9488 graphics driver for STM32 based on ST's BSP drivers and RobertoBenjami's IO drivers.

This library is based on the [RobertoBenjami/stm32_hal_graphics_display_drivers](https://github.com/RobertoBenjami/stm32_hal_graphics_display_drivers) library. It restructures the files to support simple integration as a library dependency in the PlatformIO IDE without needing to copy files into the project source tree.

## Configuration

This library can be configured directly from ```platformio.ini```. The following options are available:

```ini
; == options from stm32_adafruit_lcd.h

; Default selected font. 
; One of (Font8, Font12, Font16, Font20, Font24).
; If more fonts are added, you can also use those.
; Default: Font12
custom_lcd_default_font = Font12

; Default selected foreground/background color.
; Can be any of the color macros available in the library or LCD_COLOR(r, g, b) for
; special RGB color. Each value goes from 0 to 255.
; Defaults: shown below
custom_lcd_default_bg_color = LCD_COLOR_BLACK
custom_lcd_default_fg_color = LCD_COLOR_WHITE


; == options from lcd_io_fsmc_hal.h

; Base address of the LCD's bank in the MCU memory map, depends on selected NEx line:
;  - Bank1 (NE1) 0x60000000
;  - Bank2 (NE2) 0x64000000
;  - Bank3 (NE3) 0x68000000
;  - Bank4 (NE4) 0x6C000000
; Default: 0x60000000
custom_lcd_base_address = 0x60000000

; The Ax line (address bit) used for the LCD RS (aka. DC) line.
; This can be 1 - 25, 0 is not allowed because of multi-byte addressing problems.
; Default: 18
custom_lcd_rs_address_bit = 18

; Whether to enable reading from display, aka whether to use 
; bidirectional communication. No means only writing. (yes/no)
; Default: no
custom_lcd_data_bidirectional = no

; whether to use DMA for writing to / reading from the display. (yes/no)
; Default: no
custom_lcd_use_dma_for_tx = no
custom_lcd_use_dma_for_rx = no

; The name of the HAL DMA handle to to use for DMA communication.
; When enabling a mem-to-mem DMA in CubeMX, it will automatically generate
; a handle defined in "dma.h". simply insert it's name here. When not using DMA,
; this value doesn't matter. The default will probably be right if you only create one DMA stream
; in CubeMX.
; Default: hdma_memtomem_dma2_stream0
custom_lcd_dma_handle = hdma_memtomem_dma2_stream0

; When using DMA, when should the functions wait for transfers to finis:
;  - start: DMA check and wait at start of drawing function
;  - start+bmpend: DMA check and wait at start of drawing function and on end of BITMAP drawing function
;  - end: DMA wait at end of drawing function
; Default: start+bmpend
custom_lcd_dma_wait_mode = start+bmpend

; Definition of DMA incabable memory sections in your microcontroller. See 
; comments in LCD_DMA_UNABLE definition in lcd_io_fsmc8_hal.h. If you don't know how to use
; or what to put there leave it as the default.
; Default: 0
custom_lcd_dma_incapable_section = 0

; Whether to reverse the order of RGB24 color transfers (switches red and blue). (yes/no)
; Default: no
custom_lcd_rgb24_reverse_order = no

; Size of the buffer used to convert from 16-bit to 24-bit color. This defines how much
; of a large bitmap can be sent over DMA in 24-bit mode at once. If zero, DMA
; is not used for occasions where 16-bit has to be converted to 24-bit color.
; Default: 0
custom_lcd_rgb24_conversion_buffer_size = 0


; == options in ili9488.h

; Interface option used. (spi3w/spi4w/parallel8bit) 
; This option is not supported and fixed to parallel8bit at the moment.
; custom_lcd_ili9488_interface = parallel8bit

; LCD orientation in amount of 90° turns (0-3)
; Default: 0
custom_lcd_ili9488_orientation = 0

; Whether to clear the display black during init before turning
; it on (showing it on the panel) (yes/no)
; Default: no
custom_lcd_clear_on_init = no

; Whether the lcd uses bgr or rgb color order. (rgb/bgr)
; Default: bgr
custom_lcd_ili9488_colormode = bgr

; Whether to turn color inversion on/off. This simply changes LCD config,
; has no performance impact. Some LCDs have inverted color otherwise (yes/no)
; Default: no
custom_lcd_color_inverted = no

; Color bit-depth to use for transferring to LCD. This can be 24-bit which works
; for any interface (spi or parallel) but 16-bit is more sensible in parallel mode. 
; Since we are only supporting parallel for now, 16-bit is advised
; Default: 24
custom_lcd_ili9488_bitdepth = 24

```

# Credits and licensing

All the credits for this code go to RobertoBenjami and STMicroelectronics.

This library doesn't use a license, same as RobertoBenjami's, since certain files are parts of the STMicroelectronics BSP which forbids distributing under open source licenses.

**! Disclaimer: HinsTech GmbH is not affiliated with STMicroelectornics or RobertoBenjami !**
