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
	turn_until(1);
	while(isdark_front()) {
		create_drive_straight(create_forward_speed);
	}
	while(ispress_switch() == false) {
		create_drive_straight(create_forward_speed_slow);
	}
	close_claw();
	raise_claw();
}
