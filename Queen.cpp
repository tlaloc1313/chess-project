#include "Pieces.h"

Queen::Queen(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'q';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Queen::checkPath(int destination, bool activeArray[64]){
	int dir = direction(destination);

	switch (dir) {
		case 0:
			for (int i = location+8; i < destination; i+=8) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 2:
			for (int i = location+1; i < destination; i++) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 4:
			for (int i = location-8; i > destination; i-=8) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 6:
			for (int i = location-1; i > destination; i--) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 1:
			for (int i = location+9; i < destination; i+=9) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 3:
			for (int i = location-7; i > destination; i-=7) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 5:
			for (int i = location-9; i > destination; i-=9) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
		case 7:
			for (int i = location+7; i < destination; i+=7) {
				if (activeArray[i] == 1) {
					return 0;
				}
			}
			break;
	}
	return 1;
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
