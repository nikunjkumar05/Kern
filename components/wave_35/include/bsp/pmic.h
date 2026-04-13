#pragma once

#include "esp_err.h"
#include <stdbool.h>
#include <stdint.h>

typedef enum {
  BSP_PMIC_CHG_ABSENT,
  BSP_PMIC_CHG_DISCHARGING,
  BSP_PMIC_CHG_CHARGING,
  BSP_PMIC_CHG_FULL,
} bsp_pmic_chg_t;

/**
 * Initialize AXP2101 PMIC over I2C.
 * Probes chip ID and enables battery ADC + fuel gauge.
 * Returns ESP_ERR_NOT_FOUND if the chip is not detected.
 * Must be called after bsp_i2c_init().
 */
esp_err_t bsp_pmic_init(void);

/** Cut all power rails via SOFT_PWROFF. Device turns off. */
esp_err_t bsp_pmic_power_off(void);

/** Read battery state-of-charge from the on-chip gauge (0–100). */
esp_err_t bsp_pmic_get_battery_percent(uint8_t *pct);

/** Read battery voltage in millivolts. */
esp_err_t bsp_pmic_get_battery_mv(uint16_t *mv);

/** Read charging status. */
esp_err_t bsp_pmic_get_charge_status(bsp_pmic_chg_t *status);

/** Check if external power (USB VBUS) is connected. */
bool bsp_pmic_is_vbus_present(void);

/** Returns true if bsp_pmic_init() succeeded (chip was found). */
bool bsp_pmic_is_available(void);
