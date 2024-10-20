/*
 * @Author: LIAOYUXIAN 2391110993@qq.com
 * @Date: 2024-09-23 09:49:00
 * @LastEditors: LIAOYUXIAN 2391110993@qq.com
 * @LastEditTime: 2024-09-23 11:04:44
 * @FilePath: \lv_port0\app\led\led.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @file LED.h
 * Include all LVGL related headers
 */

#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui/ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../../ui/ui_events.h"
#include <termios.h> 
#include <sys/types.h>
#include <sys/select.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "./led/LED.h"
#include "./beep/BEEP.h"
#include "./usart/USART.h"
#include "./calculator/CALCULATOR.h"
#include "./video/VIDEO.h"
#include "./music/MUSIC.h"
#include "./login/login.h"
#include "./platform/PLATFORM.h"
#include "./album/ALBUM.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LED_H*/
