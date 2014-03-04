#include "functions.h"
int main() {
	debugmode=1;
	initialise();
	startlight(5);
	centerbot();
	while(1) {
		varget();
		if(objecth < 15 && z==0) {
			clear();
			rotate_right();
			progress=0;
		}
		else if(progress==0){
			z=1;
			varget();
			if(objectx > 45 && objectx < 84 && objecth > 15) {
				clear();
				go_forward();
			}
			if(objectx > 85 && objecth > 15) {
				clear();
				rotate_right();
			}
			if(objectx < 45 && objecth > 15) {
				clear();
				rotate_left();
			}
			if (objecttopy > 110) {
				progress=1;
			}
			if (objectany == 0 && objecth > 15) {
				z=0;
			}
		}
		else if(progress==1) {
          /*
          Once the ball is found, get the ball to the barrel.
          */
			
		}
        else if(progress=2) {
           /*
           Once at the barrel, drop the ball, and move the barrel onto our side to prevent people from gaining the points.
           */
        }
	}
}
