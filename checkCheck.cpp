/*  This function takes a given position of the board, and a
    boolean isWhiteTurn, and checks if the position has resulted
    in the previous moving player being in check.
*/
#include "Board.h"
#include <iostream>
#include <string.h>

//Returns 0 if no check, 1 if white, 2 if black and 3 if both
int check(Board* board, bool isWhiteTurn) {

	bool* actArr = board->getActiveArray();
	Piece** pieceArr = board->getPieceArray();

  int kingSquare;

	//WHITE KING

	//Find what square the king is on
	for (int i = 0; i < 63; i++) {
		std::cout << "Hi\n";
		if (pieceArr[i]->getType() == 'k') {
			kingSquare = i;
			break;
		}
	}

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
		pieceSquares[i] = pieceArr[kingSquare]->checkStraight(edges[i], actArr);
	}

	//Check squares
	for (int i = 0; i < 4; i++) {
		if (pieceSquares[i] != -1) {
			//If the piece is a black rook, queen or king
			if (strcmp(board->getPiece(pieceSquares[i]), u8"\u265C") == 0 || strcmp(board->getPiece(pieceSquares[i]), u8"\u265B") == 0 || strcmp(board->getPiece(pieceSquares[i]), u8"\u265A")) {
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
