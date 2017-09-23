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
  double current = 0;

  auto i1 = 0;
  std::vector<int> count1;
  while (i1 < 500) {
      count1.push_back(i1);
      i1++;
    }

  // Iterate 500 times and solve the control
  // to try to reach the target speed of 50
  for (int i : count1) {
    double out = pid.control(current, 50);
    current = current + out;
  }
  return current;
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
  double current = 0;

  auto i1 = 0;
  std::vector<int> count1;
  while (i1 < 500) {
      count1.push_back(i1);
      i1++;
    }

  for (int i : count1) {
    double out = pid.control(current, 50);
    current = current + out;
    pid.integral += 1;
  }
  return pid.integral;
}
