// ---------
// accumulate.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/accumulate/

#include <algorithm>  // accumulate
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <numeric>      // std::accumulate

#include "gtest/gtest.h"

#include "Accumulate.h"

using namespace std;
using namespace testing;

using Accumulate_List_Signature = function<int (list<int>::iterator, list<int>::iterator, const int&, function<int (int, int)>)>;

struct Accumulate_List_Fixture : TestWithParam<Accumulate_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Accumulate_List_Instantiation,
    Accumulate_List_Fixture,
    Values(
           accumulate<list<int>::iterator, int, function<int (int, int)>>,
        my_accumulate<list<int>::iterator, int, function<int (int, int)>>));

TEST_P(Accumulate_List_Fixture, test_1) {
    list<int> x = {3, 5, 7};
    ASSERT_TRUE(GetParam()(x.begin(), x.end(), 0, [] (int i, int j) -> int {return (i + j);}) == 15);}

TEST_P(Accumulate_List_Fixture, test_2) {
    list<int> x = {3, 6, 7};
    ASSERT_FALSE(GetParam()(x.begin(), x.end(), 0, [] (int i, int j) -> int {return (i + j);}) == 2);}

/*

% g++ -pedantic -std=c++11 -Wall Count.c++ -o Count -lgtest -lgtest_main -pthread



chill@razzles:~/Documents/Practice/C++$ Acc 
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Accumulate_List_Instantiation/Accumulate_List_Fixture
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/0
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/1
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/0
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/1
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Accumulate_List_Instantiation/Accumulate_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.

*/
