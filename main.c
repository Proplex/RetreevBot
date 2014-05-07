#include "functions.h"

int main() {
	init(5);
	create_direct_left();
	while(isdark_front() == false) {
		create_drive_straight(create_forward_speed);
	}
	while(isdark_right() + isdark_left() < 1) {
		create_drive_straight(create_forward_speed_slow);
	}
	create_black_align();
	while(isdark_front() + isdark_rear() < 1) {
		create_drive_straight(create_forward_speed_slow);
	}
	while(isdark_front()) {
		create_spin_CCW(create_turn_speed_slow);
	}
	while(ispressed_switch() == false) {
		create_drive_straight(create_forward_speed_slow);
	}
	close_claw();
	raise_claw();
}
