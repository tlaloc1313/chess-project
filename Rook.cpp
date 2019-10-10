#include "Rook.h"

Rook::Rook(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'r';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Rook::move(int square, bool activeArray[64]){
  int currentLocation = location;
  //Illegal if moving to current position
  if (currentLocation == square){
    return 0;
  }

  //Move OK if piece is moving to same row or col and path is empty
  if ((row(currentLocation) == row(square) || col(currentLocation) == col(square)) && checkStraight(square, activeArray) == -1){
    location = square;
    return 1;
  }

	return 0;
}

Rook::~Rook(){

}
