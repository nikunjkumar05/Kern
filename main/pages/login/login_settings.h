// Login Settings Page - Pre-login configuration (default wallet preferences)

#ifndef LOGIN_SETTINGS_H
#define LOGIN_SETTINGS_H

#include <lvgl.h>

void login_settings_page_create(lv_obj_t *parent, void (*return_cb)(void));
void login_settings_page_show(void);
void login_settings_page_hide(void);
void login_settings_page_destroy(void);

#endif // LOGIN_SETTINGS_H
