/**
 * @file lib_config.h
 * @author melektron (matteo@elektron.work)
 * @brief provides default library configuration values for intellisense.
 * These are overwritten by platformio.ini values.
 * @version 0.1
 * @date 2023-08-01
 * 
 * @copyright Copyright HinsTech GmbH (c) 2023-now
 * 
 */

#ifndef __LCD_LIB_CONFIG_H
#define __LCD_LIB_CONFIG_H

#define CONF_STR(x) #x
#define CONF_VAL(x) CONF_STR(x)


// config in stm32_adafruit_lcd.h

#ifndef PROJCONF_LCD_DEFAULT_FONT
#define PROJCONF_LCD_DEFAULT_FONT Font12
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DEFAULT_FONT=" CONF_VAL(PROJCONF_LCD_DEFAULT_FONT)
#endif

#ifndef PROJCONF_LCD_DEFAULT_BG_COLOR
#define PROJCONF_LCD_DEFAULT_BG_COLOR LCD_COLOR_BLACK
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DEFAULT_BG_COLOR=" CONF_VAL(PROJCONF_LCD_DEFAULT_BG_COLOR)
#endif

#ifndef PROJCONF_LCD_DEFAULT_FG_COLOR
#define PROJCONF_LCD_DEFAULT_FG_COLOR LCD_COLOR_WHITE
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DEFAULT_FG_COLOR=" CONF_VAL(PROJCONF_LCD_DEFAULT_FG_COLOR)
#endif

#ifndef PROJCONF_LCD_CLEAR_ON_INIT
#define PROJCONF_LCD_CLEAR_ON_INIT 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_CLEAR_ON_INIT=" CONF_VAL(PROJCONF_LCD_CLEAR_ON_INIT)
#endif



// config in lcd_io_fsmc8_hal.h

#ifndef PROJCONF_LCD_BASE_ADDRESS
#define PROJCONF_LCD_BASE_ADDRESS 0x60000000
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_BASE_ADDRESS=" CONF_VAL(PROJCONF_LCD_BASE_ADDRESS)
#endif

#ifndef PROJCONF_LCD_RS_ADDRESS_BIT
#define PROJCONF_LCD_RS_ADDRESS_BIT 18
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_RS_ADDRESS_BIT=" CONF_VAL(PROJCONF_LCD_RS_ADDRESS_BIT)
#endif

#ifndef PROJCONF_LCD_DATA_BIDIRECTIONAL
#define PROJCONF_LCD_DATA_BIDIRECTIONAL 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DATA_BIDIRECTIONAL=" CONF_VAL(PROJCONF_LCD_DATA_BIDIRECTIONAL)
#endif

#ifndef PROJCONF_LCD_USE_DMA_FOR_TX
#define PROJCONF_LCD_USE_DMA_FOR_TX 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_USE_DMA_FOR_TX=" CONF_VAL(PROJCONF_LCD_USE_DMA_FOR_TX)
#endif

#ifndef PROJCONF_LCD_USE_DMA_FOR_RX
#define PROJCONF_LCD_USE_DMA_FOR_RX 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_USE_DMA_FOR_RX=" CONF_VAL(PROJCONF_LCD_USE_DMA_FOR_RX)
#endif

#ifndef PROJCONF_LCD_DMA_HANDLE
#define PROJCONF_LCD_DMA_HANDLE hdma_memtomem_dma2_stream0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DMA_HANDLE=" CONF_VAL(PROJCONF_LCD_DMA_HANDLE)
#endif

#ifndef PROJCONF_LCD_DMA_WAIT_MODE
#define PROJCONF_LCD_DMA_WAIT_MODE 1
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DMA_WAIT_MODE=" CONF_VAL(PROJCONF_LCD_DMA_WAIT_MODE)
#endif

#ifndef PROJCONF_LCD_DMA_INCAPABLE_SECTION
#define PROJCONF_LCD_DMA_INCAPABLE_SECTION 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_DMA_INCAPABLE_SECTION=" CONF_VAL(PROJCONF_LCD_DMA_INCAPABLE_SECTION)
#endif

#ifndef PROJCONF_LCD_RGB24_REVERSE_ORDER
#define PROJCONF_LCD_RGB24_REVERSE_ORDER 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_RGB24_REVERSE_ORDER=" CONF_VAL(PROJCONF_LCD_RGB24_REVERSE_ORDER)
#endif

#ifndef PROJCONF_LCD_RGB24_CONVERSION_BUFFER_SIZE
#define PROJCONF_LCD_RGB24_CONVERSION_BUFFER_SIZE 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_RGB24_CONVERSION_BUFFER_SIZE=" CONF_VAL(PROJCONF_LCD_RGB24_CONVERSION_BUFFER_SIZE)
#endif

#define _PROJCONF_DEBUG 1

// config in ili9488.h

#ifndef PROJCONF_LCD_ILI9488_INTERFACE
#define PROJCONF_LCD_ILI9488_INTERFACE 2
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_ILI9488_INTERFACE=" CONF_VAL(PROJCONF_LCD_ILI9488_INTERFACE)
#endif

#ifndef PROJCONF_LCD_ILI9488_ORIENTATION
#define PROJCONF_LCD_ILI9488_ORIENTATION 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_ILI9488_ORIENTATION=" CONF_VAL(PROJCONF_LCD_ILI9488_ORIENTATION)
#endif

#ifndef PROJCONF_LCD_ILI9488_COLORMODE
#define PROJCONF_LCD_ILI9488_COLORMODE 1
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_ILI9488_COLORMODE=" CONF_VAL(PROJCONF_LCD_ILI9488_COLORMODE)
#endif

#ifndef PROJCONF_LCD_COLOR_INVERTED
#define PROJCONF_LCD_COLOR_INVERTED 0
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_COLOR_INVERTED=" CONF_VAL(PROJCONF_LCD_COLOR_INVERTED)
#endif

#ifndef PROJCONF_LCD_ILI9488_BITDEPTH
#define PROJCONF_LCD_ILI9488_BITDEPTH 24
#endif
#ifdef _PROJCONF_DEBUG
#pragma message "PROJCONF_LCD_ILI9488_BITDEPTH=" CONF_VAL(PROJCONF_LCD_ILI9488_BITDEPTH)
#endif


#endif  // __LCD_LIB_CONFIG_H