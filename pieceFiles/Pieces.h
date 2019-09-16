class Piece {
private:

public:
  char type;
  int location;
  int isWhite;
  int isActive;
  Piece (int startingSquare);
  virtual move();
  int getTaken();
  int getPosition();
  virtual ~Piece ();
};
