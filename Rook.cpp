#include "Pieces.h"
#include "position.cpp"

Rook::Rook(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'r';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Rook::checkPath(int destination){
	int direction = dir(destination);
}

bool Rook::move(int square){
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
