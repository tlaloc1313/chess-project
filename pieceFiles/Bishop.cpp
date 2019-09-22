#include "Pieces.h"
#include <math.h>

Bishop::Bishop(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  type = "Bishop";
  isActive = 1;
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

bool Bishop::move(int square){
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  if (square == location){
    return 0;
  }
  //Honestly haven't thought enough about if this will work or not
  if ( abs(toRow-fromRow) == abs(toCol-fromCol) ){
    return 1;
  }
  else{
    return 0;
  }

}

Bishop::~Bishop(){

}
