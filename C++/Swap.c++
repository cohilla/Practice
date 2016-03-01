// ---------
// Swap.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/all_of/

#include <algorithm>  // all_of
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <utility>      // std::swap

#include "gtest/gtest.h"

#include "Swap.h"

using namespace std;
using namespace testing;

using Swap_List_Signature = function<void (const int&, const int&)>;

struct Swap_List_Fixture : TestWithParam<Swap_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Swap_List_Instantiation,
    Swap_List_Fixture,
    Values(
           swap<int>,
        my_swap<int>));

TEST_P(Swap_List_Fixture, test_1) {
    int x = 2;
    int y = 3;
    GetParam()(x, y);
    ASSERT_TRUE(x == 3);
    ASSERT_TRUE(y == 2);
}


/*
% g++ -pedantic -std=c++11 -Wall Swap.c++ -o Swap -lgtest_main



% Swap
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Swap_List_Instantiation/Swap_List_Fixture
[ RUN      ] Swap_List_Instantiation/Swap_List_Fixture.test_1/0
[       OK ] Swap_List_Instantiation/Swap_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Swap_List_Instantiation/Swap_List_Fixture.test_1/1
[       OK ] Swap_List_Instantiation/Swap_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Swap_List_Instantiation/Swap_List_Fixture.test_2/0
[       OK ] Swap_List_Instantiation/Swap_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Swap_List_Instantiation/Swap_List_Fixture.test_2/1
[       OK ] Swap_List_Instantiation/Swap_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Swap_List_Instantiation/Swap_List_Fixture (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 4 tests.
*/
