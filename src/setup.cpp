//
// Created by tyler on 9/21/2022.
//
#include "ports.h"
#include "main.h"
#include "../include/setup.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);

void drive_control() {
    int left = master.get_analog(ANALOG_LEFT_X);
    int right = master.get_analog(ANALOG_LEFT_Y);

    left_mtr = left;
    left2_mtr = left;
    right_mtr = right;
    right2_mtr = right;
    pros::delay(20);
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
