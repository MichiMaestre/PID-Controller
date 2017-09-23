/*
 * @author Miguel Maestre Trueba
 *
 * @file PID.hpp
 *
 * @brief PID Controller Class to control velocity
 *
 * @copyright Miguel Maestre 2017
 *
 */
#pragma once

#include<iostream>

class PID {
 private:
  double kp = 5;
  double ki = 2;
  double kd = 2;
  double integral = 0;
  double error_v;
  double error_prev = 0;
  int dt = 1;

 public:
  double target_vel;
  double actual_vel;

  /*
   * @brief Control Function that calculates the Proportional, Integral and Derivative elements of the PID
   *
   * @param actual_vel is current speed
   *
   * @param target_vel is desired speed
   *
   * @return The controlled speed given by the PID
   */
  double control(double actual_vel, double target_vel);
};
