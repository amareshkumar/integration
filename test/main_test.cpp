/***************************************************
* Consolidated Test cases for functionalities in   *
* integrated as a whole as library				   *
* Author:	Amaresh Kumar
* Date:		May 8th 2019
***************************************************/

#include "gtest/gtest.h"

#include "../inc/my_project_app.h"
#include "../inc/calc.h"
#include "../inc/Triangle.h"
#include "../inc/Shape.h"

#include "../inc/bit_manipulation.hpp"

TEST(calc_test, avg_salary)
{
	ASSERT_DOUBLE_EQ(10.0, avg_salary(4));
}

TEST(triangle_test, area)
{
	Shape *sp = new Triangle(10, 20);
	ASSERT_DOUBLE_EQ(100.0, sp->get_area());

	delete sp;
}

TEST(no_of_set_bits_test, simple_integer)
{
	EXPECT_EQ(2, no_of_set_bits(6));
	EXPECT_EQ(3, no_of_set_bits(13));
	EXPECT_EQ(3, no_of_set_bits(7));
}

TEST(no_of_set_bits_DeathTest, integer_zero)
{
	//ToDo: how to skip this crashing test case
	//EXPECT_DEATH("with zero the application crashes", no_of_set_bits(0));
	//EXPECT_DEATH({ no_of_set_bits(0); }, "with zero the application crashes");
}

/****
* Tests for functionalities of class KumarAlgoImpl
* Using class fixture to test functionalites 
* of class KumarAlgoImpl e.g. is_palindrome
****/

//Fixture class
class KumarAlgoImplTest : public ::testing::Test
{

protected:
	void SetUp() override {}

	void TearDown() override {}
	KumarAlgoImpl kumar_algo_impl;
};

// not using fixture here
TEST(KumarAlgoImplTestWithoutFixture, prime_sum)
{
	KumarAlgoImpl kumar_algo_impl;
	//sum = 20, expected prime numbers 3, 17;
	vector<int> prime_sum{3, 17};
	vector<int> prime_sum2{7, 13};

	EXPECT_EQ(prime_sum, kumar_algo_impl.prime_sum(20));
	EXPECT_NE(prime_sum2, kumar_algo_impl.prime_sum(20));
}

TEST_F(KumarAlgoImplTest, is_palindrome)
{
	//KumarAlgoImpl kumar_algo_impl;

	EXPECT_FALSE(kumar_algo_impl.isPalindrome("aaaabbbbcccc"));
	EXPECT_FALSE(kumar_algo_impl.isPalindrome("amareshkumar"));
	EXPECT_TRUE(kumar_algo_impl.isPalindrome("navan"));
}

TEST_F(KumarAlgoImplTest, four_sum_3)
{
	//KumarAlgoImpl kumar_algo_impl;

	vector<int> input{2, 3, 5, 7, 11, 13, 15, 17, 19, 20, 21, 23, 25};

	vector<vector<int>> expected;
	expected.push_back({2, 3, 7, 13});
	expected.push_back({3, 5, 7, 15});
	expected.push_back({2, 3, 5, 20});

	EXPECT_EQ(expected, kumar_algo_impl.fourSum(input, 30));
}

TEST_F(KumarAlgoImplTest, four_sum_1)
{
	//KumarAlgoImpl kumar_algo_impl;

	vector<int> input{2, 3, 5, 7, 10, 13, 15, 17, 19};

	vector<vector<int>> expected;
	expected.push_back({2, 3, 5, 10});

	EXPECT_EQ(expected, kumar_algo_impl.fourSum(input, 20));
}

TEST(calc_test, avg_salary){
  ASSERT_DOUBLE_EQ(10.0, avg_salary(4));
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}