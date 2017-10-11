#include "pch.h"


TEST(TestMyString, isAnagram) {
	MyString string;
	EXPECT_TRUE(string.check_anagram_words("kumar", "ramuk"));
}

TEST(TestMyString, isNotAnagram) {
	MyString string;
	EXPECT_FALSE(string.check_anagram_words("kumar", "komar"));
	EXPECT_FALSE(string.check_anagram_words("kumar", "kuumar"));
}