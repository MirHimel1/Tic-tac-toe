// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Draw();
int getPlayerInput();
int getAiInput();
int win();

int const X = 1;
int const O = 2;

int player = X;


char board[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int main()
{
	Draw();

	while (1) {

		if (player == 1)
		{
			board[getPlayerInput()] = 'X';
			system("CLS");
			Draw();
		}
		else if (player == 2) {

			board[getAiInput()] = 'O';
			system("CLS");
			Draw();
		}


		if (win() == 1) {
			//player 1 goes win
			std::cout << "*****************" << endl;
			std::cout << "**   You win   **" << endl;
			std::cout << "*****************" << endl;
			break;
		}
		else if (win() == 2) {
			//ai wins
			std::cout << "******************" << endl;
			std::cout << "**   You Lose   **" << endl;
			std::cout << "******************" << endl;
			break;
		}
		else if(win() == 3){

			if (player != O) player = O; else player = X; //switch player each turn
		}
	}
}

void Draw() {

	std::cout << "Pick a number from 1 to 9" << endl;

	std::cout << board[1] << " | " << board[2] << " | " << board[3] << endl;
	std::cout << "---------" << endl;
	std::cout << board[4] << " | " << board[5] << " | " << board[6] << endl;
	std::cout << "---------" << endl;
	std::cout << board[7] << " | " << board[8] << " | " << board[9] << endl;
}

int getPlayerInput() {

	int playerInput;
	std::cin >> playerInput;

	if (playerInput < 0 || playerInput > 9 || board[playerInput] == 'X' || board[playerInput] == 'O') {
		std::cout << "INVALID NUMBER" << endl;
		getPlayerInput();
	}
	else {
		return playerInput;
	}
}

int getAiInput() {


	// Defend Row
	if (board[3] == 'O' && board[2] == 'O' && board[1] == '1') return 1;
	else if (board[6] == 'O' && board[5] == 'O' && board[4] == '4') return 4;
	else if (board[9] == 'X' && board[8] == 'X' && board[7] == '7') return 7;

	if (board[1] == 'O' && board[3] == 'O' && board[2] == '2') return 2;
	else if (board[4] == 'O' && board[6] == 'O' && board[5] == '5') return 5;
	else if (board[7] == 'O' && board[9] == 'O' && board[8] == '8') return 8;

	if (board[1] == 'O' && board[2] == 'O' && board[3] == '3') return 3;
	else if (board[4] == 'O' && board[5] == 'O' && board[6] == '6') return 6;
	else if (board[7] == 'O' && board[8] == 'O' && board[9] == '9') return 9;


	// Defend Column
	if (board[7] == 'O' && board[4] == 'O' && board[1] == '1') return 1;
	else if (board[8] == 'O' && board[5] == 'O' && board[2] == '2') return 2;
	else if (board[9] == 'O' && board[6] == 'O' && board[3] == '3') return 3;

	if (board[7] == 'O' && board[1] == 'O' && board[4] == '4') return 4;
	else if (board[8] == 'O' && board[2] == 'O' && board[5] == '5') return 5;
	else if (board[9] == 'O' && board[3] == 'O' && board[6] == '6') return 6;

	if (board[4] == 'O' && board[1] == 'O' && board[7] == '7') return 7;
	else if (board[5] == 'O' && board[2] == 'O' && board[8] == '8') return 8;
	else if (board[6] == 'O' && board[3] == 'O' && board[9] == '9') return 9;


	// Defend Diagonals
	if (board[7] == 'O' && board[5] == 'O' && board[3] == '3') return 3;
	else if (board[7] == 'O' && board[3] == 'O' && board[5] == '5') return 5;
	else if (board[5] == 'O' && board[3] == 'O' && board[7] == '7') return 7;

	if (board[9] == 'O' && board[5] == 'O' && board[1] == '1') return 1;
	else if (board[9] == 'O' && board[1] == 'o' && board[5] == '5') return 5;
	else if (board[5] == 'O' && board[1] == 'O' && board[9] == '9') return 9;


	


	// Check Row Wins
	if (board[3] == 'X' && board[2] == 'X' && board[1] == '1') return 1;
	else if(board[6] == 'X' && board[5] == 'X' && board[4] == '4') return 4;
	else if (board[9] == 'X' && board[8] == 'X' && board[7] == '7') return 7;

	if (board[1] == 'X' && board[3] == 'X' && board[2] == '2') return 2;
	else if (board[4] == 'X' && board[6] == 'X' && board[5] == '5') return 5;
	else if (board[7] == 'X' && board[9] == 'X' && board[8] == '8') return 8;

	if (board[1] == 'X' && board[2] == 'X' && board[3] == '3') return 3;
	else if (board[4] == 'X' && board[5] == 'X' && board[6] == '6') return 6;
	else if (board[7] == 'X' && board[8] == 'X' && board[9] == '9') return 9;


	// Check Column Wins
	if (board[7] == 'X' && board[4] == 'X' && board[1] == '1') return 1;
	else if (board[8] == 'X' && board[5] == 'X' && board[2] == '2') return 2;
	else if (board[9] == 'X' && board[6] == 'X' && board[3] == '3') return 3;

	if (board[7] == 'X' && board[1] == 'X' && board[4] == '4') return 4;
	else if (board[8] == 'X' && board[2] == 'X' && board[5] == '5') return 5;
	else if (board[9] == 'X' && board[3] == 'X' && board[6] == '6') return 6;

	if (board[4] == 'X' && board[1] == 'X' && board[7] == '7') return 7;
	else if (board[5] == 'X' && board[2] == 'X' && board[8] == '8') return 8;
	else if (board[6] == 'X' && board[3] == 'X' && board[9] == '9') return 9;


	// Check Diagonals
	if (board[7] == 'X' && board[5] == 'X' && board[3] == '3') return 3;
	else if (board[7] == 'X' && board[3] == 'X' && board[5] == '5') return 5;
	else if (board[5] == 'X' && board[3] == 'X' && board[7] == '7') return 7;

	if (board[9] == 'X' && board[5] == 'X' && board[1] == '1') return 1;
	else if (board[9] == 'X' && board[1] == 'X' && board[5] == '5') return 5;
	else if (board[5] == 'X' && board[1] == 'X' && board[9] == '9') return 9;


	//pick 5 if empty
	if (board[5] == '5') return 5;


	//multiply with time later
	int rendomNumber = rand() % 9 + 1;
	if (board[rendomNumber] == 'X' || board[rendomNumber] == 'O') {
		getAiInput();
	}
	else {
		cout << "rendom number is " << rendomNumber << endl;
		return rendomNumber;
	}
}

int win() {

	//Player Win Check
	//raw
	if (board[1] == 'X' && board[2] == 'X' && board[3] == 'X') return 1;
	else if (board[4] == 'X' && board[5] == 'X' && board[6] == 'X') return 1;
	else if (board[7] == 'X' && board[8] == 'X' && board[9] == 'X') return 1;

	//Column
	if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return 1;
	else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') return 1;
	else if (board[3] == 'X' && board[6] == 'X' && board[9] == 'X') return 1;

	//Diagonals
	if (board[1] == 'X' && board[5] == 'X' && board[9] == 'X') return 1;
	else if (board[3] == 'X' && board[5] == 'X' && board[7] == 'X') return 1;



	//AI Win Check
	//raw
	if (board[1] == 'O' && board[2] == 'O' && board[3] == 'O') return 2;
	else if (board[4] == 'O' && board[5] == 'O' && board[6] == 'O') return 2;
	else if (board[7] == 'O' && board[8] == 'O' && board[9] == 'O') return 2;

	//Column
	if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') return 2;
	else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') return 2;
	else if (board[3] == 'O' && board[6] == 'O' && board[9] == 'O') return 2;

	//Diagonals
	if (board[1] == 'O' && board[5] == 'O' && board[9] == 'O') return 2;
	else if (board[3] == 'O' && board[5] == 'O' && board[7] == 'O') return 2;

	return 3;
}