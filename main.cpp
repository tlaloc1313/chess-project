#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

#include "Pieces.h"
#include "Board.h"

extern int setup(Board* gameBoard);
extern int inputFunc();
extern int draw(Board* gameBoard);

int main(int argc, char const *argv[]) {
  //Set first turn to white
  bool whiteTurn=1;
  int gameEnd = 0;
  // Setup a game
  Board* gameBoard = new Board();
  setup(gameBoard);

  while (gameEnd == 0){
    draw(gameBoard);

    //Display whose turn it is
    if (whiteTurn==1){
      cout << "White to move:\n";
    }
    else{
      cout<<"Black to move:\n";
    }

    int success = 0;

    while (success !=1){

      cout << "From: ";
      int startPos = inputFunc();
      cout << "To: ";
      int endPos = inputFunc();

      success = gameBoard->movePiece(startPos, endPos);
    }

    whiteTurn= !whiteTurn;
  }
  return 0;
}
