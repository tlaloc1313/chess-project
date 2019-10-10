#include <iostream>
using std::cout;
using std::cin;
using std::wcout;

//Defines the horizontal spacing between columns
#ifndef SPACINGH
#define SPACINGH "   "
#endif

//Defines the vertical spacing between rows
#ifndef SPACINGV
#define SPACINGV "\n\n"
#endif

#include "Board.h"

//This function takes the game board and uses behaviour functions to output all
// previous moves in chess algebraic notation.
void drawMoves(Board* gameBoard){
  cout<< "Moves: \n";

  //Loops from start to current point in game.
  for (int i = 0; i < gameBoard->getMoveNumber(); i++){
    cout << gameBoard->getPastPiece(i) << gameBoard->getPastSquare(i) << "  ";
  }
  cout << "\n\n";
}

// Draws the game board at its current state, with all pieces. Flips the board
// when it is black's turn to move.
int draw(Board* gameBoard, bool isWhiteTurn) {
  //Initialising variables
  int currentSquare;

  //Clears the screen
  for (int n=0; n<10; n++){
    cout<<"\n\n\n\n\n\n\n\n\n\n";
  }

  //Game board is displayed from White's POV
  if (isWhiteTurn == 1){

    //Iterating through rows
    for (int row=7; row>=0; row--){

      //Row numbering is displayed alongside the board
      cout<<row+1<<SPACINGH;

      //Iterating through columns
      for (int column=0; column<8; column++){
        currentSquare = (column*8) + row;

        //Where the square is occupied, print that piece
        if (gameBoard->spaceOccupied(currentSquare) == 1){
          cout<<gameBoard->getPiece(currentSquare)<<SPACINGH;
        } else { //Where the square is unoccupied, print either a black or white square
          if ((column+row)%2 == 0){
            cout<<"#"<<SPACINGH;
          } else {
            cout<<" "<<SPACINGH;
          }
        }
      }
      //Spacing between rows:
      cout<<SPACINGV;
    }
    // Column numbers are displayed below the board
    cout<<" "<<SPACINGH<<"a"<<SPACINGH<<"b"<<SPACINGH<<"c"<<SPACINGH<<"d"<<SPACINGH<<"e"<<SPACINGH<<"f"<<SPACINGH<<"g"<<SPACINGH<<"h \n\n";

  } else { //Game board is displayed from Black's POV

    //Iterating through rows
    for (int row=0; row<8; row++){

      //Row numbering is displayed alongside the board
      cout<<row+1<<SPACINGH;

      //Iterating through columns
      for (int column=7; column>=0; column--){
        currentSquare = (column*8) + row;

        //Where the square is occupied, print that piece
        if (gameBoard->spaceOccupied(currentSquare) == 1){
          cout<<gameBoard->getPiece(currentSquare)<<SPACINGH;
        } else { //Where the square is unoccupied, print either a black or white square
          if ((column+row)%2 == 0){
            cout<<"#"<<SPACINGH;
          } else {
            cout<<" "<<SPACINGH;
          }
        }
      }
      //Spacing between rows:
      cout<<SPACINGV;
    }
    // Column numbers are displayed below the board
    cout<<" "<<SPACINGH<<"h"<<SPACINGH<<"g"<<SPACINGH<<"f"<<SPACINGH<<"e"<<SPACINGH<<"d"<<SPACINGH<<"c"<<SPACINGH<<"b"<<SPACINGH<<"a \n\n";
  }

  drawMoves(gameBoard);

return 0;
}
