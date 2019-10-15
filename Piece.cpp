#include "Piece.h"

// Basic piece constructor allows for creation of empty Piece objects.
Piece::Piece(){
	pieceType = '?';
	enPassantPossible = 0;
}

// Returns the direction the piece will move in from 0-7, anticlockwise from east
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

// Iterates along the direction to be moved, if a piece is found, the square is
// returned, otherwise returns -1
int Piece::checkStraight(int destination, bool activeArray[64]) {
	int dir = direction(destination);

	int east, north, west, south;

	switch (dir) {
		case 0: //East
			for (east = location+8; east < destination; east+=8) {
				if (activeArray[east] == 1) {
					return east;
				}
			}
			break;
		case 2: //North
			for (north = location+1; north < destination; north++) {
				if (activeArray[north] == 1) {
					return north;
				}
			}
			break;
		case 4: //West
			for (west = location-8; west > destination; west-=8) {
				if (activeArray[west] == 1) {
					return west;
				}
			}
			break;
		case 6: //South
			for (south = location-1; south > destination; south--) {
				if (activeArray[south] == 1) {
					return south;
				}
			}
			break;
	}

	//If there are no pieces found
	return -1;
}

// Iterates along the direction to be moved, if a piece is found, the square is
// returned, otherwise returns -1
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

	//If there are no pieces found
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

//Normal pieces don't castle
void Piece::castle(int square){
	return;
}

//Normal pieces can't be taken en passant
int Piece::checkEnPassant(){
	return -1;
}

//Basic destructor for Piece objects.
Piece::~Piece(){

}
