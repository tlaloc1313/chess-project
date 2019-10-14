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
// extern int checkCheck(Board* board, bool isWhiteTurn);

int main(int argc, char const *argv[]) {

  for (int i = 0; i < 10; i++) {
    cout<<"\n\n\n\n\n\n\n\n\n\n";
  }

  cout<<"Welcome to Chess++, a chess interface developed in C++11.\n\nPress Enter/Return to continue...";
  cin.get();

  //Set first turn to white
  bool whiteTurn=1;
  int gameEnd = 0;
  char drawAccept = ' ';
  // Setup a game
  Board* gameBoard = new Board();
  setup(gameBoard);

	//Records if a player has used a cheat code
	bool whiteCheat = 0;
	bool blackCheat = 0;

  //Set to 1 to enter test mode.
  bool longTest = 0;
  int longTestCounter = 0;
  int testMoves[1000] = {33, 35, 38, 36, 48, 42, 55, 45, 8, 18, 15, 20, 15, 21, 40,
    19, 30, 29, 25, 26, 47, 29, 47, 38, 16, 34, 69, 55, 24,
    25, 6, 5, 69, 16, 14, 12, 19, 18, 19, 10, 7, 14, 7, 15, 57, 58, 5, 3, 5, 4, 1, 2, 4, 3, 10, 1, 23, 37, 1, 37, 46, 37,
    24, 48, 30, 28, 29, 28, 35, 28, 37, 28, 49, 51,
    28, 27, 51, 52, 27, 34, 25, 34, 45, 28, 18, 28, 31, 28, 52, 53, 28, 42, 53, 62, 42, 34, 55, 63, 34, 25, 21, 27, 25, 32, 27, 33, 48,
    50, 16, 8, 33, 48, 56, 48, 42, 41, 32, 41, 47, 41, 48, 40, 41, 40, 8, 1, 63, 62, 9, 11, 3, 10, 1, 10, 36, 35, 26, 27, 35, 34,
    2, 3, 34, 33, 27, 28, 33, 32, 3, 4, 32, 11, 10, 1, 11, 8};

	int inCheck = 0;
  int success, startPos, endPos;

  while (gameEnd == 0){

    //50 Move Rules
    if (gameBoard->getMovesSince()>100){
      cout << "50 Move Rule - Game is Drawn\n";
      gameEnd = 3;
      break;
    }

    draw(gameBoard, whiteTurn);
    //Display whose turn it is
    if (whiteTurn){
      cout << "White to move:"<< std::endl;
    }
    else{

      cout<<"Black to move:" << std::endl;
    }

    success = 0;

    while (success !=1){
      cout << "From: ";
      if (!longTest) {
        //Normal Operation
          startPos = inputFunc();
        } else {
        //Long Test
          startPos = testMoves[longTestCounter];
          longTestCounter++;
      }


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

      //Resignation or Draw Offers:
      if (startPos == 800){ //Resignation
        if (whiteTurn){
          cout << "Black wins by resignation!\n";
          gameEnd = 2;
        } else {
          cout << "White wins by resignation!\n";
          gameEnd =  1;
        }
        break;
      }
      if (startPos == 801){ // Draw offer
        if (whiteTurn){
          cout << "White offers a draw. Black, do you accept? (y/n) ";
          cin >> drawAccept;
          if (drawAccept == 'y'){
            cout << "The game is drawn!\n";
            gameEnd = 3;
            break;
          } else {
            continue;
          }
        } else {
          cout << "Black offers a draw. White, do you accept? (y/n) ";
          cin >> drawAccept;
          if (drawAccept == 'y'){
            cout << "The game is drawn!\n";
            gameEnd = 3;
            break;
          } else {
            continue;
          }
        }
      }

      cout << "To: ";
      if (!longTest) {
          //Normal Operation
          endPos = inputFunc();
        } else {
          //Long Test
          endPos = testMoves[longTestCounter];
          longTestCounter++;
      }
      //CASTLING
      if (startPos == 69) {
        success = 0; //Castling fails by default

        switch (endPos){

          //White castling queenside
          case 16:
            if (whiteTurn == 1){
              success = gameBoard->castle(1, 0);
            }
          break;

          //Black castling queenside
          case 23:
            if (whiteTurn == 0){
              success = gameBoard->castle(0, 0);
            }
          break;

          //White castling kingside
          case 48:
            if (whiteTurn == 1){
              success = gameBoard->castle(1, 1);
            }
          break;

          //Black castling kingside
          case 55:
            if (whiteTurn == 0){
              success = gameBoard->castle(0, 1);
            }
          break;
        }
      } else { //If no special move is being made, attempt to make normal move

				Board gameBoardCopy(gameBoard->getPieceArray(), gameBoard->getActiveArray(), gameBoard->getPastPieces(), gameBoard->getPastMoves());

				success = gameBoardCopy.movePiece(startPos, endPos, whiteTurn);

				if (success >= 1) {
          std::cout << std::endl;
					inCheck = gameBoardCopy.checkCheck();
				}

				//delete gameBoardCopy;

				if (inCheck == 3) {
					std::cout << "White and Black are in check. ";
					success = 0;
					inCheck = 0;
				} else if (whiteTurn && inCheck == 1) {
					std::cout << "White is in check. ";
					success = 0;
					inCheck = 0;
				} else if (!whiteTurn && inCheck == 2) {
					std::cout << "Black is in check. ";
					success = 0;
					inCheck = 0;
				} else {
					gameBoard->movePiece(startPos, endPos, whiteTurn);
				}
      }
      if (success != 1){
        std::cout << "Invalid Move\n";
      }
    }
    whiteTurn= !whiteTurn;
  }


  delete gameBoard;
  return 0;
}
