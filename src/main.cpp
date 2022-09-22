#include "main.h"
const int num_of_pages = 7;
void disable_all_tasks()
{
    drive_pid.suspend();
}
int current_page = 0;
void auto_select(bool is_auton)
{
    for (int i = 0; i < 7; i++)
        pros::lcd::clear_line(i);

    pros::lcd::set_text(0, "Page " + std::to_string(current_page + 1));

    switch (current_page)
    {
        case 0: // Auto 1
            pros::lcd::set_text(2, "Claw Auton");
            if (is_auton)
                tilter_auton(); // solo_awp();
            break;
        case 1: // Auto 2
            pros::lcd::set_text(2, "Biggiecheese Auton");
            if (is_auton)
                // auto_3();
                break;
        case 2: // Auto 3
            pros::lcd::set_text(2, "Skills auton");
            if (is_auton)
                skills_auton();
            break;
        case 3:
            pros::lcd::set_text(2, "Neutral auton:");
            pros::lcd::set_text(2, "Goes forward and picks up");
            pros::lcd::set_text(2, "the neutral goal");
            if (is_auton)
                neutral_auton();
            break;
        case 4:
            pros::lcd::set_text(2, "Win Point Auton");
            if (is_auton)
                win_point();
            break;
        case 5:
            pros::lcd::set_text(2, "Line Auton");
            if (is_auton)
                line_auton();
            break;
        case 6:
            pros::lcd::set_text(2, "New Mexico");
            if (is_auton)
                new_mexico();
            break;
        default:
            break;

    }
}

void page_up()
{
    if (current_page == num_of_pages - 1)
        current_page = 0;
    else
        current_page++;
    auto_select(false);
}
void page_down()
{
    if (current_page == 0)
        current_page = num_of_pages - 1;
    else
        current_page--;
    auto_select(false);
}
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    disable_all_tasks();

    pros::lcd::initialize();
    auto_select(false);
    pros::lcd::register_btn0_cb(page_down);
    pros::lcd::register_btn2_cb(page_up);


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
#include "setup.h"
void opcontrol() {


	while (true) {
    drive_control();
    //second_drive_control(); ///take this out of commetns if the other one doesn't work.

	}
}
