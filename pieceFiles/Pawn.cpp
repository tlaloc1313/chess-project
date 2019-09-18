#include "Pieces.h"

Pawn::Pawn(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Pawn";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Pawn::move(int square){

}

Pawn::~Pawn(){

}
