#include "Pieces.h"
#include <iostream>

using std::cout;
using std::cin;

extern int inputFunc();

int main(int argc, char const *argv[]) {
  cout<<"Making a bishop. What square? ";
  Bishop b1 = Bishop(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b1.move(inputFunc())<<"\n";
  cout<<"Making a Knight. What square? ";
  Knight b2 = Knight(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b2.move(inputFunc())<<"\n";
  cout<<"Making a Pawn. What square? ";
  Pawn b3 = Pawn(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b3.move(inputFunc())<<"\n";
  return 0;
}
