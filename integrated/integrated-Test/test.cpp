#include "pch.h"

TEST(salary_avg, simple_cal) {
	EXPECT_EQ(7.5, avg_salary(3));
}

TEST(salary_avg, simple_cal_2) {
	EXPECT_NE(10, avg_salary(5));
}

TEST(mylogger, fileexistcheck) {
	const char *fileName = "C:/selfdev/logger.txt";
	fstream file;
	EXPECT_TRUE (file.good());
}
