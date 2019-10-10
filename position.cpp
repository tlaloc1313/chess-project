#include <cmath>

// Given a square number on the board, returns the row (0-7) that square is on.
int row(int location) {

  int row = location%8;

  return row;
}

// Given a square number on the board, returns the column (0-7) that square is on.
int col(int location) {

  double a = location/8;
  int col = floor(a);

  return col;
}
