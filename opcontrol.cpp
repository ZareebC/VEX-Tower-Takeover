#include "main.h"
#include "variables.h"
using namespace okapi;
int FRONT_LEFT = 1;
int FRONT_RIGHT = -2;
int BACK_LEFT = -3;
int BACK_RIGHT = 4;
pros::Motor motor1 (1);
pros::Motor motor2 (2);
pros::Motor motor3 (3);
pros::Motor motor4 (4);
int ch1;
int ch2;
int ch3;
int ch4;
int thresh = 20;


void opcontrol() {

	pros::Controller controller (pros::E_CONTROLLER_MASTER);
	ControllerButton runAutoButton(ControllerDigital::X);

	while(true){
		ch2 = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		ch1 = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		ch3 = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		ch4 = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
		if((abs(ch1) > 0) || (abs(ch2) > 0) || (abs(ch3) > 0) || (abs(ch4) > 0)){
			if(abs(ch1) < thresh) {
				ch1 = 0;
			}
			if(abs(ch2) < thresh) {
				ch2 = 0;
			}
			if(abs(ch3) < thresh) {
				ch3 = 0;
			}
			if(abs(ch4) < thresh) {
				ch4 = 0;
			}

			if(abs(ch3) > abs(ch2)) {
				ch2 = 0;
			}
			else {
				ch3 = 0;
			}

			if(abs(ch3) > 80){
				ch1*=.707106781186548;
			}
		}
			drive(ch1, ch2, ch3, ch4);
		pros::Task::delay(10);

	}
}

		if(runAutoButton.changedToPressed()){
			for(int i = 0; i < 4; i++){
				myChassis.moveDistance(12_in);
				myChassis.turnAngle(90_deg);
			}
		}

		pros::Task::delay(10);
	}

}
