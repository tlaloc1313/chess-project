#include "Pieces.h"
#include <iostream>
#include <cmath>

Piece::Piece(){
  std::cout<<"Created Piece\n";
}

int Piece::dir(int destination){
	int direction;
	if (col(location) < col(destination)) {
		direction = 0;
	} else if (row(location) < row(destination)) {
		direction = 2;
	} else if (col(location) > col(destination)) {
		destination = 4;
	} else if (row(location) > row(destination)){
		destination = 6;
	}
}

bool Piece::move(int square){

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
