// ---------
// Count.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/Count/

#include <algorithm>  // Count
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <numeric>    

#include "gtest/gtest.h"

#include "Count.h"

using namespace std;
using namespace testing;

using Count_List_Signature = function<int (list<int>::iterator, list<int>::iterator, const int&)>;

struct Count_List_Fixture : TestWithParam<Count_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Count_List_Instantiation,
    Count_List_Fixture,
    Values(
           count<list<int>::iterator, int>,
        my_count<list<int>::iterator, int>));

TEST_P(Count_List_Fixture, test_1) {
    list<int> x = {3, 5, 7};
    int v = 3;
    ASSERT_TRUE(GetParam()(x.begin(), x.end(), v) == 1);}

TEST_P(Count_List_Fixture, test_2) {
    list<int> x = {3, 3, 3};
    int v = 3;
    ASSERT_TRUE(GetParam()(x.begin(), x.end(), v) == 3);}

/*

% g++ -pedantic -std=c++11 -Wall Count.c++ -o Count -lgtest -lgtest_main -pthread



chill@razzles:~/Documents/Practice/C++$ Acc 
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Count_List_Instantiation/Count_List_Fixture
[ RUN      ] Count_List_Instantiation/Count_List_Fixture.test_1/0
[       OK ] Count_List_Instantiation/Count_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Count_List_Instantiation/Count_List_Fixture.test_1/1
[       OK ] Count_List_Instantiation/Count_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Count_List_Instantiation/Count_List_Fixture.test_2/0
[       OK ] Count_List_Instantiation/Count_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Count_List_Instantiation/Count_List_Fixture.test_2/1
[       OK ] Count_List_Instantiation/Count_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Count_List_Instantiation/Count_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.

*/
