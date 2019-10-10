#include "Board.h"
#include <iostream>
#include <string.h>

extern std::string encode(int code);

//Basic constructor, needs no arguments
Board::Board(){
  for (int i=0; i<64; i++){
    activeArray[i]=0;
  }
	for (int i = 0; i < 64; i++) {
		pieceArray[i] = new Piece();
	}
  moveNumber = 0;
};

//Checks if a space on the board is occupied
bool Board::spaceOccupied(int space){
  if (activeArray[space] == 0){
    return 0;
  }
  return 1;
}

//See Board.h for description.
int Board::movePiece(int startSpace, int endSpace, int whiteTurn){
  if (startSpace > 63){
    return -1;
  }

  //Check that a piece exists at StartSpace
  if (activeArray[startSpace] == 0){
    return -2;
  }

  //Allows white to only move white pieces, and black to only move black pieces.
  if (whiteTurn != pieceArray[startSpace]->getIsWhite()){
    return -2;
  }

  //It is illegal and illogical to take your own pieces:
  if ((activeArray[endSpace]==1)) {
    if ((pieceArray[endSpace]->getIsWhite() == pieceArray[startSpace]->getIsWhite())){
      return -1;
    }
  }
  int spaceWasOccupied = activeArray[endSpace]; //Checks the endSpace
  int success = pieceArray[startSpace]->move(endSpace, activeArray);
  if (success == 1){
    if (spaceWasOccupied == 1){//If a piece is being taken, deletes that piece
      delete pieceArray[endSpace];
    }
    activeArray[startSpace] = 0; //Clears the startSpace since the piece is moving
    activeArray[endSpace] = 1; //Marks the endSpace as taken
    pieceArray[endSpace] = pieceArray[startSpace]; //Copies the pointer to the piece within the array

    //PROMOTING A PAWN
    if (pieceArray[endSpace]->getType()=='p'&& (row(endSpace)==7 || row(endSpace)==0)){
      bool pawnWasWhite = pieceArray[endSpace]->getIsWhite();
      delete pieceArray[endSpace];
      char promotePiece;
      std::cout << "Please enter a letter corresponding to the piece you would like to promote to (q, r, n, b):" << '\n';
      std::cin >> promotePiece;
      switch (promotePiece){
        case 'b':
          pieceArray[endSpace] = new Bishop(endSpace, pawnWasWhite);
          break;
        case 'n':
          pieceArray[endSpace] = new Knight(endSpace, pawnWasWhite);
          break;
        case 'q':
          pieceArray[endSpace] = new Queen(endSpace, pawnWasWhite);
          break;
        case 'r':
          pieceArray[endSpace] = new Rook(endSpace, pawnWasWhite);
          break;
      }
    }

    //If a piece is being moved, adds the move to the history arrays.
    pastPieces.push_back(pieceArray[endSpace]->getType());
    pastMoves.push_back(endSpace);
    moveNumber++;
    return 1;
  }
  //If the move was illegal
  return -1;
}

//Adds a piece to the board, given the necessary attributes. Returns -1 on failure.
int Board::addPiece(char type, int startSpace, int isWhite){
  if (activeArray[startSpace] == 1){ //If the space is taken
    return -1;
  }
  activeArray[startSpace] = 1; //Activates the space before placing the piece
  switch (type){
    case 'b':
      pieceArray[startSpace] = new Bishop(startSpace, isWhite);
      break;
    case 'n':
      pieceArray[startSpace] = new Knight(startSpace, isWhite);
      break;
    case 'p':
      pieceArray[startSpace] = new Pawn(startSpace, isWhite);
      break;
    case 'k':
      pieceArray[startSpace] = new King(startSpace, isWhite);
      break;
    case 'q':
      pieceArray[startSpace] = new Queen(startSpace, isWhite);
      break;
    case 'r':
      pieceArray[startSpace] = new Rook(startSpace, isWhite);
      break;
  }

  return 0;
}

//Gets the unicode chess piece for a given square
const char* Board::getPiece(int space){
  char type = pieceArray[space]->getType();
  bool isWhite = pieceArray[space]->getIsWhite();

  if (isWhite == 1){
    //White Pieces
    switch (type) {
      case 'p':
      return u8"\u2659";
      case 'r':
      return u8"\u2656";
      case 'b':
      return u8"\u2657";
      case 'n':
      return u8"\u2658";
      case 'k':
      return u8"♔";
      case 'q':
      return u8"\u2655";
    }
  } else {
    //Black Pieces
    switch (type) {
      case 'p':
      return u8"\u265F";
      case 'r':
      return u8"\u265C";
      case 'b':
      return u8"\u265D";
      case 'n':
      return u8"\u265E";
      case 'k':
      return u8"\u265A";
      case 'q':
      return u8"\u265B";
    }
  }

  return u8"U+FFFD";
}

