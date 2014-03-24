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
        printf("PAD_VERT=%6d    ", axes[JT_PAD_VERT]);

		printf("\r");
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
        printf("A=%d ", buttons[JT_A]);
        printf("B=%d ", buttons[JT_B]);
        printf("X=%d ", buttons[JT_X]);
        printf("Y=%d ", buttons[JT_Y]);
        printf("LB=%d ", buttons[JT_LB]);
        printf("RB=%d ", buttons[JT_RB]);
        printf("back=%d ", buttons[JT_BACK]);
        printf("start=%d ", buttons[JT_START]);

		printf("\r");
		fflush(stdout);
    }
}

