#include "Queen.h"

// Basic constructor for the Queen subclass.
Queen::Queen(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'q';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

// Given a destination square, this function checks that the path is free
// Returns 1 if path is free.
bool Queen::checkPath(int destination, bool activeArray[64]){
	int dir = direction(destination);
	if (dir%2 == 0) {
		if (checkStraight(destination, activeArray) == -1) {
			return 1;
		}
	} else {
		if (checkDiagonal(destination, activeArray) == -1) {
			return 1;
		}
	}
	return 0;
}

// Checks validity of move, returns 0 if invalid.
bool Queen::move(int square, bool activeArray[64]){
	int currentLocation = location;
  // Illegal if moving to current position
  if (currentLocation == square) {
    return 0;
  }

  // Move OK if piece is moving to same row or col OR moving diagonally
  // AND path is free
  if (  ((row(currentLocation) == row(square)
        || col(currentLocation) == col(square))
        || (abs(row(square)-row(location)) == abs(col(square)-col(location))))
      && checkPath(square, activeArray)){
    location = square;
    hasMoved = 1;
    return 1;
  }
	return 0;
}

// Basic destructor for the Queen subclass.
Queen::~Queen(){
  
}
