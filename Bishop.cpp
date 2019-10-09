#include "Pieces.h"
#include <cmath>

Bishop::Bishop(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'b';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Bishop::move(int square, bool activeArray[64]){
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  if (square == location){
    return 0;
  }
  //Honestly haven't thought enough about if this will work or not
  if ((abs(toRow-fromRow) == abs(toCol-fromCol)) && checkDiagonal(square, activeArray)){
    return 1;
  }
  else{
    return 0;
  }

}

Bishop::~Bishop(){

}
