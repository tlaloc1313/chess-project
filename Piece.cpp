#include "Pieces.h"
#include <iostream>
#include <cmath>

Piece::Piece(){
  std::cout<<"Created Piece\n";
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
