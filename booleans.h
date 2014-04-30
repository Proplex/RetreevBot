#include <stdbool.h>

bool isdark_front() {
    if(analog10(sensor_f_IR) > sensor_f_IR_dark) {
        return true;
    } else {
        return false;
    }
}

bool isdark_right() {
    if(analog10(sensor_rt_IR) > sensor_rt_IR_dark) {
        return true;
    } else {
        return false;
    }
}

bool isdark_left() {
    if(analog10(sensor_l_IR) > sensor_l_IR_dark) {
        return true;
    } else {
        return false;
    }
}

bool ispress_switch() {
        if(digital(claw_switch) == 1) {
            return true;
        } else {
            return false;
        }
}
