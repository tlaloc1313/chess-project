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
  bool isActive;
  bool hasMoved;
  virtual Piece (int startingSquare, int isWhite);
  virtual void move(int square);
  int beTaken();
  int getPosition();
  int getType();
  int getIsWhite();
  virtual ~Piece ();
};

class Bishop = public Piece {
public:
  ~Bishop();
};


class King = public Piece{
public:
  ~King();
};

class Knight = public Piece{
public:
  ~Knight();
};

class Pawn = public Piece{
public:
  ~Pawn();
};

class Queen = public Piece{
public:
  ~Queen();
};

class Rook = public Piece{
public:
  ~Rook();
};


#endif
