#include "Bishop.h"

// Basic constructor for the Bishop subclass.
Bishop::Bishop(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'b';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

//Given a destination square, this function checks if the piece is capable of moving
//and returns 1 if it is a legal move. Returns 0 if not.
bool Bishop::move(int square, bool activeArray[64]){
  //Decoding square numbers:
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  //Pieces can't move to the square they are already on.
  if (square == location){
    return 0;
  }
  //Checks that the move is strictly diagonal, and uses 'checkDiagonal' to ensure that
  //no other pieces are in the way.
  if ((abs(toRow-fromRow) == abs(toCol-fromCol)) && checkDiagonal(square, activeArray) == -1){
		location = square;
    hasMoved = 1;
		return 1;
  }
  else{
    return 0;
  }
}

//Basic destructor for the Bishop subclass.
Bishop::~Bishop(){

}
