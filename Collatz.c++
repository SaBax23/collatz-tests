// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read(istream &r, int &i, int &j) {
  if (!(r >> i))
    return false;
  r >> j;
  return true;
}

// ------------
// cycle_length
// ------------

int cycle_length(int n) {
  int c = 1;
  while (n > 1) {
    if ((n % 2) == 0)
      n = (n / 2);
    else
      n = (3 * n) + 1;
    ++c;
  }
  return c;
}

// ------------
// collatz_eval
// ------------

int collatz_eval(int i, int j) {
  int maxLen = 0;
  int upper, lower;
  if (i >= j) {
    upper = i;
    lower = j;
  } else {
    upper = j;
    lower = i;
  }
  for (; lower <= upper; lower++) {
    int thisLen = cycle_length(lower);
    if (thisLen > maxLen) {
      maxLen = thisLen;
    }
  }
  return maxLen;
}

// -------------
// collatz_print
// -------------

void collatz_print(ostream &w, int i, int j, int v) {
  w << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve(istream &r, ostream &w) {
  int i;
  int j;
  while (collatz_read(r, i, j)) {
    const int v = collatz_eval(i, j);
    collatz_print(w, i, j, v);
  }
}
