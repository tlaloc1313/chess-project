#ifndef PIECE_H
#define PIECE_H

#include <cmath>
using std::abs;

extern int col(int location);
extern int row(int location);

// Superclass
class Piece {
protected:
  char pieceType;
  int location;
  bool isWhite;
  bool hasMoved;
  bool enPassantPossible;

public:
  Piece();
	int direction(int destination);
	int checkStraight(int destination, bool activeArray[64]);
	int checkDiagonal(int destination, bool activeArray[64]);
	virtual bool checkPath(int destination, bool activeArray[64]);
  virtual bool move(int square, bool activeArray[64]);
  int getPosition();
  char getType();
  bool getIsWhite();
  bool getHasMoved();
  virtual void castle(int square);
  int checkEnPassant();
  virtual ~Piece ();
};

#endif
