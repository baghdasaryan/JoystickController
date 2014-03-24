JoystickController
==================

A class that helps in getting data from a USB joystick

Contributors
------------
| Name                | Email                             |
| ----                | -----                             |
| Georgi Baghdasaryan | baghdasaryan@ucla.edu             |

Project Description
-------------------
A simple program that helps in getting input from joystick connected via USB.
Please note that, since this program was built specifically for 
[Logitech F710 Wireless Gamepad](http://gaming.logitech.com/en-us/product/f710-wireless-gamepad "Logitech F710"),
you might need to make some changes to it to get it working for other
controllers. 

Usage
-----
First, we need to download and build the project. Follow the following steps to
do so:

```shell
$ git clone https://github.com/baghdasaryan/Bruinbase-Database.git
$ cd JoystickController/build/
$ cmake ..
$ make
```

`make` will create the executable file, `jc`, in the current (build) directory.

Now you can test the program by running:
```shell
$ ./jc
```

