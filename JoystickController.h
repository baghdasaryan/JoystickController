// ############################################ //
// ############################################ //
// ####                                    #### //
// ####    Program: Joystick Controller    #### //
// ####    Language: C++                   #### //
// ####    Author: Georgi Baghdasaryan     #### //
// ####    Email: baghdasaryan@ucla.edu    #### //
// ####                                    #### //
// ############################################ //
// ############################################ //


#ifndef __JOYSTICKCONTROLLER_H__
#define __JOYSTICKCONTROLLER_H__


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <string.h>

#define JOY_DEV "/dev/input/js0"
#define NAME_LENGTH 80

#define DIRECT_JS_INPUT

// Mainly for Logitech F710
// See manual: http://www.logitech.com/assets/34885/f710620-002923003403gswamr.pdf
/* ************************** */
#ifdef DIRECT_JS_INPUT

// Four action buttons
#define JB_A 1
#define JB_B 2
#define JB_X 0
#define JB_Y 3

#define JB_LB 4    // Left Button
#define JB_RB 5    // Right Button

// mini-stick buttons
#define JB_LMS 10
#define JB_RMS 11

// Start and Back buttons
#define JB_BACK 8
#define JB_START 9

// Left side: mini-sticks(horizontal and vertical)
#define JT_LMS_HOR 0 
#define JT_LMS_VERT 1

// Right side: mini-sticks(horizontal and vertical) and trigger
#define JT_RMS_HOR 2
#define JT_RMS_VERT 3

// 8-way D-pad
#define JT_PAD_HOR 4
#define JT_PAD_VERT 5

// Left and right side triggers
#define JT_LT 10
#define JT_RT 11

#endif  // DIRECT_JS_INPUT
/* ************************** */

class JoystickController
{
    public:
        JoystickController(int **axes, char **buttons);
        ~JoystickController();

        void getInfo(char *name, int &numAxes, int &numButtons) const;
        void update();

    private:
        struct js_event m_js;
        int m_fd;                   // file descriptor
        char m_name[NAME_LENGTH];
        int m_numAxes;
        int *m_axes;
        int m_numButtons;
        char *m_buttons;
};

#endif  // __JOYSTICKCONTROLLER_H__

