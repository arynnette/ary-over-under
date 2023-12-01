/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <filesystem>

#include "main.h"

namespace ary::autonselector {
AutonSelector auton_selector{};

void page_up() {
  if (auton_selector.current_auton_page == auton_selector.auton_count - 1)
    auton_selector.current_auton_page = 0;
  else
    auton_selector.current_auton_page++;
  //update_auto_sd();
  auton_selector.print_selected_auton();
}

void page_down() {
  if (auton_selector.current_auton_page == 0)
    auton_selector.current_auton_page = auton_selector.auton_count - 1;
  else
    auton_selector.current_auton_page--;
  //update_auto_sd();
  auton_selector.print_selected_auton();
}

void initialize() {
  pros::lcd::initialize();
  //ary::autonselector::init_auton_selector();

  // Callbacks for auto selector
  ary::autonselector::auton_selector.print_selected_auton();
  pros::lcd::register_btn0_cb(ary::autonselector::page_down);
  pros::lcd::register_btn2_cb(ary::autonselector::page_up);
}

void shutdown() {
  pros::lcd::shutdown();
}

bool turn_off = false;

pros::ADIDigitalIn* left_limit_switch = nullptr;
pros::ADIDigitalIn* right_limit_switch = nullptr;
pros::Task limit_switch_task(limitSwitchTask);
void limit_switch_lcd_initialize(pros::ADIDigitalIn* right_limit, pros::ADIDigitalIn* left_limit) {
  if (!left_limit && !right_limit) {
    delete left_limit_switch;
    delete right_limit_switch;
    if (pros::millis() <= 100)
      turn_off = true;
    return;
  }
  turn_off = false;
  right_limit_switch = right_limit;
  left_limit_switch = left_limit;
  limit_switch_task.resume();
}

void limitSwitchTask() {
  while (true) {
    if (right_limit_switch && right_limit_switch->get_new_press())
      page_up();
    else if (left_limit_switch && left_limit_switch->get_new_press())
      page_down();

    if (pros::millis() >= 500 && turn_off)
      limit_switch_task.suspend();

    pros::delay(50);
  }
}
}