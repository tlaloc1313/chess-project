int row(int location) {

  int row = position%8;

  return row;
}


int col(int location) {
  double a = position/8;

  int col = floor(a);

  return col;
}
