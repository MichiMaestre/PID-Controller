/*
 * @author Miguel Maestre Trueba
 *
 * @file PID.cpp
 *
 * @brief PID Controller Class calculations to control velocity
 *
 * @copyright Miguel Maestre 2017
 *
 */

#include "../include/PID.hpp"

/*
 * @brief Control Function that calculates the Proportional, Integral and Derivative elements of the PID
 *
 * @param actual_vel is current speed
 * @param target_vel is desired speed
 * @param error_v is the current error
 * @param error_prev is the previous error
 * @param dt is the time step
 * @param integral is the integral element
 * @param derivative is the derivative element
 * @param kp, ki, kd are the controller gains
 *
 * @return The controlled speed given by the PID
 */
double PID::control(double actual_vel, double target_vel) {
  error_v = target_vel - actual_vel;

  integral = integral + (error_v * dt);

  double derivative = (error_v - error_prev) / dt;

  error_prev = error_v;

  double output = kp * error_v + ki* integral + kd * derivative;

  return output;
}
