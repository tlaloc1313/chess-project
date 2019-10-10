#include <iostream>
#include <string>
#include <chrono>
#include <random>
using std::cout;
using std::cin;
using std::string;

#include "Board.h"

extern int setup(Board* gameBoard);
extern int inputFunc();
extern int draw(Board* gameBoard, bool isWhiteTurn);
extern int checkCheck(Board* board, bool isWhiteTurn);

int main(int argc, char const *argv[]) {

  for (int i = 0; i < 10; i++) {
    cout<<"\n\n\n\n\n\n\n\n\n\n";
  }

  cout<<"Welcome to Chess++, a chess interface developed in C++11.\nPress Enter/Return to continue...";
  cin.get();

  //Set first turn to white
  bool whiteTurn=1;
  int gameEnd = 0;
  // Setup a game
  Board* gameBoard = new Board();
  setup(gameBoard);

	//Records if a player has used a cheat code
	bool whiteCheat = 0;
	bool blackCheat = 0;

	// int inCheck = 0;

  while (gameEnd == 0){
    draw(gameBoard, whiteTurn);

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

			//Cheat code - creates a queen of the current player in a random, unoccupied square
			//There is a 1 in 10 chance to create an opponent's queen
			if (startPos == 1000) {
				if ((whiteTurn && whiteCheat == 0) || (!whiteTurn && blackCheat == 0)) {
					unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	//Current time in ms
					std::default_random_engine generator (seed);	//Generates uniformly distributed numbers
					std::uniform_int_distribution<int> sqrDist(0,63);	//Uniform int distribution from 0-63
					std::uniform_int_distribution<int> failDist(0,9);	//Uniform int distribution from 0-9
					bool free = 0;
					while (!free) {
						int randNum = sqrDist(generator);	//Generates the number
						if (gameBoard->spaceOccupied(randNum) == 0) {
							free = 1;
							if (failDist(generator) == 0) {
								gameBoard->addPiece('q', randNum, !whiteTurn);	//Adds opponent's queen
								cout << "Bad luck...\n";
							} else {
								gameBoard->addPiece('q', randNum, whiteTurn);		//Adds player's queen
							}
							//Uses the cheat of the current player
							if (whiteTurn) {
								whiteCheat = 1;
							} else {
								blackCheat = 1;
							}
							draw(gameBoard, whiteTurn);
						}
					}
					break;
				} else {
					cout << "Nice try 😉\n";
					continue;
				}
			}

      cout << "To: ";
      int endPos = inputFunc();

      //CASTLING
      if (startPos == 69) {
        switch (endPos){

          //White castling queenside
          case 8:
            if (whiteTurn == 0){
              break;
            }

          break;

          //Black castling queenside
          case 15:
            if (whiteTurn == 1){
              break;
            }

          break;

          //White castling kingside
          case 48:
            if (whiteTurn == 0){
              break;
            }

          break;

          //Black castling kingside
          case 55:
            if (whiteTurn == 1){
              break;
            }

          break;
        }
      }

      success = gameBoard->movePiece(startPos, endPos, whiteTurn);

      if (success != 1){
        std::cout << "Invalid Move" << '\n';
      }
    }
    whiteTurn= !whiteTurn;
  }
  return 0;
}
