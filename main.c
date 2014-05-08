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
	thread_start_lower_claw();
	while(isdark_front() == false) {
		create_spin_CCW(create_turn_speed_slow);
	}

	create_stop();
	thread_wait(lc);
	while(ispressed_claw() == false) {
		create_drive_straight(create_forward_speed_slow);
	}
	create_stop();
	close_claw();
	thread_start_raise_claw();
	while(isdark_front() == false) {
		create_drive_straight(create_forward_speed_slow);
	}
	setzero_distance();
	create_go_forward(1250);
	create_stop();
	thread_destroy(rc);
	create_direct_left();
	create_spin_CCW(create_turn_speed_slow);
	msleep(50);
	create_go_forward(100);
	open_claw();
	create_go_forward(200);
	create_stop();


}
