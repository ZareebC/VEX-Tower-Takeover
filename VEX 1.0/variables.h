#define INCLUDE_VARIABLES_H

#include "main.h"

int FRONT_LEFT = 1;
int FRONT_RIGHT = 2;
int BACK_LEFT = 10;
int BACK_RIGHT = 4;

int TWO_BAR = 5;
int RIGHT_ROLLER = 6;
int LEFT_ROLLER = 7;
int PUSHER = 8;

void drive(int ch1, int ch2, int ch3, int ch4);

void lift(bool liftUpButton, bool liftDownButton);

void roll(bool rollUpButton, bool rollDownButton, bool slowRollUp, bool slowRollDown);

void push(bool pushForwardButton, bool pullBackwardsButton);
