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


JoystickController::JoystickController(int **axes, int **buttons)
{
	if((m_fd = open(JOY_DEV, O_RDONLY | O_NONBLOCK)) == -1)
    {
        printf( "Couldn't open joystick\n" );
        return;
    }

    ioctl(m_fd, JSIOCGNAME(NAME_LENGTH), &m_name);

    int data;
    ioctl(m_fd, JSIOCGAXES, &data);
    m_numAxes = data;

    ioctl(m_fd, JSIOCGBUTTONS, &data);
    m_numButtons = data;

	m_axes = (int *) calloc(m_numAxes, sizeof(int));
    *axes = m_axes;

    m_buttons = (int *) calloc(m_numButtons, sizeof(char));
    *buttons = m_buttons;
}

JoystickController::~JoystickController()
{
    free(m_axes);
    free(m_buttons);
    close(m_fd);
}

void JoystickController::getInfo(char *name, int &numAxes, int &numButtons) const
{
    strncpy(name, m_name, sizeof(m_name) > NAME_LENGTH ? NAME_LENGTH : sizeof(m_name));
    numAxes = m_numAxes;
    numButtons = m_numButtons;
}

void JoystickController::update()
{
    read(m_fd, &m_js, sizeof(struct js_event));
    switch(m_js.type & ~JS_EVENT_INIT)
    {
        case JS_EVENT_AXIS:
            m_axes   [ m_js.number ] = m_js.value;
            break;
        case JS_EVENT_BUTTON:
            m_buttons [ m_js.number ] = m_js.value;
            break;
    }
}

