/*
This file includes most of the functions called by the RetreevBot. Threads can be found in threads.h, and values called can be found values.h.
*/

#include "setvar.h"
#include "values.h"
#include "threads.h"
#include "booleans.h"


//Init function that starts most things needed for the Retreev
void init(int port) { //Port refers to the analog port used to grab light sensor information
    values(); //Sets all values found in values.h. THIS SHOULD ALWAYS BE FIRST OR ELSE THINGS /WILL/ BREAK
    display_clear(); //The camera library is somehow buggy and outputs a ton of garbage warnings when starting up. This at least gets rid of it.
    if(debugmode==1) printf("Camera started. \n");
    enable_servos();
    if(debugmode==1) printf("Servos enabled. \n");
    create_connect();
    if(debugmode==1) printf("Create connected. \n");
    if (createmode==1){ //This if statement reads the createmode value and sets it accordingly
        create_full();
        printf("!!!!!!!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!\nCREATE IS IN FORCE MODE. IT WILL NOT STOP AT CLIFFS\n!!!!!!!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!\n");
    } else {
        create_safe();
        if(debugmode==1) printf("Create is in safe mode\n");
    }
    create_battery_now=(((double)get_create_battery_charge())/get_create_battery_capacity())*100;
    if (create_battery_now < create_warn_batt) {
        printf("!!!!!!!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!\nCREATE BATTERY LOW. BATTERY AT %g%%\n!!!!!!!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!\n", create_battery_now);
        sleep(3);
    }
    else{
        printf("Create battery level %g%%\n", create_battery_now);
    }
    if (side_button() == 1) { //The rest of the function initates the startlight function. If the side hardware button is pressed, it will call the wait_for_light function, which is built in [This should be used during the real competition, but for testing, the value from lightvalue will suffice]. Alternatively, you can override this entire function by setting forcemode to 1, in values.h
        if (debugmode==1) printf ("Manual calibration mode \n");
        wait_for_light(port);
    } else {
        if (debugmode==1) printf("Using predetermined light value: %d \n", lightvalue);
        set_b_button_text("Force");
        if (debugmode==1) printf("Current LS: %d \nWaiting for trigger or force", analog10(port));
        while(analog10(port) > lightvalue && b_button()==0 && forcemode==0) {
            if (b_button()==1) {
                if(debugmode==1) printf("Start forced, waiting two seconds \n");
                sleep(2);
            }
        }
    }

}

/*
void camget() {
camera_update();
objectx=get_object_center(0,0).x;
objecty=get_object_center(0,0).y;
objecth=get_object_bbox(0,0).height;
objectany=get_object_count(0);
objecttopy=get_object_bbox(0,0).uly;
if(debugmode==1) printf("X: %d Y: %d H: %d C: %d YH: %d \n", objectx, objecty, objecth, objectany, objecttopy);
}
*/
void setzero_angle() { //This normalizes the angle distance the Create uses to measure how far it has turned. The value can be set using create_zero, found in values.h
    set_create_normalized_angle(create_zero);
    if(debugmode==1) printf("Angle measure set to %d\n", create_zero);
}

void setzero_distance() { //This normalizes the angle distance the Create uses to measure how far it has turned. The value can be set using create_zero, found in values.h
    set_create_distance(create_zero);
    if(debugmode==1) printf("Distance measure set to %d\n", create_zero);
}
void create_direct_left() { //This turns the Create, in place, 90 degrees to the left.
    setzero_angle();
    if(debugmode==1) printf("Turning directly left\n");
    while(get_create_normalized_angle() < create_left_turn) {
        printf("%d\n", get_create_normalized_angle());
        create_spin_CCW(create_turn_speed);
    }
}

void create_direct_right() {
    setzero_angle();
    if(debugmode==1) printf("Turning directly right\n");
    while(get_create_normalized_angle() > create_right_turn) {
        create_spin_CW(create_turn_speed);
    }
}

void create_180() {
    setzero_angle();
    if(debugmode==1) printf("Turning around\n");
    while(get_create_normalized_angle() < create_180_turn) {
        create_spin_CCW(create_turn_speed);
    }
}

void turn_until(int action2) {
    if(action2==1) {
        if(debugmode==1) printf("Turning until black line alignment\n");
        while(analog10(sensor_f_IR) < sensor_f_IR_dark || analog10(sensor_r_IR) < sensor_r_IR_dark) {
            create_spin_CCW(create_turn_speed_slow);
            if (debugmode==1) printf("F: %d R: %d\n",analog10(sensor_f_IR),analog10(sensor_r_IR));
        }

    }
}
void create_black_align() {
    setzero_distance();
    while(get_create_distance() < 4) {
        create_drive_straight(create_backward_speed_slow);
    }
    /*
    setzero_angle();
    while(get_create_angle() < 4) {
    create_spin_CW(100);
}
setzero_distance();
while(get_create_distance() < -4) {
create_drive_straight(create_forward_speed_slow);
}
*/
}

void create_go_forward(int distance_create) {
    setzero_distance();
    distance_create=distance_create*-1;
    while(get_create_distance() > distance_create) {
        if(debugmode==1) printf("Going %d. At %d.\n",distance_create,get_create_distance());
        create_drive_straight(create_forward_speed);
    }
}

void raise_claw() {
    while(ispress_height() == false) {
        motor(claw_motor,claw_up_speed_max);
    }
}

void lower_claw() {
    /* Lower claw */
}

void close_claw() {
    if(debugmode==1) printf("Closing claw on port %d\n", claw_servo);
    set_servo_position(claw_servo,claw_close_pos);
}

void open_claw() {
    if(debugmode==1) printf("Opening claw on port %d\n", claw_servo);
    set_servo_position(claw_servo,claw_open_pos);
}
