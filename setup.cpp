#include "Board.h"

//Uses behaviour of the Board class to setup a standard
//game of chess on the given gameBoard 
int setup(Board gameBoard) {
  //White Pawns
  gameboard.addPiece('p', 1, 1);
  gameboard.addPiece('p', 9, 1);
  gameboard.addPiece('p', 17, 1);
  gameboard.addPiece('p', 25, 1);
  gameboard.addPiece('p', 33, 1);
  gameboard.addPiece('p', 41, 1);
  gameboard.addPiece('p', 49, 1);
  gameboard.addPiece('p', 57, 1);

  //Black Pawns
  gameboard.addPiece('p', 6, 0);
  gameboard.addPiece('p', 14, 0);
  gameboard.addPiece('p', 22, 0);
  gameboard.addPiece('p', 30, 0);
  gameboard.addPiece('p', 38, 0);
  gameboard.addPiece('p', 46, 0);
  gameboard.addPiece('p', 54, 0);
  gameboard.addPiece('p', 62, 0);

  //Rooks
  gameboard.addPiece('r', 0, 1);
  gameboard.addPiece('r', 56, 1);
  gameboard.addPiece('r', 7, 0);
  gameboard.addPiece('r', 63, 0);

  //Bishops
  gameboard.addPiece('n', 16, 1);
  gameboard.addPiece('n', 40, 1);
  gameboard.addPiece('n', 23, 0);
  gameboard.addPiece('n', 47, 0);

  //Knights - note 'n' as type
  gameboard.addPiece('n', 8, 1);
  gameboard.addPiece('n', 48, 1);
  gameboard.addPiece('n', 15, 0);
  gameboard.addPiece('n', 55, 0);

  //Kings - note 'k' as type
  gameboard.addPiece('k', 32, 1);
  gameboard.addPiece('k', 39, 0);

  //Queens
  gameboard.addPiece('q', 24, 1);
  gameboard.addPiece('q', 31, 0);

  return 0;
}
