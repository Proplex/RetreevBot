#include "functions.h"
int main() {
	init(5);
	create_direct_left();
	while(isdark_front() == false) {
		create_drive_straight(create_forward_speed);
	}
	create_black_align();
	while(isdark_right() && isdark_left() == false) {
		create_drive_straight(create_forward_speed);
	}
	while(isdark_front()) {
		create_drive_straight(create_forward_speed);
	}
	create_go_forward(1200);
}
