#include "Piece.h"

//Basic piece constructor allows for creation of empty Piece objects.
Piece::Piece(){
	pieceType = '?';
	enPassantPossible = 0;
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
//If there is a piece at destination, that square+100 is returned
int Piece::checkStraight(int destination, bool activeArray[64]) {
	int dir = direction(destination);

	int e,n,w,s;

	switch (dir) {
		case 0: //East
			for (e = location+8; e < destination; e+=8) {
				if (activeArray[e] == 1) {
					return e;
				}
			}
			break;
		case 2: //North
			for (n = location+1; n < destination; n++) {
				if (activeArray[n] == 1) {
					return n;
				}
			}
			break;
		case 4: //West
			for (w = location-8; w > destination; w-=8) {
				if (activeArray[w] == 1) {
					return w;
				}
			}
			break;
		case 6: //South
			for (s = location-1; s > destination; s--) {
				if (activeArray[s] == 1) {
					return s;
				}
			}
			break;
	}

	if (activeArray[destination] == 1) {
		return destination + 100;
	}

	return -1;
}

//Iterates along the direction to be moved, if a piece is found, the square is returned, otherwise returns -1
//If there is a piece at destination, that square+100 is returned
int Piece::checkDiagonal(int destination, bool activeArray[64]) {
	int dir = direction(destination);

	switch (dir) {
		case 1: //North East
			for (int ne = location+9; ne < destination; ne+=9) {
				if (activeArray[ne] == 1) {
					return ne;
				}
			}
			break;
		case 3: //North West
			for (int nw = location-7; nw > destination; nw-=7) {
				if (activeArray[nw] == 1) {
					return nw;
				}
			}
			break;
		case 5: //South West
			for (int sw = location-9; sw > destination; sw-=9) {
				if (activeArray[sw] == 1) {
					return sw;
				}
			}
			break;
		case 7: //South East
			for (int se = location+7; se < destination; se+=7) {
				if (activeArray[se] == 1) {
					return se;
				}
			}
			break;
	}

	if (activeArray[destination] == 1) {
		return destination + 100;
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

//Normal pieces can't be taken en passant
int Piece::checkEnPassant(){
	return -1;
}

//Basic destructor for Piece objects.
Piece::~Piece(){

}
