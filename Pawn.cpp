#include "Pawn.h"
#include <iostream>

//Constructor
Pawn::Pawn(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'p';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

//This function checks that a given move is legal
bool Pawn::move(int square, bool activeArray[64]){
  //Can't move to same square
  if (square == location){
    return 0;
  }

  //Decoding the square numbers to useable values
  int fromRow = row(location);
  int fromCol = col(location);
  int toRow = row(square);
  int toCol = col(square);

  enPassantPossible = 0; //By default, en passant is impossible

  //Same-column movement only, when not taking another piece
  if (fromCol == toCol && activeArray[square]==0){

    //Pawn behaves differently by colour
    switch(isWhite){
      case 1: //Piece is White

      //Move up to two squares forward if first move for the piece
      if (fromRow == 1){
          if ((toRow-fromRow)==2){
            if (activeArray[square-1]==0){ //Checks that intermediate square is empty
              location = square;
              hasMoved = 1;
              enPassantPossible = 1;
              return 1;
            }
          }
          if ((toRow-fromRow)==1){
            location = square;
            hasMoved = 1;
            return 1;
          }
        } else {
          if ( (toRow-fromRow)==1){
            location = square;
            hasMoved = 1;
            return 1;
          }
      }
      break;

      case 0: //Piece is Black
      //Move up to two if first move for the piece
      if (fromRow == 6){
          if ((toRow-fromRow)==-2){
            if (activeArray[square+1]==0){ //Checks that intermediate square is empty
              location = square;
              hasMoved = 1;
              enPassantPossible = 1;
              return 1;
            }
          }
          if ((toRow-fromRow)==-1){
            location = square;
            hasMoved = 1;
            return 1;
          }
        } else {
          if ( (toRow-fromRow)==-1){
            location = square;
            hasMoved = 1;
            return 1;
          }
      }
    }
  }

//The pawn has unique behaviour only when taking another piece
  if (abs(fromCol-toCol)==1 && activeArray[square]==1){
    if (isWhite){
      if (toRow-fromRow==1){ //Checks for a diagonal move forwards
        location = square;
        hasMoved = 1;
        return 1;
      }
    } else {
      if ( toRow-fromRow==-1 ){ //Checks for a diagonal move backwards
        location = square;
        hasMoved = 1;
        return 1;
      }
    }
  }

  //If all tests fail, return 0
  return 0;
}

int Pawn::checkEnPassant(){
	return enPassantPossible;
}

//Generic Destructor
Pawn::~Pawn(){

}
