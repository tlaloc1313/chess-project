#include "Pieces.h"


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

  //Move OK if piece is moving to same row or col
  if (row(currentLocation) == row(square)){
    location = square;
    return 1;
  }

  if (col(currentLocation) == col(square)){
    location = square;
    return 1;
  }

}

Rook::~Rook(){

}
