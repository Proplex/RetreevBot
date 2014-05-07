#include "functions.h"

int main() {
	init(5);
	raise_claw();
	open_claw();
	create_direct_left();
	while(isdark_front() == false) {
		create_drive_straight(create_forward_speed);
	}
	while(isdark_right() + isdark_left() < 1) {
		create_drive_straight(create_forward_speed_slow);
	}
	create_black_align();
	while(isdark_front() == false) {
		create_spin_CCW(create_turn_speed_slow);
	}
	create_stop();
	msleep(500);
	lower_claw();
	while(ispressed_claw() == false) {
		create_drive_straight(create_forward_speed_slow);
	}
	close_claw();
	raise_claw();
}
