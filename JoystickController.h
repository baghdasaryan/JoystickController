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


// Mainly for Logitech F710
// See manual: http://www.logitech.com/assets/34885/f710620-002923003403gswamr.pdf
enum joystickButtons {
    // Four action buttons
    JB_A, JB_B, JB_X, JB_Y,

    // Left Button
    JB_LB,

    // Right Button
    JB_RB,

    // Start and Back buttons
    JB_BACK,
    JB_START
};
enum joystickTriggers {
    // Left side: mini-sticks(horizontal and vertical) and trigger
    JT_LMS_HOR,
    JT_LMS_VERT,
    JT_LT,

    // Right side: mini-sticks(horizontal and vertical) and trigger
    JT_RMS_HOR,
    JT_RMS_VERT,
    JT_RT,

    // 8-way D-pad
    JT_PAD_HOR,
    JT_PAD_VERT
};

class JoystickController
{
    public:
        JoystickController(int **axes, int **buttons);
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
        int *m_buttons;
};

#endif  // __JOYSTICKCONTROLLER_H__

