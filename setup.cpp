#include "Board.h"

//Uses behaviour of the Board class to setup a standard
//game of chess on the given gameBoard
int setup(Board* gameBoard) {

  //Pawns
  for (int i = 1; i<64; i+=8) {
    gameBoard->addPiece('p', i, 1);
    gameBoard->addPiece('p', i+5 , 0);
  }

  //Rooks
  gameBoard->addPiece('r', 0, 1);
  gameBoard->addPiece('r', 56, 1);
  gameBoard->addPiece('r', 7, 0);
  gameBoard->addPiece('r', 63, 0);

  //Bishops
  gameBoard->addPiece('b', 16, 1);
  gameBoard->addPiece('b', 40, 1);
  gameBoard->addPiece('b', 23, 0);
  gameBoard->addPiece('b', 47, 0);

  //Knights - note 'n' as type
  gameBoard->addPiece('n', 8, 1);
  gameBoard->addPiece('n', 48, 1);
  gameBoard->addPiece('n', 15, 0);
  gameBoard->addPiece('n', 55, 0);

  //Kings - note 'k' as type
  gameBoard->addPiece('k', 32, 1);
  gameBoard->addPiece('k', 39, 0);

  //Queens
  gameBoard->addPiece('q', 24, 1);
  gameBoard->addPiece('q', 31, 0);

return 0;
}