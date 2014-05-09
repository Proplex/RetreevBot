#include "functions.h"

int main() {
	init(5);
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
	create_spin_CW(create_turn_speed_slow);
	msleep(10);
	create_stop();
	thread_wait(lc);
	while(ispressed_claw() == false) {
		create_drive_straight(create_forward_speed_slow);
	}
	create_stop();
	close_claw();
	thread_start_raise_claw_timed();
	create_spin_CCW(create_turn_speed_slow);
	msleep(50);
	create_go(1250);
	thread_destroy(rc);
	create_direct_left();
	create_spin_CCW(create_turn_speed_slow);
	msleep(50);
	create_go(80);
	open_claw();
	thread_start_raise_claw();
	create_go(210);
	thread_destroy(rc);
	thread_start_lower_claw();
	create_go(-260);
	create_direct_left();
	create_go(950);
	create_direct_left();
	create_spin_CCW(create_turn_speed_slow);
	msleep(85);
	create_stop();
	lower_claw();
	while(ispressed_claw() == false) {
		create_drive_straight(create_forward_speed_very_slow);
	}
	create_stop();
	close_claw();
	raise_claw_timed();
	create_go(-260);
	thread_start_raise_claw();
	create_direct_left();
	create_go(960);
	create_direct_left();
	create_spin_CCW(create_turn_speed_slow);
	msleep(100);
	create_go_(75);
}
