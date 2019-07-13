#include "variables.h"
#include "main.h"
#include <math.h>
pros::Motor move1 (1);
pros::Motor move2 (2);
pros::Motor move3 (3);
pros::Motor move4 (4);
void drive(int ch1, int ch2, int ch3, int ch4){ //a corresponds to the individual analog button axes
  move4.move(ch3  + ch4 + ch1);
  move1.move(ch3 - ch4 + ch1);
  move2.move(-(ch3 - ch4 - ch1));
  move3.move(-(ch3 + ch4 - ch2));
}
