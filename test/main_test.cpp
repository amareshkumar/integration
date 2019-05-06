#include "gtest/gtest.h"

#include "../inc/my_project_app.h"
#include "../inc/calc.h"
#include "../inc/Triangle.h"
#include "../inc/Shape.h"

TEST(calc_test, avg_salary){
  ASSERT_DOUBLE_EQ(10.0, avg_salary(4));
}

//TEST(triangle_test, area) {
//	Shape *sp = new Triangle (10, 20);
//	ASSERT_DOUBLE_EQ(100.0, sp->get_area());
//
//	delete sp;
//}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}