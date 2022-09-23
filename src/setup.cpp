//
// Created by tyler on 9/21/2022.
//
#include "ports.h"
#include "main.h"
#include "../include/setup.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);

void forward_drive(){
    left_mtr.move(1000);
    left2_mtr.move(1000);
    right_mtr.move(1000);
    right2_mtr.move(1000);

}
void side_drive(){
    left_mtr.move(1000);
    left2_mtr.move(1000);
    right_mtr.move(-1000);
    right2_mtr.move(-1000);

}
void drive_control() {
    while (master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y))
        forward_drive();
        pros::delay(2);
    if (master.get_analog(ANALOG_LEFT_X))
        side_drive();
    pros::delay(2);


}

void second_drive_control() {

        int power = master.get_analog(ANALOG_LEFT_Y);
        int turn = master.get_analog(ANALOG_RIGHT_X);
        int left = power + turn;
        int right = power - turn;
        left_mtr.move(left);
        left2_mtr.move(left);
        right_mtr.move(right);
        right2_mtr.move(right);
        pros::delay(2);
}
