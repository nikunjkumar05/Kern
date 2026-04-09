if(CONFIG_KERN_BOARD_WAVE_35)
    idf_component_register(
        SRCS "wave_35.c"
        INCLUDE_DIRS "include"
        PRIV_INCLUDE_DIRS "priv_include"
        REQUIRES driver esp_lcd esp_driver_ledc
        PRIV_REQUIRES esp_lcd_touch_ft5x06
    )
else()
    idf_component_register(
        REQUIRES driver esp_lcd esp_driver_ledc
    )
endif()
