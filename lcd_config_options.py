try:
    import configparser
except ImportError:
    import ConfigParser as configparser

Import('env')

boolvals = {"yes": "1", "no": "0"}
membanks = [
    "0x60000000",
    "0x64000000",
    "0x68000000",
    "0x6C000000",
]
dma_wait_modes = ["0", "1", "2"]
if_options = ["0", "1", "2"]
rot_options = ["0", "1", "2", "3"]
colormode = {"rgb": "0", "bgr": "1"}
bitdeph = ["16", "24"]

# options from stm32_adafruit_lcd.h
lcd_default_font = env.GetProjectOption("custom_lcd_default_font", "Font12")

lcd_default_bg_color = env.GetProjectOption("custom_lcd_default_bg_color", "LCD_COLOR_BLACK")
lcd_default_fg_color = env.GetProjectOption("custom_lcd_default_fg_color", "LCD_COLOR_WHITE")

lcd_clear_on_init = env.GetProjectOption("custom_lcd_clear_on_init", "no")
assert lcd_clear_on_init in boolvals, f"custom_lcd_clear_on_init must be one of {boolvals}"

# options from lcd_io_fsmc_hal.h
lcd_base_address = env.GetProjectOption("custom_lcd_base_address", "0x60000000")
assert lcd_base_address in membanks, f"custom_lcd_base_address must be one of {membanks}"

lcd_rs_address_bit = env.GetProjectOption("custom_lcd_rs_address_bit", "18")
assert int(lcd_rs_address_bit) >= 1 and int(lcd_rs_address_bit) <= 25 , f"custom_lcd_rs_address_bit must a value from 1 to 25"

lcd_data_bidirectional = env.GetProjectOption("custom_lcd_data_bidirectional", "no")
assert lcd_data_bidirectional in boolvals, f"custom_lcd_data_bidirectional must be one of {boolvals}"

lcd_use_dma_for_tx = env.GetProjectOption("custom_lcd_use_dma_for_tx", "no")
assert lcd_use_dma_for_tx in boolvals, f"custom_lcd_use_dma_for_tx must be one of {boolvals}"
lcd_use_dma_for_rx = env.GetProjectOption("custom_lcd_use_dma_for_rx", "no")
assert lcd_use_dma_for_rx in boolvals, f"custom_lcd_use_dma_for_rx must be one of {boolvals}"

lcd_dma_handle = env.GetProjectOption("custom_lcd_dma_handle", "hdma_memtomem_dma2_stream0")

lcd_dma_wait_mode = env.GetProjectOption("custom_lcd_dma_wait_mode", "1")
assert lcd_dma_wait_mode in dma_wait_modes, f"custom_lcd_dma_wait_mode must be one of {dma_wait_modes}"

lcd_dma_incapable_section = env.GetProjectOption("custom_lcd_dma_incapable_section", "0")

lcd_rgb24_revers_order = env.GetProjectOption("custom_lcd_rgb24_revers_order", "no")
assert lcd_rgb24_revers_order in boolvals, f"custom_lcd_rgb24_revers_order must be one of {boolvals}"

lcd_rgb24_conversion_buffer_size = env.GetProjectOption("custom_lcd_rgb24_conversion_buffer_size", "0")

# options in ili9488.h
lcd_ili9488_interface = env.GetProjectOption("custom_lcd_ili9488_interface", "1")
assert lcd_ili9488_interface in if_options, f"custom_lcd_ili9488_interface must be one of {if_options}"

lcd_ili9488_orientation = env.GetProjectOption("custom_lcd_ili9488_orientation", "1")
assert lcd_ili9488_orientation in rot_options, f"custom_lcd_ili9488_orientation must be one of {rot_options}"

# don't support this initclear

lcd_ili9488_colormode = env.GetProjectOption("custom_lcd_ili9488_colormode", "bgr")
assert lcd_ili9488_colormode in colormode, f"custom_lcd_ili9488_colormode must be one of {colormode}"

lcd_ili9488_bitdepth = env.GetProjectOption("custom_lcd_ili9488_bitdepth", "24")
assert lcd_ili9488_bitdepth in bitdeph, f"custom_lcd_ili9488_bitdepth must be one of {bitdeph}"


print("Using the following LCD configuration:")

print(f"{lcd_default_font=}")
print(f"{lcd_default_bg_color=}")
print(f"{lcd_default_fg_color=}")
print(f"{lcd_clear_on_init=}")

print(f"{lcd_base_address=}")
print(f"{lcd_rs_address_bit=}")
print(f"{lcd_data_bidirectional=}")
print(f"{lcd_use_dma_for_tx=}")
print(f"{lcd_use_dma_for_rx=}")
print(f"{lcd_dma_handle=}")
print(f"{lcd_dma_wait_mode=}")
print(f"{lcd_dma_incapable_section=}")
print(f"{lcd_rgb24_revers_order=}")
print(f"{lcd_rgb24_conversion_buffer_size=}")

print(f"{lcd_ili9488_interface=}")
print(f"{lcd_ili9488_orientation=}")
print(f"{lcd_ili9488_colormode=}")
print(f"{lcd_ili9488_bitdepth=}")

env.Append(CCFLAGS=[
    f"-DPROJCONF_LCD_DEFAULT_FONT={lcd_default_font}",
    f"-DPROJCONF_LCD_DEFAULT_BG_COLOR={lcd_default_bg_color}",
    f"-DPROJCONF_LCD_DEFAULT_FG_COLOR={lcd_default_fg_color}",
    f"-DPROJCONF_LCD_CLEAR_ON_INIT={boolvals[lcd_clear_on_init]}",

    f"-DPROJCONF_LCD_BASE_ADDRESS={lcd_base_address}",
    f"-DPROJCONF_LCD_RS_ADDRESS_BIT={lcd_rs_address_bit}",
    f"-DPROJCONF_LCD_DATA_BIDIRECTIONAL={boolvals[lcd_data_bidirectional]}",
    f"-DPROJCONF_LCD_USE_DMA_FOR_TX={boolvals[lcd_use_dma_for_tx]}",
    f"-DPROJCONF_LCD_USE_DMA_FOR_RX={boolvals[lcd_use_dma_for_rx]}",
    f"-DPROJCONF_LCD_DMA_HANDLE={lcd_dma_handle}",
    f"-DPROJCONF_LCD_DMA_WAIT_MODE={lcd_dma_wait_mode}",
    f"-DPROJCONF_LCD_DMA_INCAPABLE_SECTION={lcd_dma_incapable_section}",
    f"-DPROJCONF_LCD_RGB24_REVERS_ORDER={boolvals[lcd_rgb24_revers_order]}",
    f"-DPROJCONF_LCD_RGB24_CONVERSION_BUFFER_SIZE={lcd_rgb24_conversion_buffer_size}",

    f"-DPROJCONF_LCD_ILI9488_INTERFACE={lcd_ili9488_interface}",
    f"-DPROJCONF_LCD_ILI9488_ORIENTATION={lcd_ili9488_orientation}",
    f"-DPROJCONF_LCD_ILI9488_COLORMODE={colormode[lcd_ili9488_colormode]}",
    f"-DPROJCONF_LCD_ILI9488_BITDEPTH={lcd_ili9488_bitdepth}"
])