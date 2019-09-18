#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

#include "Pieces.h"
#include "Board.h"

extern int setup(Board* gameBoard);
extern int inputFunc();

int main(int argc, char const *argv[]) {
  //Set first turn to white
  bool whiteTurn=1;
  int gameEnd = 0;
  // Setup a game
  Board* gameBoard = new Board();
  setup(gameBoard);

  while (gameEnd == 0){
    //Display whose turn it is
    if (whiteTurn==1){
      cout << "White to move:\n";
    }
    else{
      "Black to move:\n";
    }

    cout << "From: ";
    int startPos = inputFunc();
    cout << "To: ";
    int endPos = inputFunc();


    whiteTurn++;
  }
  return 0;
}
