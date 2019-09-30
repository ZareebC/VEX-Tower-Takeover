#include "variables.h"
#include "main.h"
#include <math.h>

pros::Motor move1 (FRONT_LEFT);
pros::Motor move2 (FRONT_RIGHT);
pros::Motor move3 (BACK_LEFT);
pros::Motor move4 (BACK_RIGHT);

pros::Motor twoBar (TWO_BAR);
pros::Motor rightRoller (RIGHT_ROLLER);
pros::Motor leftRoller (LEFT_ROLLER);
pros::Motor pusher (PUSHER);


void drive(int ch1, int ch2, int ch3, int ch4)
{
  move4.move(-ch3  + ch4 + ch1);
  move1.move(ch3 - ch4 + ch1);
  move2.move(-(-ch3 - ch4 - ch1));
  move3.move(-(ch3 + ch4 - ch1));
}

void lift(bool liftUpButton, bool liftDownButton)
{
  if(liftUpButton)
  {
    twoBar.move_velocity(100);
  }
  else if(liftDownButton)
  {
    twoBar.move_velocity(-100);
  }
  else{
    twoBar.move_velocity(0);
  }
}

void roll(bool rollUpButton, bool rollDownButton, bool slowRollUp, bool slowRollDown)
{
  if(rollUpButton)
  {
    leftRoller.move_velocity(600);
    rightRoller.move_velocity(-600);
  }
  else if(rollDownButton)
  {
    leftRoller.move_velocity(-600);
    rightRoller.move_velocity(600);
  }
  else
  {
    leftRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    rightRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
}

void push(bool pushForwardButton, bool pullBackwardsButton)
{
  if(pushForwardButton)
  {
      pusher.move_velocity(-50);
  }
  else if(pullBackwardsButton)
  {
    if(pusher.get_position() == -520)
    {
       pusher.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    else
    {
      pusher.move_velocity(50);
    }
  }
  else
  {
    pusher.move_velocity(0);
  }

  if(pusher.get_position() <= -500)
  {
    leftRoller.move_velocity(30);
    rightRoller.move_velocity(-30);
  }
}
