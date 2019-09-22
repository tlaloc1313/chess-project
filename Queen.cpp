#include "Pieces.h"

Queen::Queen(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'q';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Queen::move(int square){

}

Queen::~Queen(){

}
