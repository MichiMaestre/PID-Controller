/*
 * @author Miguel Maestre Trueba
 *
 * @file PID_test.cpp
 *
 * @brief PID Controller Class tests
 *
 * @copyright Miguel Maestre 2017
 *
 */

#include <gtest/gtest.h>
#include "../include/PID.hpp"
#include "../include/PID_test.hpp"
#include "../app/PID.cpp"

/*
 * @brief Test the compute method for the PID controller
 */
TEST(PID_test1, unitTest1) {
  EXPECT_NEAR(50, compute(), 0.1);
}

/*
 * @brief Test if the integral element is behaving correctly
 */
TEST(PID_test2, unitTest2) {
  EXPECT_NEAR(0, integral_check(), 0.001);
}
