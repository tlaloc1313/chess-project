#include <iostream>
using std::cout;
using std::cin;
using std::wcout;

#include "Board.h"

void drawMoves(Board* gameBoard){
  cout<< "Moves: \n";
  for (int i = 0; i < gameBoard->getMoveNumber(); i++){
    cout << gameBoard->getPastPiece(i) << gameBoard->getPastSquare(i) << "  ";
  }
  cout << "\n\n";
}

int draw(Board* gameBoard) {
  int currentSquare;

  for (int n=0; n<10; n++){
    cout<<"\n\n\n\n\n\n\n\n\n\n";
  }

  for (int row=7; row>=0; row--){

    cout<<row+1<<"   ";

    for (int column=0; column<8; column++){
      currentSquare = (column*8) + row;

      //Where the square is occupied
      if (gameBoard->spaceOccupied(currentSquare) == 1){
        cout<<gameBoard->getPiece(currentSquare)<<"   ";
      } else { //Where the square is unoccupied
        if ((column+row)%2 == 0){
          cout<<"#"<<"   ";
        } else {
          cout<<" "<<"   ";
        }
      }
    }
    cout<<"\n\n";
  }

  cout<<"    a   b   c   d   e   f   g   h \n\n";

  drawMoves(gameBoard);

return 0;
}
