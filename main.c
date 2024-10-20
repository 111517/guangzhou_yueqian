#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui/ui.h"
#include "ui/ui_events.h"
#include "app/app.h"
#include<pthread.h>
#include "cJSON.h"

#define LV_LOGING 1

static const char * getenv_default(const char * name, const char * dflt)
{
    return getenv(name) ?: dflt;
}

static void lv_linux_disp_init(void)
{
    const char * device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t * disp = lv_linux_fbdev_create();

    lv_linux_fbdev_set_file(disp, device);
}

void* pthread_platform(void* arg)
{
    time_sleep(10000);
    main_deom();
    pthread_exit(NULL);
}

void* pthread_zigbee(void* arg)
{
    time_sleep(10000);
    while (1)
    {
        zigbee_data();
        time_sleep(5000);
    }
    
    pthread_exit(NULL);
}

int main(void)
{
    lv_init();
    /*Linux display device init*/
    lv_linux_disp_init();

    /*Linux touch device init*/
    lv_indev_t * ts = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event0");
    // 设置屏幕大小
    lv_evdev_set_calibration(ts, 0, 0, 1024, 600);

    lvgl_example_login();

    pthread_t tid_platform;
    int res_platform = pthread_create(&tid_platform,NULL,pthread_platform,NULL);

    pthread_t tid_zigbee;
    int res_zigbee = pthread_create(&tid_zigbee,NULL,pthread_zigbee,NULL);
    
    uart_init();
    /*Handle LVGL tasks*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    char* s = NULL;
    pthread_join(tid_platform,(void**)&s);
    char* s_zigbee = NULL;
    pthread_join(tid_zigbee,(void**)&s_zigbee);
    exit(0);

    return 0;
}