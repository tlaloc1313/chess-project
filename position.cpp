#include <cmath>

int row(int location) {

  int row = location%8;

  return row;
}


int col(int location) {
  double a = location/8;

  int col = floor(a);

  return col;
}
