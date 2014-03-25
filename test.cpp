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


#include "JoystickController.h"


void testInfo(JoystickController *jc);
void testButtons(JoystickController *jc, int *buttons);
void testAxes(JoystickController *jc, int *axes);

int main()
{
    int *axes;
    int *buttons;

    JoystickController jc(&axes, &buttons);

    testInfo(&jc);
    //testAxes(&jc, axes);
    //testButtons(&jc, buttons);
}

void testInfo(JoystickController *jc)
{
    char name[NAME_LENGTH];
    int num_axes;
    int num_buttonss;

    // Get data
    jc->getInfo(name, num_axes, num_buttonss);

    printf("Name: \"%s\"\n", name);
    printf("Number of axes: %d\n", num_axes);
    printf("Number of buttons: %d\n\n", num_buttonss);
    fflush(stdout);
}

void testAxes(JoystickController *jc, int *axes)
{
    while(true)
    {
        // Update controller state
        jc->update();

        // Left Side
        printf("LMS_HOR=%6d    ", axes[JT_LMS_HOR]);
        printf("LMS_VERT=%6d    ", axes[JT_LMS_VERT]);
        printf("LT=%6d    ", axes[JT_LT]);

        // Right Side
        printf("RMS_HOR=%6d    ", axes[JT_RMS_HOR]);
        printf("RMS_VERT=%6d    ", axes[JT_RMS_VERT]);
        printf("LT=%6d    ", axes[JT_RT]);

        // Pad
        printf("PAD_HOR=%6d    ", axes[JT_PAD_HOR]);
        printf("PAD_VERT=%6d", axes[JT_PAD_VERT]);

        printf("     \r");
        fflush(stdout);
    }
}

void testButtons(JoystickController *jc, int *buttons)
{

    while(true)
    {
        // Update controller state
        jc->update();

        // Print buttons
        printf("A = %1d; ", buttons[JB_A]);
        printf("B = %1d; ", buttons[JB_B]);
        printf("X = %1d; ", buttons[JB_X]);
        printf("Y = %1d; ", buttons[JB_Y]);
        printf("LB = %1d; ", buttons[JB_LB]);
        printf("RB = %1d; ", buttons[JB_RB]);
        printf("back = %1d; ", buttons[JB_BACK]);
        printf("start = %1d;", buttons[JB_START]);

        printf("     \r");
        fflush(stdout);
    }
}

