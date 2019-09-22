#include "Pieces.h"
#include <cmath>

Pawn::Pawn(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'p';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}


bool Pawn::move(int square){
  //Can't move to same square
  if (square == location){
    return 0;
  }

  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  //Same-column movement only
  if (fromCol == toCol){
    //Move up to two if first move for the piece
    switch (hasMoved){
      case 0:
        if ( (toRow-fromRow)<3 ){
          return 1;
        }
        break;
      case 1:
        if ( (toRow-fromRow)==1){
          return 1;
        }
    }
  }
  else{
    return 0;
  }

}



Pawn::~Pawn(){

}
