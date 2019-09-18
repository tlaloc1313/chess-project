/* Header file for all pieces */

// Superclass
class Piece {
private:

public:
  char type;
  int location;
  bool isWhite;
  bool isActive;
  bool hasMoved;
  Piece (int startingSquare);
  virtual void move();
  int beTaken();
  int getPosition();
  virtual ~Piece ();
};

class Bishop = public Piece {
public:
  void move();
};
