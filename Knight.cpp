#include "Knight.h"

//Basic constructor for Knight subclass.
Knight::Knight(int startingSquare, int pieceIsWhite){
  location = startingSquare;
  pieceType = 'n';
  isWhite = pieceIsWhite;
  hasMoved = 0;
}

//Given a destination square, this function checks if the piece is capable of moving
//and returns 1 if it is a legal move. Returns 0 if not.
bool Knight::move(int square, bool activeArray[64]){
  int currentPos = location;
  int dist = abs(currentPos - square);

  //Check move is legal
  if (dist == 6 || dist == 10 || dist == 15 || dist == 17){
    //Move is illegal if it involves going off the edge of the board
    if (row(currentPos)<2 && row(square)>5){
      return 0;
    }
    if (row(currentPos)>5 && row(square)<2){
      return 0;
    }
    if (col(currentPos)<2 && col(square)>5){
      return 0;
    }
    if (col(currentPos)>5 && col(square)<2){
      return 0;
    }

    //Move piece and return 1
    location = square;
    hasMoved = 1;
    return 1;
  }
	return 0;
}
//+10, +6, -6, -10, -15, -17, +15, +17

//Basic destructor for Knight subclass.
Knight::~Knight(){

}
