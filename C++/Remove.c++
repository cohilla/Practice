// ---------
// Remove.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/Remove/

#include <algorithm>  // Remove
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <numeric>    

#include "gtest/gtest.h"

#include "Remove.h"

using namespace std;
using namespace testing;

using Remove_List_Signature = function<list<int>::iterator (list<int>::iterator, list<int>::iterator, const int&)>;

struct Remove_List_Fixture : TestWithParam<Remove_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Remove_List_Instantiation,
    Remove_List_Fixture,
    Values(
           remove<list<int>::iterator, int>,
        my_remove<list<int>::iterator, int>));

TEST_P(Remove_List_Fixture, test_1) {
    list<int> x = {3, 5, 7};
    list<int> y = {5, 7};
    int v = 3;
    list<int>::iterator p = GetParam()(x.begin(), x.end(), v);

    ASSERT_TRUE(equal(p, ++++p, y.begin()));}

TEST_P(Remove_List_Fixture, test_2) {
    list<int> x = {3, 5, 7};
    list<int> y = {3, 5};
    int v = 7;
    list<int>::iterator p = GetParam()(x.begin(), x.end(), v);

    ASSERT_TRUE(equal(p, ++++p, y.begin()));}

/*

% g++ -pedantic -std=c++11 -Wall Remove.c++ -o Remove -lgtest -lgtest_main -pthread



chill@razzles:~/Documents/Practice/C++$ Acc 
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Remove_List_Instantiation/Remove_List_Fixture
[ RUN      ] Remove_List_Instantiation/Remove_List_Fixture.test_1/0
[       OK ] Remove_List_Instantiation/Remove_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Remove_List_Instantiation/Remove_List_Fixture.test_1/1
[       OK ] Remove_List_Instantiation/Remove_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Remove_List_Instantiation/Remove_List_Fixture.test_2/0
[       OK ] Remove_List_Instantiation/Remove_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Remove_List_Instantiation/Remove_List_Fixture.test_2/1
[       OK ] Remove_List_Instantiation/Remove_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Remove_List_Instantiation/Remove_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.

*/
