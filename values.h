#include "setvar.h"
/*
This is a file that sets variables for the various Retreev functions. Editing these numbers is not recommended unless it's necessary.

VALUE KEY:
LIGHTVALUE: Default light sensor value, to allow for light-start but without having to calibrate every time. (1-1010, analog)

DEBUGMODE: Verbosely print all actions; including movements, sensor values, and thread actions. (1=yes or 0=no)

CREATEMODE: Mode the create should enter, only supports SAFE or FULL. (0 for safe, 1 for full.) WARNING: 1/FULL MEANS THE CREATE WILL FALL OFF A CLIFF SHOULD IT ENCOUNTER ONE.

CREATE_WARN_BATT: When the the battery level, in percentage, of the Create goes below defined value (1-100)

FORCEMODE: When set to 1, the Retreev will ignore all start-light values and immediately run the main function once setup.

CREATE_LEFT_TURN: The Create is rather poor in measuring angles so it needs to be set manually. In order to turn a 90 degree angle to the LEFT, set the degree the Create should wait for here. (Example: IRL the Create turned 90 degrees after reporting it measured 75 degrees) (0-359)

CREATE_RIGHT_TURN: The Create is rather poor in measuring angles so it needs to be set manually. In order to turn a 90 degree angle to the RIGHT, set the degree the Create should wait for here. (Example: IRL the Create turned 90 degrees after reporting it measured 75 degrees) (0-359)

CREATE_ZERO: The degrees the function setzero() should set. This should always be 0.

CREATE_TURN_SPEED: The speed of the Create while turning. (0-500)

CREATE_FORWARD_SPEED: The speed of the Create while going forward. MUST BE NEGATIVE (0-500)

SENSOR_IR: The port where the IR sensor will be found. Will be analog, so it should always be under 7. (0-7)

SENSOR_IR_DARKNESS: The minimum threshold the IR sensor should report when hovering over dark tape. (0-1010)
*/

#define lightvalue 950
#define debugmode 1
#define createmode 1
#define create_warn_batt 25
#define startmode 3
#define create_zero 0
#define sensor_f_IR 0
#define sensor_f_IR_dark 800
#define sensor_r_IR 1
#define sensor_r_IR_dark 800
#define sensor_rt_IR 2
#define sensor_rt_IR_dark 800
#define sensor_l_IR 3
#define sensor_l_IR_dark 800
#define claw_switch 15
#define create_left_turn 68
#define create_right_turn -75
#define create_turn_speed 250
#define create_turn_speed_slow 100
#define create_forward_speed_slow -100
#define create_forward_speed -200
#define create_backward_speed 200
#define create_backward_speed_slow 100
#define create_180_turn 160
#define claw_servo 1
#define claw_open_pos 2000
#define claw_close_pos 100
#define claw_down_speed -75
#define claw_up_speed_max 100
#define claw_up_speed_min 1
#define claw_motor 1
#define height_switch 10
#define bottom_switch 14
thread rc;
thread lc;


