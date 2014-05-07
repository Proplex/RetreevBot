#include <stdbool.h>

bool isdark_front() {
    if(analog10(sensor_f_IR) > sensor_f_IR_dark) {
        return true;
    } else {
        return false;
    }
}

bool isdark_rear() {
    if(analog10(sensor_r_IR) > sensor_r_IR_dark) {
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

bool ispressed_claw() {
        if(digital(claw_switch) == 1) {
            return true;
        } else {
            return false;
        }
}

bool ispressed_height() {
        if(digital(height_switch) == 1) {
            return true;
        } else {
            return false;
        }
}

bool ispressed_bottom() {
        if(digital(bottom_switch) == 1) {
            return true;
        } else {
            return false;
        }
}
