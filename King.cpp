#include "Pieces.h"

King::King(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'k';
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool King::move(int square){

}

King::~King(){

}
