#include <iostream>
using namespace std;

bool isWon(char player, char board[3][3]) {
	int count1stDiagonal = 0;
	for (int i = 0; i < 3; i++) {
		int countCol = 0;
		int countRow = 0;
		for (int j = 0; j < 3; j++) {
			//loops through rows increment countRow if the char matches player
			if (board[j][i] == player) {
				countRow++;
			}
			//loops through col increment countCol if the char matches player
			if (board[i][j] == player) {
				countCol++;
			}

		}
		//check 1st diagonal to see if there's a matching char
		//checks[0][0] [1][1] [2][2] for matching char
		if (board[i][i] == player) {
			count1stDiagonal++;
		}

		//if countRow=3 or countCol=3 that means there is 3 in a row on the board = win
		if (countRow == 3 || countCol == 3) return true;
	}

	//if first diagonal all match player then there is a win
	if (count1stDiagonal == 3) {
		return true;
	}

	//check 2nd diagonal if it's a win [0][2] [1][1] [2][0]
	int diagonal2 = 0;
	if (board[0][2] == player) diagonal2++;
	if (board[1][1] == player) diagonal2++;
	if (board[2][0] == player) diagonal2++;
	return diagonal2 == 3;
}


bool isDraw(char board[3][3]) {
	//If there's empty space on board continue game return false
	for (int i = 0; i < 9; i++) {
		if (board[0][i] == ' ') return false;
	}
	//if no empty space and neither player wins then it's a draw
	return !isWon('X', board) && !isWon('O', board);
}

void displayBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++) {
		cout << "\n-------------\n";
		//cout << i <<"= i\n";
		for (int j = 0; j < 3; j++) {
			//cout << j <<"= j\n";
			cout << "| " << board[i][j] << " ";
		}
		cout << "|";
	}
	cout << "\n-------------\n";
}
void makeAMove(char board[3][3], char player) {
	int row;
	int col;
	cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
	cin >> row;
	cout << "Enter a column (0, 1, 2) for player " << player << ": ";
	cin >> col;
	if (board[row][col] == ' ') {
		board[row][col] = player;
	}
	else {
		cout << "This cell is already occupied. Try a different cell\n";
		makeAMove(board, player);
	}
}

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}
