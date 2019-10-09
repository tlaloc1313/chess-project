#include "Queen.h"

Queen::Queen(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'q';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Queen::checkPath(int destination, bool activeArray[64]){
	int dir = direction(destination);

	if (dir%2 == 0) {
		return checkStraight(destination, activeArray);
	} else {
		return checkDiagonal(destination, activeArray);
	}
	return 0;
}

bool Queen::move(int square, bool activeArray[64]){
	int currentLocation = location;
  //Illegal if moving to current position
  if (currentLocation == square){
    return 0;
  }

  //Move OK if piece is moving to same row or col OR moving diagonally AND path is free
  if (((row(currentLocation) == row(square) || col(currentLocation) == col(square)) || (abs(row(square)-row(location)) == abs(col(square)-col(location)))) && checkPath(square, activeArray)){
    location = square;
    return 1;
  }

	return 0;
}

Queen::~Queen(){

}
