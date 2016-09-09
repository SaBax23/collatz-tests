// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(999999, 999998);
  ASSERT_EQ(259, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(200, 100);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(285000, 287000);
  ASSERT_EQ(376, v);
}

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(1, 100000);
  ASSERT_EQ(351, v);
}
TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(999200, 999999);
  ASSERT_EQ(396, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(303000, 305000);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(2000, 1);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(67000, 68000);
  ASSERT_EQ(312, v);
}
// ----
// cycle_length
// ----

TEST(CollatzFixture, cycle_length_1) {
  const int v = cycle_length(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_length_2) {
  const int v = cycle_length(789126);
  ASSERT_EQ(88, v);
}

// ----
// check_cache
// ----

TEST(CollatzFixture, check_cache_1) {
  const int v = check_cache(5600);
  ASSERT_EQ(86, v);
}

TEST(CollatzFixture, check_cache_2) {
  const int v = check_cache(990734);
  ASSERT_EQ(166, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}
