// --------
// Reverse.c++
// --------

#include <algorithm>  // all_of, fill, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list

#include "gtest/gtest.h"

#include "Reverse.h"

using namespace std;
using namespace testing;

using Reverse_List_Signature = function<void (list<int>::iterator, list<int>::iterator)>;

struct Reverse_List_Fixture : TestWithParam<Reverse_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Reverse_List_Instantiation,
    Reverse_List_Fixture,
    Values(
           reverse<list<int>::iterator>,
        my_reverse<list<int>::iterator>));

TEST_P(Reverse_List_Fixture, test) {
    list<int> x = {1, 2, 3, 4, 5};
    list<int> y = {5, 4, 3, 2, 1};

    GetParam()(x.begin(), x.end());
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
  }

  TEST_P(Reverse_List_Fixture, test1) {
    list<int> x = {1, 2, 3, 4};
    list<int> y = {4, 3, 2, 1};

    GetParam()(x.begin(), x.end());
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));
  }


/*

*/