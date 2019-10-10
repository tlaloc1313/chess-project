#include "Piece.h"

Piece::Piece(){
	pieceType = '?';
}

//Returns the direction the piece will move in from 0-7, anticlockwise from east
int Piece::direction(int destination){
	int dir;

	if (col(location) < col(destination)) {
		if (row(location) < row(destination)) {
			dir = 1;
		} else if (row(location) > row(destination)) {
			dir = 7;
		} else {
			dir = 0;
		}
	} else if (col(location) > col(destination)) {
		if (row(location) < row(destination)) {
			dir = 3;
		} else if (row(location) > row(destination)) {
			dir = 5;
		} else {
			dir = 4;
		}
	} else {
		if (row(location) < row(destination)) {
			dir = 2;
		} else {
			dir = 6;
		}
	}
	return dir;
}

//Iterates along the direction to be moved, if a piece is found, the square is returned, otherwise returns -1
int Piece::checkStraight(int destination, bool activeArray[64]) {
	int dir = direction(destination);

	switch (dir) {
		case 0:
			for (int i = location+8; i < destination; i+=8) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 2:
			for (int i = location+1; i < destination; i++) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 4:
			for (int i = location-8; i > destination; i-=8) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 6:
			for (int i = location-1; i > destination; i--) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
	}
	return -1;
}

int Piece::checkDiagonal(int destination, bool activeArray[64]) {
	int dir = direction(destination);

	switch (dir) {
		case 1:
			for (int i = location+9; i < destination; i+=9) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 3:
			for (int i = location-7; i > destination; i-=7) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 5:
			for (int i = location-9; i > destination; i-=9) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 7:
			for (int i = location+7; i < destination; i+=7) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
	}
	return -1;
}

bool Piece::checkPath(int destination, bool activeArray[64]){
  return 0;
}

bool Piece::move(int square, bool activeArray[64]){
  return 0;
}

int Piece::getPosition(){
  return location;
}

char Piece::getType(){
  return pieceType;
}

bool Piece::getIsWhite(){
  return isWhite;
}

Piece::~Piece(){

}
