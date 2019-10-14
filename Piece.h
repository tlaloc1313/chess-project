#ifndef PIECE_H
#define PIECE_H

#include <cmath>
using std::abs;

extern int col(int location);
extern int row(int location);

// Superclass
class Piece {
protected:
  int location;
  char pieceType;
  bool isWhite;
  bool hasMoved;
  bool enPassantPossible;

public:
  Piece();
  int getPosition();
  char getType();
  bool getIsWhite();
  bool getHasMoved();
	int direction(int destination);
	int checkStraight(int destination, bool activeArray[64]);
	int checkDiagonal(int destination, bool activeArray[64]);
  int checkEnPassant();
  virtual bool checkPath(int destination, bool activeArray[64]);
  virtual bool move(int square, bool activeArray[64]);
  virtual void castle(int square);
  virtual ~Piece ();
};

#endif
