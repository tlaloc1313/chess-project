/* Header file for all pieces */
#ifndef PIECES_H
#define PIECES_H

// Superclass
class Piece {
private:

public:
  char type;
  int location;
  bool isWhite;
  bool hasMoved;
  Piece (int startingSquare, int isWhite);
  virtual bool move(int square);
  int getPosition();
  char getType();
  bool getIsWhite();
  virtual ~Piece ();
};

class Bishop : public Piece {
public:
  Bishop(int startingSquare, int isWhite);
  bool move(int square);
  ~Bishop();
};


class King : public Piece{
public:
  King(int startingSquare, int isWhite);
  bool move(int square);
  ~King();
};

class Knight : public Piece{
public:
  Knight(int startingSquare, int isWhite);
  bool move(int square);
  ~Knight();
};

class Pawn : public Piece{
public:
  Pawn(int startingSquare, int isWhite);
  bool move(int square);
  ~Pawn();
};

class Queen : public Piece{
public:
  Queen(int startingSquare, int isWhite);
  bool move(int square);
  ~Queen();
};

class Rook : public Piece{
public:
  Rook(int startingSquare, int isWhite);
  bool move(int square);
  ~Rook();
};


#endif
