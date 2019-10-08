#include "Pieces.h"
#include <iostream>

using std::cout;
using std::cin;

extern int inputFunc();

int main(int argc, char const *argv[]) {
  bool activeArray[64]={1};
  cout<<"Making a Bishop. What square? ";
  Bishop b1 = Bishop(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b1.move(inputFunc(), activeArray)<<"\n";
  cout<<"Making a Knight. What square? ";
  Knight b2 = Knight(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b2.move(inputFunc(), activeArray)<<"\n";
  cout<<"Making a White Pawn. a3 is taken. What Square?";
  activeArray[2]=1;
  Pawn b3 = Pawn(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b3.move(inputFunc(), activeArray)<<"\n";
  cout<<"Making a King. What square? ";
  King b4 = King(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b4.move(inputFunc(), activeArray)<<"\n";
  cout<<"Making a Rook. What square? ";
  Rook b5 = Rook(inputFunc(), 1);
  cout<<"Where to move it?";
  cout<<b5.move(inputFunc(), activeArray)<<"\n";
  return 0;
}
