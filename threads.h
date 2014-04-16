#include "setvar.h"
/*
This file is responsible for all threaded functions that the main thread will call from time to time, including servolocks, and other sensor-related functions that must run at all times.
This also includes the functions that each thread will call for ease of use.
*/
void servolock() {
	while(1){
	set_servo_position(1,1900);
    sleep(2);
	}
}

void thread_start_servolock() {
	thread tid;
	tid = thread_create(servolock);
	thread_start(tid);
  	if(debugmode==1) printf("Servo lock thread started. \n");
}
