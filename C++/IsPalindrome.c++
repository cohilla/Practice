// --------
// IsPalindrome.c++
// --------

#include <algorithm>  // all_of, fill, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <forward_list>

#include "gtest/gtest.h"

#include "IsPalindrome.h"

using namespace std;
using namespace testing;


TEST(IsPalindrome_List_Fixture, test) {
    list<int> x = {1, 2, 3, 4, 5};
    ASSERT_FALSE(is_palindrome(x.begin(), x.end()));
}

TEST(IsPalindrome_List_Fixture, test1) {
    list<int> x = {1, 2, 3, 4, 4, 3, 2, 1};
    ASSERT_TRUE(is_palindrome(x.begin(), x.end()));
}

TEST(IsPalindrome_List_Fixture, test3) {
    list<int> x = {1, 2, 3, 4, 4, 3, 2, 1};
    ASSERT_TRUE(is_palindrome(x.begin(), x.end()));
}

/*

*/