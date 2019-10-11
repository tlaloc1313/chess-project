#include "Rook.h"

//Basic constructor for the Rook subclass.
Rook::Rook(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'r';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

//Given a destination square, this function checks if the piece is capable of moving
//and returns 1 if it is a legal move. Returns 0 if not.
bool Rook::move(int square, bool activeArray[64]){
  int currentLocation = location;
  //Illegal if moving to current position
  if (currentLocation == square){
    return 0;
  }

  //Move OK if piece is moving to same row or col and path is empty
  if ((row(currentLocation) == row(square) || col(currentLocation) == col(square)) && checkStraight(square, activeArray) == -1){
    location = square;
    hasMoved = 1;
    return 1;
  }

	return 0;
}

//Given a destination square, the rook attempts to castle. Returns 0 on success.
int Rook::castle(int square){
  if (hasMoved == 0){
    location = square;
    hasMoved = 1;
    return 0;
  }
  return -1;
}

//Basic destructor for the Rook subclass.
Rook::~Rook(){

}
