#include <iostream>
using std::cout;
using std::cin;
using std::wcout;

#ifndef SPACINGH
#define SPACINGH "   "
#endif

#include "Board.h"

void drawMoves(Board* gameBoard){
  cout<< "Moves: \n";
  for (int i = 0; i < gameBoard->getMoveNumber(); i++){
    cout << gameBoard->getPastPiece(i) << gameBoard->getPastSquare(i) << "  ";
  }
  cout << "\n\n";
}

int draw(Board* gameBoard, bool isWhiteTurn) {
  int currentSquare;

  for (int n=0; n<10; n++){
    cout<<"\n\n\n\n\n\n\n\n\n\n";
  }

  if (isWhiteTurn == 1){

    for (int row=7; row>=0; row--){

      cout<<row+1<<SPACINGH;

      for (int column=0; column<8; column++){
        currentSquare = (column*8) + row;

        //Where the square is occupied
        if (gameBoard->spaceOccupied(currentSquare) == 1){
          cout<<gameBoard->getPiece(currentSquare)<<SPACINGH;
        } else { //Where the square is unoccupied
          if ((column+row)%2 == 0){
            cout<<"#"<<SPACINGH;
          } else {
            cout<<" "<<SPACINGH;
          }
        }
      }
      cout<<"\n\n";
    }

    cout<<" "<<SPACINGH<<"a"<<SPACINGH<<"b"<<SPACINGH<<"c"<<SPACINGH<<"d"<<SPACINGH<<"e"<<SPACINGH<<"f"<<SPACINGH<<"g"<<SPACINGH<<"h \n\n";

  } else {

    for (int row=0; row<8; row++){

      cout<<row+1<<SPACINGH;

      for (int column=7; column>=0; column--){
        currentSquare = (column*8) + row;

        //Where the square is occupied
        if (gameBoard->spaceOccupied(currentSquare) == 1){
          cout<<gameBoard->getPiece(currentSquare)<<SPACINGH;
        } else { //Where the square is unoccupied
          if ((column+row)%2 == 0){
            cout<<"#"<<SPACINGH;
          } else {
            cout<<" "<<SPACINGH;
          }
        }
      }
      cout<<"\n\n";
    }

    cout<<" "<<SPACINGH<<"h"<<SPACINGH<<"g"<<SPACINGH<<"f"<<SPACINGH<<"e"<<SPACINGH<<"d"<<SPACINGH<<"c"<<SPACINGH<<"b"<<SPACINGH<<"a \n\n";
  }

  drawMoves(gameBoard);

return 0;
}
