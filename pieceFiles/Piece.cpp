#include "Pieces.h"

int Piece::getPosition(){
  return location;
}

char Piece::getType(){
  return type;
}

bool Piece::getIsWhite(){
  return isWhite;
}
