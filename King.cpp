#include "King.h"

//Basic constructor for King subclass.
King::King(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'k';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

//Given a destination square, this function checks if the piece is capable of moving
//and returns 1 if it is a legal move. Returns 0 if not.
bool King::move(int square, bool activeArray[64]){
  //Decoding square numbers:
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  // Same square check
  if (square==location){
    return 0;
  }

  // The king can move 1 square in any direction
  if ( abs(fromRow-toRow)<2 && abs(fromCol-toCol)<2 ){
    location = square;
    hasMoved = 1;
    return 1;
  }
  return 0;
}

// Given a destination square, the king is forced to castle.
void King::castle(int square){
  if (hasMoved == 0){
    location = square;
    hasMoved = 1;
  }
  return;
}

// Basic destructor for King subclass.
King::~King(){
}
