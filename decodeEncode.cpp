#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;

//Takes input from cin and encodes to number from 0-63.
//"a1" returns 0, "a2" returns 1,..., "h8" returns 63.
//Returns a negative number if not a valid input
int inputFunc(void) {
  string input;
  int square = -1;
	bool invInput = true;

	//Loops until a valid input is entered
	while (invInput) {
		cin >> input;

		//Checks that the input is the correct length
		if (!(input.length() == 2)) {
			cout << "Invalid square, try again:\n";
			invInput = true;
			continue;
		}

		//Sets the starting number based on the column
	  char letter = input[0];
	  switch (letter) {
		  case 'a':
				square = 0;
				invInput = false;
				break;
			case 'b':
				square = 8;
				invInput = false;
				break;
			case 'c':
				square = 16;
				invInput = false;
				break;
			case 'd':
				square = 24;
				invInput = false;
				break;
			case 'e':
				square = 32;
				invInput = false;
				break;
			case 'f':
				square = 40;
				invInput = false;
				break;
			case 'g':
				square = 48;
				invInput = false;
				break;
			case 'h':
				square = 56;
				invInput = false;
				break;
			//Returns to start of loop if invalid input
			default:
				cout << "Invalid square, try again:\n";
				invInput = true;
				continue;
	  }

		//Adds on the row
		char number = input[1];
	  switch (number) {
		  case '1':
				square += 0;
				invInput = false;
				break;
			case '2':
				square += 1;
				invInput = false;
				break;
			case '3':
				square += 2;
				invInput = false;
				break;
			case '4':
				square += 3;
				invInput = false;
				break;
			case '5':
				square += 4;
				invInput = false;
				break;
			case '6':
				square += 5;
				invInput = false;
				break;
			case '7':
				square += 6;
				invInput = false;
				break;
			case '8':
				square += 7;
				invInput = false;
				break;
			//Returns to start of loop if invalid input
			default:
				cout << "Invalid square, try again:\n";
				invInput = true;
	  }
	}

  return square;
}

string encode(int code){



  return "";
}
