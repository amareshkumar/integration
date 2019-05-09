#include "gtest/gtest.h"

#include "../inc/programming.h"
#include "../inc/my_project_app.h"

TEST(programming_questions_test, reverse_string)
{
    programming_questions pq;
    EXPECT_EQ("kumar", pq.Reverse("ramuk"));
    EXPECT_EQ("AMARESH", pq.Reverse("HSERAMA"));
}

TEST(programming_questions_test, reverse_string_case_sensitive)
{
    programming_questions pq;
    EXPECT_NE("amaresh", pq.Reverse("HSERAMA"));
}

// TEST(programming_questions_test, reverse_word_wise)
// {
//     programming_questions pq;
//     string sent = "HOW ARE YOU";
//     EXPECT_EQ("YOU ARE HOW", pq.reverse_word_wise(sent));
// }