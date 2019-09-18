#include "Board.h"

Board::Board(){
  activeArray = {};
};

bool Board::spaceOccupied(int space){
  if (activeArray[space] == 0){
    return 0;
  }
  return 1;
}

int Board::movePiece(int startSpace, int endSpace){
  if (activeArray[startSpace] == 0){ //Check a piece is at StartSpace
    return -2;
  }
  int spaceWasOccupied = activeArray[endSpace]; //Checks the endSpace
  success = pieceArray.move(endSpace);
  if (success == 1){
    activeArray[startSpace] = 0;

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

int Board::addPiece(char type, int startSpace, int isWhite){
  if (activeArray[startSpace] == 0){
    return -1;
  }
  activearray[startSpace] = 1;
  switch (type){
    case 'b':
      pieceArray[startSpace] = Bishop(startSpace, isWhite);
    case 'n':
      pieceArray[startSpace] = Knight(startSpace, isWhite);
    case 'p':
      pieceArray[startSpace] = Pawn(startSpace, isWhite);
    case 'k':
      pieceArray[startSpace] = King(startSpace, isWhite);
    case 'q':
      pieceArray[startSpace] = Queen(startSpace, isWhite);
    case 'r':
      pieceArray[startSpace] = Rook(startSpace, isWhite);
  }
}

//Gets the unicode chess piece for a given square
char Board::getPiece(int space){
  char type = pieceArray[space].getType();
  bool isWhite = pieceArray[space].getIsWhite();

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


Board::~Board(){

}
