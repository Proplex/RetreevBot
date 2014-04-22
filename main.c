#include "functions.h"
int main() {
	init(5);
	create_direct_left();
	continue_until(2);
	create_black_align();
	while(isdark_right && isdark_left == false) {
		create_drive_straight(create_forward_speed)
	}
	while(isdark_front == true) {
		create_drive_straight(create_forward_speed);
	}
	create_go_forward(1200);
}
