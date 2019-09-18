#include "Pieces.h"

Bishop::Bishop(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Bishop";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Bishop::move(int square){

}

Bishop::~Bishop(){

}
