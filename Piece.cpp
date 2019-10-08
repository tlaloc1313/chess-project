#include "Pieces.h"
#include <iostream>
#include <cmath>

Piece::Piece(){
  std::cout<<"Created Piece\n";
}

//Returns the direction the piece will move in from 0-7, anticlockwise from the positive horizontal
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

bool Piece::checkPath(int destination, bool activeArray[64]){

}

bool Piece::move(int square, bool activeArray[64]){

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
