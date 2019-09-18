#include "Pieces.h"

Bishop::Bishop(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Bishop";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

Bishop::move(int square){

}

King::King(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "King";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}


Pawn::Pawn(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Pawn";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

Queen::Queen(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Queen";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}
