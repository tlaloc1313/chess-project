#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::stoi;

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
			default:
				cout << "Invalid square, try again:\n";
				invInput = true;
				continue;
	  }

		//Adds the remainder based on the row
		char number = input[1];
		string numStr(&number);
		int numInt = stoi(numStr,nullptr);
		if (numInt >= 1 && numInt <= 8) {
			square =+ numInt - 1;
			invInput = false;
		} else {
			cout << "Invalid square, try again:\n";
			invInput = true;
		}
	}

  return square;
}

string encode(int code){



  return "";
}
