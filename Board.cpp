#include "Board.h"
#include <iostream>

//Basic constructor, needs no arguments
Board::Board(){
  activeArray;
  for (int i=0; i<64; i++){
    activeArray[i]=0;
  }
};

//Checks if a space on the board is occupied
bool Board::spaceOccupied(int space){
  if (activeArray[space] == 0){
    return 0;
  }
  return 1;
}

//See Board.h for description.
int Board::movePiece(int startSpace, int endSpace){
  if (activeArray[startSpace] == 0){ //Check a piece exists at StartSpace
    return -2;
  }
  int spaceWasOccupied = activeArray[endSpace]; //Checks the endSpace
  int success = pieceArray[startSpace]->move(endSpace);
  if (success == 1){
    activeArray[startSpace] = 0; //Clears the startSpace since the piece is moving
    activeArray[endSpace] = 1; //Marks the endSpace as taken
    pieceArray[endSpace] = pieceArray[startSpace]; //Copies the pointer to the piece within the array

    if (spaceWasOccupied == 1){//If a piece is being taken
      delete pieceArray[endSpace];
      return 2;
    }
    //If a piece is being moved
    return 1;
  }
  //If the move was illegal
  return -1;
}

//Adds a piece to the board, given the necessary attributes. Returnss -1 on failure.
int Board::addPiece(char type, int startSpace, int isWhite){
  if (activeArray[startSpace] == 1){ //If the space is taken
    return -1;
  }
  activeArray[startSpace] = 1;
  switch (type){
    case 'b':
      pieceArray[startSpace] = new Bishop(startSpace, isWhite);
    case 'n':
      pieceArray[startSpace] = new Knight(startSpace, isWhite);
    case 'p':
      pieceArray[startSpace] = new Pawn(startSpace, isWhite);
    case 'k':
      pieceArray[startSpace] = new King(startSpace, isWhite);
    case 'q':
      pieceArray[startSpace] = new Queen(startSpace, isWhite);
    case 'r':
      pieceArray[startSpace] = new Rook(startSpace, isWhite);
  }
}

//Gets the unicode chess piece for a given square
char Board::getPiece(int space){
  char type = pieceArray[space]->getType();
  bool isWhite = pieceArray[space]->getIsWhite();

  if (isWhite == 1){
    //White Pieces
    switch (type) {
      case 'p':
      return '\u2659';
      case 'r':
      return '\u2656';
      case 'b':
      return '\u2657';
      case 'n':
      return '\u2658';
      case 'k':
      return '\u2654';
      case 'q':
      return '\u2655';
    }
  } else {
    //Black Pieces
    switch (type) {
      case 'p':
      return '\u265F';
      case 'r':
      return '\u265C';
      case 'b':
      return '\u265D';
      case 'n':
      return '\u265E';
      case 'k':
      return '\u265A';
      case 'q':
      return '\u265B';
    }
  }
}

//Destructor has no specific behaviour
Board::~Board(){

}
