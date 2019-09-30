#include "main.h"
#include "variables.h"
//using namespace okapi;

pros::Motor FrontRight (FRONT_RIGHT);
pros::Motor FrontLeft (FRONT_LEFT);
pros::Motor BackLeft (BACK_LEFT);
pros::Motor BackRight (BACK_RIGHT);
pros::Motor TwoBar (TWO_BAR);
pros::Motor RightRoller (RIGHT_ROLLER);
pros::Motor LeftRoller (LEFT_ROLLER);
pros::Motor Pusher (PUSHER);


int RightX;
int RightY;
int LeftY;
int LeftX;

bool rollUpButton;
bool rollDownButton;
bool liftUpButton;
bool liftDownButton;
bool pushForwardButton;
bool pullBackwardsButton;
bool slowrollfor;
bool slowrollback;
int thresh = 40;

void opcontrol()
{

	pros::Controller controller (CONTROLLER_MASTER);

	while(true)
	{

    RightX = controller.get_analog(ANALOG_RIGHT_X);
		RightY = controller.get_analog(ANALOG_RIGHT_Y);
		LeftY = -(controller.get_analog(ANALOG_LEFT_Y));
		LeftX = controller.get_analog(ANALOG_LEFT_X);

		rollUpButton = controller.get_digital(DIGITAL_R2);
		rollDownButton = controller.get_digital(DIGITAL_R1);
    liftUpButton = controller.get_digital(DIGITAL_L2);
    liftDownButton = controller.get_digital(DIGITAL_L1);
		pushForwardButton = controller.get_digital(DIGITAL_UP);
		pullBackwardsButton = controller.get_digital(DIGITAL_DOWN);
		slowrollfor = controller.get_digital(DIGITAL_A);
		slowrollback = controller.get_digital(DIGITAL_Y);

		if((abs(RightX) > 0) || (abs(RightY) > 0) || (abs(LeftY) > 0) || (abs(LeftX) > 0))
		{
			if(abs(RightX) < thresh)
			{
				RightX = 0;
			}
			if(abs(RightY) < thresh)
			{
				RightY = 0;
			}
			if(abs(LeftY) < thresh)
			{
				LeftY = 0;
			}
			if(abs(LeftX) < thresh)
			{
				LeftX = 0;
			}

			if(abs(LeftY) > abs(RightY))
			{
				RightY = 0;
			}
			else {
				LeftY = 0;
			}

			if(abs(LeftY) > 80)
			{
				RightX *= .707106781186548;
			}
		}

		drive(RightX, RightY, LeftX, LeftY);
    lift(liftUpButton, liftDownButton);
		roll(rollUpButton, rollDownButton, slowrollfor, slowrollback);
		push(pushForwardButton, pullBackwardsButton);

		pros::Task::delay(10);
	}
}
