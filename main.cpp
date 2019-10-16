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

int main(int argc, char const *argv[]) {

  //Clear screen
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

  int inCheck = 0;
  int success, startPos, endPos;

  while (gameEnd == 0) {

    //50 Move Rules
    if (gameBoard->getMovesSince()>100) {
      cout << "50 Move Rule - Game is Drawn\n";
      gameEnd = 3;
      break;
    }

    draw(gameBoard, whiteTurn);
    //Display whose turn it is
    if (whiteTurn) {
      cout << "White to move:"<< std::endl;
    } else {
      cout<<"Black to move:" << std::endl;
    }

    //Assume move is unsuccessful
    success = 0;
    //Keep asking for moves until successful
    while (success !=1){
      cout << "From: ";
        startPos = inputFunc();
        if (startPos == -1){ // In case of invalid iostream (end of a test file)
          return 0;
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
            //Generates a number and checks that the square is free
						int randNum = sqrDist(generator);
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
      endPos = inputFunc();

      //CASTLING -- Returns -5 if castling through check
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

        //Section checks if the move results in the player being in check.
        //Creates a copy of the board
				Board* gameBoardCopy = new Board(gameBoard->getPieceArray(), gameBoard->getActiveArray(), gameBoard->getPastPieces(), gameBoard->getPastMoves());
        //Makes the move on the copied board
      	success = gameBoardCopy->movePiece(startPos, endPos, whiteTurn);
        //Checks that the piece isn't in check after moving then deletes copy.
				if (success >= 1) {
					inCheck = gameBoardCopy->checkCheck(-1, -1);
				}
				delete gameBoardCopy;

				if (whiteTurn && (inCheck == 1 || inCheck == 3)) {
					std::cout << "White is in check. ";
					success = 0;
					inCheck = 0;
				} else if (!whiteTurn && (inCheck == 2 || inCheck == 3)) {
					std::cout << "Black is in check. ";
					success = 0;
					inCheck = 0;
				} else {
					gameBoard->movePiece(startPos, endPos, whiteTurn);
				}
      }

      // This section ensures that the user is aware of the exact reason for the
      // invalidity of their move by providing them with detailed messages as
      // decided by a switch statement.
      switch (success) {
        case 0:
        cout << "Invalid Move\n";
        break;
        case -5:
        cout << "Invalid Move - Cannot castle through, out of, or into check\n";
        break;
        case -4:
        cout << "Invalid Move - Illegal Castling\n";
        break;
      }
    }
    whiteTurn= !whiteTurn;
  }


  delete gameBoard;
  return 0;
}
