// ---------
// Find.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/Find/

#include <algorithm>  // Find
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <numeric>    

#include "gtest/gtest.h"

#include "Find.h"

using namespace std;
using namespace testing;

using Find_List_Signature = function<list<int>::iterator (list<int>::iterator, list<int>::iterator, const int&)>;

struct Find_List_Fixture : TestWithParam<Find_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Find_List_Instantiation,
    Find_List_Fixture,
    Values(
           find<list<int>::iterator, int>,
        my_find<list<int>::iterator, int>));

TEST_P(Find_List_Fixture, test_1) {
    list<int> x = {3, 5, 7};
    int v = 3;
    list<int>::iterator p = GetParam()(x.begin(), x.end(), v);

    ASSERT_TRUE(p == x.begin());}

TEST_P(Find_List_Fixture, test_2) {
    list<int> x = {3, 3, 3};
    int v = 4;
    list<int>::iterator p = GetParam()(x.begin(), x.end(), v);

    ASSERT_TRUE(p == x.end());}

TEST_P(Find_List_Fixture, test_3) {
    list<int> x = {3, 5, 7};
    int v = 7;
    list<int>::iterator p = GetParam()(x.begin(), x.end(), v);

    ASSERT_TRUE(p == ++++x.begin());}

/*

% g++ -pedantic -std=c++11 -Wall Find.c++ -o Find -lgtest -lgtest_main -pthread



chill@razzles:~/Documents/Practice/C++$ Acc 
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Find_List_Instantiation/Find_List_Fixture
[ RUN      ] Find_List_Instantiation/Find_List_Fixture.test_1/0
[       OK ] Find_List_Instantiation/Find_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Find_List_Instantiation/Find_List_Fixture.test_1/1
[       OK ] Find_List_Instantiation/Find_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Find_List_Instantiation/Find_List_Fixture.test_2/0
[       OK ] Find_List_Instantiation/Find_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Find_List_Instantiation/Find_List_Fixture.test_2/1
[       OK ] Find_List_Instantiation/Find_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Find_List_Instantiation/Find_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.

*/
