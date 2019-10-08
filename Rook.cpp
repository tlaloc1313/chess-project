#include "Pieces.h"

Rook::Rook(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'r';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

//Returns 0 if path is blocked, or 1 if path is free
bool Rook::checkPath(int destination, bool activeArray[64]){
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
	}
	return 1;
}

bool Rook::move(int square, bool activeArray[64]){
  int currentLocation = location;
  //Illegal if moving to current position
  if (currentLocation == square){
    return 0;
  }

  //Move OK if piece is moving to same row or col and path is empty
  if ((row(currentLocation) == row(square) || col(currentLocation) == col(square)) && checkPath(square, activeArray)){
    location = square;
    return 1;
  }

	return 0;
}

Rook::~Rook(){

}
