#include "Board.h"

//Uses behaviour of the Board class to setup a standard
//game of chess on the given gameBoard
int setup(Board* gameBoard) {
  //White Pawns
  gameBoard->addPiece('p', 1, 1);
  gameBoard->addPiece('p', 9, 1);
  gameBoard->addPiece('p', 17, 1);
  gameBoard->addPiece('p', 25, 1);
  gameBoard->addPiece('p', 33, 1);
  gameBoard->addPiece('p', 41, 1);
  gameBoard->addPiece('p', 49, 1);
  gameBoard->addPiece('p', 57, 1);

  //Black Pawns
  gameBoard->addPiece('p', 6, 0);
  gameBoard->addPiece('p', 14, 0);
  gameBoard->addPiece('p', 22, 0);
  gameBoard->addPiece('p', 30, 0);
  gameBoard->addPiece('p', 38, 0);
  gameBoard->addPiece('p', 46, 0);
  gameBoard->addPiece('p', 54, 0);
  gameBoard->addPiece('p', 62, 0);

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

//Success
return 0;
}

int setupchecktest(Board* gameBoard) {
  //White Pawns
  // gameBoard->addPiece('p', 12, 1);

  //Black Pawns
  // gameBoard->addPiece('p', 27, 0);

  //Rooks
  // gameBoard->addPiece('r', 0, 1);
  // gameBoard->addPiece('r', 0, 0);

  //Bishops
  // gameBoard->addPiece('b', 16, 1);
  // gameBoard->addPiece('b', 16, 0);

  //Knights - note 'n' as type
  // gameBoard->addPiece('n', 8, 1);
  // gameBoard->addPiece('n', 44, 0);

  //Kings - note 'k' as type
  gameBoard->addPiece('k', 55, 1);
  gameBoard->addPiece('k', 18, 0);

  //Queens
  gameBoard->addPiece('q', 24, 1);
  // gameBoard->addPiece('q', 58, 0);
return 0;
}
