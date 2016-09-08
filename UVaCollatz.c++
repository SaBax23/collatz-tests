// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints from r into i an j
 * @param r an istream
 * @param i an int
 * @param j an int
 * @return true if the read is successful, otherwise false
 */
bool collatz_read(istream &r, int &i, int &j);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval(int i, int j);

// -------------
// collatz_print
// -------------

/**
 * print three ints to w
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print(ostream &w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve(istream &r, ostream &w);

#endif // Collatz_h
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

#define ENABLE_OPTIMIZATION
int cycles[1000000] = {0};
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
// check_cache
// ------------

int check_cache (int n) {
  int c = 1;
  int val = n;
  while (n > 1) {
    //printf("%d\n", cycles[n]);
    if (n < 1000000 && cycles[n] != 0){
	cycles[val] = c - 1 + cycles[n];
	return cycles[val];
    }
    else if ((n % 2) == 0)
      n = (n / 2);
    else
      n = (3 * n) + 1;
    ++c;
  }
  cycles[val] = c;
  return c;
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
  int thisLen;
  for (; lower <= upper; lower++) {
  	#ifdef ENABLE_OPTIMIZATION
    		thisLen = check_cache(lower);
    	#else
    		thisLen = cycle_length(lower);
    	#endif
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
// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout


// ----
// main
// ----

int main() {
  using namespace std;
  collatz_solve(cin, cout);
  return 0;
}
