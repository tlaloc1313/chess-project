#include "Piece.h"

//Basic piece constructor allows for creation of empty Piece objects.
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
		case 0: //East
			for (int i = location+8; i < destination; i+=8) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 2: //North
			for (int i = location+1; i < destination; i++) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 4: //West
			for (int i = location-8; i > destination; i-=8) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 6: //South
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
		case 1: //North East
			for (int i = location+9; i < destination; i+=9) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 3: //North West
			for (int i = location-7; i > destination; i-=7) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 5: //South West
			for (int i = location-9; i > destination; i-=9) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
		case 7: //South East
			for (int i = location+7; i < destination; i+=7) {
				if (activeArray[i] == 1) {
					return i;
				}
			}
			break;
	}
	return -1;
}

//Placeholder functions to allow for initialisation of empty Piece objects.
bool Piece::checkPath(int destination, bool activeArray[64]){
  return 0;
}

bool Piece::move(int square, bool activeArray[64]){
  return 0;
}

//These functions return the required values for use by outside functions.
int Piece::getPosition(){
  return location;
}

char Piece::getType(){
  return pieceType;
}

bool Piece::getIsWhite(){
  return isWhite;
}

bool Piece::getHasMoved(){
	return hasMoved;
}

//Normal pieces can't castle
int Piece::castle(int square){
	return -1;
}

//Basic destructor for Piece objects.
Piece::~Piece(){

}
