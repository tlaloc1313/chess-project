/* Header file for all pieces */
#ifndef PIECES_H
#define PIECES_H

#include <cmath>

extern int col(int location);
extern int row(int location);

// Superclass
class Piece {
private:

public:
  char pieceType;
  int location;
  bool isWhite;
  bool hasMoved;
  Piece();
	int direction(int destination);
	virtual bool checkPath(int destination, bool activeArray[64]);
  virtual bool move(int square, bool activeArray[64]);
  int getPosition();
  int isActive;
  char getType();
  bool getIsWhite();
  ~Piece ();
};

class Bishop : public Piece {
public:
  Bishop(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~Bishop();
};


class King : public Piece{
public:
  King(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~King();
};

class Knight : public Piece{
public:
  Knight(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~Knight();
};

class Pawn : public Piece{
public:
  Pawn(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~Pawn();
};

class Queen : public Piece{
public:
  Queen(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~Queen();
};

class Rook : public Piece{
public:
  Rook(int startingSquare, int isWhite);
	bool checkPath(int destination, bool activeArray[64]);
  bool move(int square, bool activeArray[64]);
  ~Rook();
};


#endif
