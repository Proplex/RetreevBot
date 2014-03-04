/*
PORT MAP (All Left/Right from viewpoint where CBC I/O ports are facing the person)
Motor0: Left Motor
Motor1: Right Motor
Digital13: Center Infared
Digital15: Right Infared
Digital14: Left Infared
Digital12: Back Infared (Unused)
 
COLOR MAPS:
Channel 0: Orange
Channel 1: Pink
Channel 2: Green
*/
int objectx;
int objecty;
int objecth;
int objectany;
int objecttopy;
int x;
int y;
int z;
int debugmode;
int progress;

	
void initialise() {
	camera_open(LOW_RES);
	if(debugmode==1) printf("Camera started. \n");
	enable_servos();
	if(debugmode==1) printf("Servos enabled. \n");
}

void startlight(int port) {
	if (side_button() == 1) {
		if (debugmode==1) printf ("Manual calibration mode \n");
		wait_for_light(port);
	} else { 
			if (debugmode==1) printf("Automatic calibration mode \n");
			set_b_button_text("Force");
			if (debugmode==1) printf("Current LS: %d", analog10(port));
			while(analog10(port) > 950 || b_button_clicked()==0);
			}	
}

void varget() {
	camera_update();
	objectx=get_object_center(0,0).x;
	objecty=get_object_center(0,0).y;
	objecth=get_object_bbox(0,0).height;
	objectany=get_object_count(0);
	objecttopy=get_object_bbox(0,0).uly;
	if(debugmode=1) printf("X: %d Y: %d H: %d C: %d YH: %d \n", objectx, objecty, objecth,objectany, objecttopy);
}

void centerbot() {
	motor(0,5);
	motor(1,45);
	sleep(4);
}
void clear()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void go_forward() { //the go forward function, sets both wheels to positive power to direct them forward
	if(debugmode==1) printf("going forward for inf \n");
	motor(0,30);
	motor(1,28);
}
void go_forward_slow() { //the go forward function, sets both wheels to positive power to direct them forward
    if(debugmode==1) printf("going forward for inf slowly \n");
	motor(0,55);
	motor(1,50);
}
int go_backward() { //the backward function, sets both wheels to negative power to direct them backwards
	if(debugmode==1) printf("going backward \n");
	motor(0,-75);
	motor(1,-77);
}
int rotate_left() { //rotates the wheels in opposite directions so that the bot turns left
	if(debugmode==1) printf("rotating left \n");
	motor(0,-23);
	motor(1,23);
}

int slight_left() { //rotates the wheels in opposite directions so that the bot turns left
	if(debugmode==1) printf("slight left \n");
	motor(0,15);
	motor(1,37);
}

int slight_right() { //rotates the wheels in opposite directions so that the bot turns right
	if(debugmode==1) printf("slight right \n");
	motor(0,35);
	motor(1,15);
}


int rotate_right() { //rotates the wheels in opposite directions so that the bot turns right
	if(debugmode==1) printf("rotating right \n");
	motor(0,23);
	motor(1,-23);
}

int slow_down() { //to prevent the bot from tipping over, a function was created to slowly lower the wheels to 0 so that it doesn't jerk.
	if(debugmode==1) printf("object detected, slowing down \n");
	motor(0,55);
	motor(1,50);
	sleep(0.2);
	motor(0,30);
	motor(1,27);
	sleep(0.2);
	ao();
}

int speed_up() {
	if(debugmode==1) printf("resuming \n");
	motor(0,30);
	motor(1,27);
	sleep(0.4);
	motor(0,55);
	motor(1,50);
	sleep(0.4);
}

int speed_up_back() {
	if(debugmode==1) printf("resuming backards\n");
	motor(0,-30);
	motor(1,-27);
	sleep(0.4);
	motor(0,-55);
	motor(1,-50);
	sleep(0.4);
}

int complete() {
	printf("NO PROBLEM\n");
	beep();
	beep();
	beep();
	return(0);
}
