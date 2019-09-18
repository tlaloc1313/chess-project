#include <iostream>
using std::cout;
using std::cin;

#include "Board.h"

int draw(Board gameBoard) {
  int currentSquare;

  for (int n=0; n<10; n++){
    cout<<"\n\n\n\n\n\n\n\n\n\n";
  }

  for (int row=7; row>=0; row--){

    for (int column=0; column<8; column++){
      currentSquare = (column*8) + row;

      //Where the square is occupied
      if (gameBoard.spaceOccupied(currentSquare) == 1){
        cout<<gameBoard.getPiece(currentSquare)<<" ";
      } else { //Where the square is unoccupied
        cout<<"#"<<" ";
      }
    }
    cout<<"\n";
  }
return 0;
}
