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
      delete pieceArray[endSpace]
      return 2;
    }
    //If a piece is being moved
    return 1;
  }
  //If the move was illegal
  return -1;
}

Board::~Board(){

}
