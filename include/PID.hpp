/*
 * @author Miguel Maestre Trueba
 *
 * @file PID.hpp
 *
 * @brief PID Controller Class to control velocity header
 *
 * @copyright Miguel Maestre 2017
 *
 */
#pragma once

#include<iostream>

class PID {
 private:
  double kp = 500;
  double ki = 500;
  double kd = 300;
  double error_v;
  double error_prev = 0;
  int dt = 1;

 public:
  double target_vel;
  double actual_vel;
  double integral = 0;

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

