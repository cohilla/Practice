// ---------
// Transform.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/all_of/

#include <algorithm>  // all_of
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <algorithm>    // std::transform
#include <vector>       // std::vector

#include "gtest/gtest.h"

#include "Transform.h"

using namespace std;
using namespace testing;

using Transform_List_Signature = function<vector<int>::iterator (list<int>::iterator, list<int>::iterator, vector<int>::iterator, function<int (int)>)>;

struct Transform_List_Fixture : TestWithParam<Transform_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Transform_List_Instantiation,
    Transform_List_Fixture,
    Values(
           transform<list<int>::iterator, vector<int>::iterator, function<int (int)>>,
        my_transform<list<int>::iterator, vector<int>::iterator, function<int (int)>>));

TEST_P(Transform_List_Fixture, test_1) {
    list<int> x = {3, 6, 7};
    int i = 1;
    vector<int> y(3);
    list<int> z = {4, 7, 8};
    vector<int>::iterator p = GetParam()(x.begin(), x.end(), y.begin(), [i] (int j) -> int {return i + j;});
    ASSERT_TRUE(equal(p, ++++++p, z.begin()));
}

TEST_P(Transform_List_Fixture, test_2) {
    list<int> x = {3, 6, 7};
    int i = 1;
    vector<int> y(3);
    list<int> z = {4, 7, 8};
    GetParam()(x.begin(), x.end(), y.begin(), [i] (int j) -> int {return i + j;});
    ASSERT_TRUE(equal(y.begin(), y.end(), z.begin()));
}

/*
% g++ -pedantic -std=c++11 -Wall Transform.c++ -o Transform -lgtest_main



% Transform
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Transform_List_Instantiation/Transform_List_Fixture
[ RUN      ] Transform_List_Instantiation/Transform_List_Fixture.test_1/0
[       OK ] Transform_List_Instantiation/Transform_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Transform_List_Instantiation/Transform_List_Fixture.test_1/1
[       OK ] Transform_List_Instantiation/Transform_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Transform_List_Instantiation/Transform_List_Fixture.test_2/0
[       OK ] Transform_List_Instantiation/Transform_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Transform_List_Instantiation/Transform_List_Fixture.test_2/1
[       OK ] Transform_List_Instantiation/Transform_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Transform_List_Instantiation/Transform_List_Fixture (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 4 tests.
*/
