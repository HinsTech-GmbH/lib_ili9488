# lib_ili9488

ILI9488 graphics driver for STM32 based on ST's BSP drivers and RobertoBenjami's IO drivers.

This library is based on the [RobertoBenjami/stm32_hal_graphics_display_drivers](https://github.com/RobertoBenjami/stm32_hal_graphics_display_drivers) library. It restructures the files to support simple integration as a library dependency in the PlatformIO IDE without needing to copy files into the project source tree.

## Configuration

This library can be configured directly from ```platformio.ini```. The following options are available:

```ini
; Default selected font. 
; One of (Font8, Font12, Font16, Font20, Font24).
; Default: Font12
custom_lcd_default_font = Font12

; Default selected foreground/background color.
; Can be any of the color macros available in the library or LCD_COLOR(r, g, b) for
; special RGB color. Each value goes from 0 to 255.
; Defaults: shown below
custom_lcd_default_bg_color = LCD_COLOR_BLACK
custom_lcd_default_fg_color = LCD_COLOR_WHITE

; Whether to clear the display with the default bg color on init (yes/no)
; Default: no
custom_lcd_clear_on_init = no

```

# Credits and licensing

All the credits for this code go to RobertoBenjami and STMicroelectronics.

This library doesn't use a license, same as RobertoBenjami's, since certain files are parts of the STMicroelectronics BSP which forbids distributing under open source licenses.

**! Disclaimer: HinsTech GmbH is not affiliated with STMicroelectornics or RobertoBenjami !**
