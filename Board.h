#include "Pieces.h"

#include <vector>
#include <string>

#ifndef BOARD_H
#define BOARD_H

//Board class is used to track the active pieces and their location. It allows for
//movement of pieces and creation/deletion of piece objects.
class Board {
private:
  bool activeArray[64]; //Tracks if a square has a piece
  std::vector<char> pastPieces;
  std::vector<int> pastMoves;
  int moveNumber;

public:
	Piece* pieceArray[64]; //Array of pieces corresponding to squares
  Board ();
  bool spaceOccupied(int space); //Checks if a square is occupied
  const char* getPiece(int space); //Returns what type of piece is at a square
  const char* getPastPiece(int number);
  std::string getPastSquare(int number);
  int getMoveNumber();
	Piece** getPieceArray();
	bool* getActiveArray();
	int checkCheck(bool isWhiteTurn);

  //Returns 2 if a piece is taken, 1 if the piece is moved,
  //-1 if the move is illegal, -2 if the piece doesn't exist
  int movePiece(int startSpace, int endSpace, int whiteTurn);

  //Returns 1 if the piece was added, -1 if the space is taken
  int addPiece(char type, int startSpace, int isWhite);
  virtual ~Board ();
};

#endif
