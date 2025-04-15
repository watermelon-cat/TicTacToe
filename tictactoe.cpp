#include<iostream>
using namespace std;

//function prototypes
void printBoard(const char board[3][3]);
void playerTurn(char board[3][3], char player);
bool checkWin(const char board[3][3]);
bool checkFull(const char board[3][3]);

int main() {
	char board[3][3] = { {'-', '-', '-',}, {'-', '-', '-'}, {'-', '-', '-'} }; // 2D array to hold board
	char player = 'X'; // keeps track of whose turn it is
	bool endGame = false; // runs the game loop

	cout << "Welcome to Tic-Tac-Toe!" << endl;
	while (endGame == false) { //GAME LOOP
		playerTurn(board, player); //get user input
		printBoard(board); //print current board

		if (checkWin(board) == true) { //check if there are 3 in a row
			cout << "Player " << player << " wins!" << endl;
			endGame = true; //quit game loop
		}
		else if (checkFull(board) == true) {
			cout << "It's a draw!\n";
			endGame = true;
		}

		if (player == 'X') // if player is X, change to Y
			player = 'Y';
		else if (player == 'Y')
			player = 'X';
		if (endGame == false)
			cout << "Player " << player << "'s turn!" << endl << endl;
	}
}

void printBoard(const char board[3][3]) {
	for (int i = 0; i < 3; i++) {  //handles rows
		for (int j = 0; j < 3; j++) {  //handles columns
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void playerTurn(char board[3][3], char player) {

	//declare row and col int variables
	int row; 
	int col;

	//ask user for row and col and store them
	if (player == 'X')
		cout << "Player X, type row and collumn to place X." << endl;
	else
		cout << "Player Y, type row and collumn to place O." << endl;
	
	cin >> row;
	cin >> col;

	//place the X or O into the board (minus 1 since the arrays start at 0)
	if (player == 'X')
		board[row - 1][col - 1] = 'X'; //place an X for player 1
	else board[row - 1][col - 1] = 'O';

	cout << endl;
}

bool checkWin(const char board[3][3]) {

	//check horizontal and vertical lines---------------------------------
	for (int i = 0; i < 3; i++) {
		//check rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
			return true;
		//check collumns
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
			return true;
	}
	//check diagonals-----------------------------------------------------
	//check top left to bottom right
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
		return true;
	//check top right to bottom left
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
		return true;

	return false; //you'll only get to thsi line if NONE of the above if statements return true
}

bool checkFull(const char board[3][3]) {

	for (int i = 0; i < 3; i++) { 
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '-')
				return false;
		}//end of inner loop (columns in each row)
		
	}//end of the outer loop (switches rows)
	return true;
}
