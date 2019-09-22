#include "Pieces.h"

King::King(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'k';
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool King::move(int square){
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  //Same square check
  if (square=location){
    return 0;
  }

  //King can move 1 square in any direction
  if ( abs(fromRow-toRow)<2 && abs(fromCol-toCol<2) ){
    return 1;
  }

}

King::~King(){

}
