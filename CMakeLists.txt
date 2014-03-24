CMAKE_MINIMUM_REQUIRED( VERSION 2.8  )
PROJECT( JoystickController )
SET( jc_SRCS JoystickController.cpp test.cpp )
ADD_EXECUTABLE( jc ${jc_SRCS} )
