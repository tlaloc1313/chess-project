#include "King.h"

King::King(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'k';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool King::move(int square, bool activeArray[64]){
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  //Same square check
  if (square==location){
    return 0;
  }

  //King can move 1 square in any direction
  if ( abs(fromRow-toRow)<2 && abs(fromCol-toCol)<2 ){
    return 1;
  }
  return 0;
}

King::~King(){

}