//This function gets the unicode character from the pastPieces vector to allow move
//history to be printed.
const char* Board::getPastPiece(int number){
  int isWhite = ((number + 1) % 2);

  if (isWhite == 1){
    //White Pieces
    switch (pastPieces[number]) {
      case 'p':
      return u8"\u2659";
      case 'r':
      return u8"\u2656";
      case 'b':
      return u8"\u2657";
      case 'n':
      return u8"\u2658";
      case 'k':
      return u8"♔";
      case 'q':
      return u8"\u2655";
    }
  } else {
    //Black Pieces
    switch (pastPieces[number]) {
      case 'p':
      return u8"\u265F";
      case 'r':
      return u8"\u265C";
      case 'b':
      return u8"\u265D";
      case 'n':
      return u8"\u265E";
      case 'k':
      return u8"\u265A";
      case 'q':
      return u8"\u265B";
    }
  }

  //Error character
  return u8"\uFFFD";
}

//Given a move number, returns a string in chess notation of the desination square.
std::string Board::getPastSquare(int number){
  return encode(pastMoves[number]);
}

// Gives accesss to the moveNumber variable, which stores how many moves have been played.
int Board::getMoveNumber(){
  return moveNumber;
}

// Gives access to the activeArray, a 64-long boolean array which records if squares have pieces on them.
bool* Board::getActiveArray(){
	return activeArray;
}

Piece** Board::getPieceArray(){
	return pieceArray;
}

//Returns 0 if no check, 1 if white, 2 if black and 3 if both
int Board::checkCheck(bool isWhiteTurn) {

	// bool* actArr = board->getActiveArray();
	// Piece** pieceArr = board->getPieceArray();

  int kingSquare = 300;

	//WHITE KING

	//Find what square the king is on
	for (int i = 0; i < 63; i++) {
		if (pieceArray[i]->getType() == 'k') {
			kingSquare = i;
			break;
		}
	}

	std::cout << kingSquare;

	//Find straight destinations
	int edges[4];		//Array of squares at the edge of board that could be attacking king, 0-3, anticlockwise starting east

	int kingRow = row(kingSquare);
	int kingCol = col(kingSquare);

	edges[0] = 56 + kingRow;
	edges[1] = (8 * kingCol) + 7;
	edges[2] = 0 + kingRow;
	edges[3] = 8 * kingCol;

	//Find if pieces are on squares
	int pieceSquares[4];
	for (int i = 0; i < 4; i++) {
		pieceSquares[i] = pieceArray[kingSquare]->checkStraight(edges[i], activeArray);
	}

	//Check squares
	for (int i = 0; i < 4; i++) {
		if (pieceSquares[i] != -1) {
			//If the piece is a black rook, queen or king
			if (pieceArray[pieceSquares[i]]->getType() == 'r' || pieceArray[pieceSquares[i]]->getType() == 'q') {
				return 1;
			}
		}
	}

	//Find diagonal destinations - edges now 0-3, anticlockwise starting north-east

	/*
	int kingRowIncr = kingRow;
	int kingColIncr = kingCol;

	while (kingRowIncr < 8 && kingColIncr < 8) {
		kingRowIncr++;
		kingColIncr++;
	}

	edges[0] = (kingColIncr * 8) + kingRowIncr;

	while (kingRowIncr < 8 && kingColIncr > -1) {
		kingRowIncr++;
		kingColIncr--;
	}

	edges[1] = (kingColIncr * 8) + kingRowIncr;

	while (kingRowIncr > -1 && kingColIncr > -1) {
		kingRowIncr--;
		kingColIncr--;
	}

	edges[2] = (kingColIncr * 8) + kingRowIncr;

	while (kingRowIncr > -1 && kingColIncr < 8) {
		kingRowIncr--;
		kingColIncr++;
	}

	edges[3] = (kingColIncr * 8) + kingRowIncr;

	//Find if pieces are on squares
	pieceSquares[4];
	for (int i = 0; i < 4; i++) {
		pieceSquares[i] = pieceArr[kingSquare]->checkStraight(edges[i], actArr);
	}

	//Check squares
	for (int i = 0; i < 4; i++) {
		if (pieceSquares[i] != -1) {
			//If the piece is a black bishop, queen, king or (pawn that is above white king on board)
			if (board->getPiece(pieceSquares[i]) == u8"\u265D" || board->getPiece(pieceSquares[i]) == u8"\u265B" || board->getPiece(pieceSquares[i]) == u8"\u265A" || (board->getPiece(pieceSquares[i]) == u8"\u265F" && row(pieceSquares[i]) > kingRow)) {
				return 1;
			}
		}
	}
	*/

	// int knightSquares[8] = {kingSquare+17,kingSquare+10,kingSquare-6,kingSquare-15,}

  return 0;
}

//Destructor has no specific behaviour
Board::~Board(){

}
