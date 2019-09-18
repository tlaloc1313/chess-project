#include "Pieces.h"

Queen::Queen(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Queen";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Queen::move(int square){

}

Queen::~Queen(){

}
