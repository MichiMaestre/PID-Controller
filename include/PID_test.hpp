/*
 * @author Miguel Maestre Trueba
 *
 * @file PID_test.hpp
 *
 * @brief PID Controller Class tests header
 *
 * @copyright Miguel Maestre 2017
 *
 */

#include "../include/PID.hpp"
#include <vector>
#include <iostream>

/*
 * @brief Compute method for PID Controller. Iterates for 500 steps and tries to reach 50 starting at 0
 *
 * @return The final value of the controlled velocity
 *
 * @TODO [RaviBhadeshiya] Tune the gains to make the system stable
 */
double compute() {
  PID pid;

  double state = 0;
  int count = 0;
  // For iterating 500 steps
  while (count < 500){
    // Compute and update the state
    state += pid.control(state,50);
    count++;
  }

  return state;
}

/*
 * @brief Compute method that checks if after 500 steps, the integral element of the controller is close to 0
 *
 * @return The final value of the integral element of the controller
 *
 * @TODO [RaviBhadeshiya] Find and correct the error that makes the Integral element never reach 0
 */
double integral_check() {
  PID pid;
  double state = 0;
  int count = 0;
  while (count < 500){
    // Compute and update state
    state += pid.control(state,10);
    count++;
  }
  // Return the integral value after 500 iterations
  return pid.integral;
}
