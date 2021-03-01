#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);

void displayBoard(char board[3][3])
{
    for(int i = 0; i < 3; i++){
		cout<<"\n-------------\n";
		//cout << i <<"= i\n";
		for(int j = 0; j < 3; j++){
			//cout << j <<"= j\n";
			cout <<"| "<<board[i][j]<<" ";
		}
		cout<<"|";
	}
	cout<<"\n-------------\n";
}
void makeAMove(char board[3][3], char player){
	int row;
	int col;
	cout << "Enter a row (0, 1, 2) for player "<< player<<"   : ";
	cin >>  row;
	cout << "Enter a column (0, 1, 2) for player "<< player<<": ";
	cin >> col;
	if(board[row][col]==' '){
		board[row][col]=player;
	} else{
		cout <<"This cell is already occupied. Try a different cell\n";
		makeAMove(board,player);
	}
}

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);
	while(true){
		makeAMove(board, 'X');
		displayBoard(board);
	}
	/*
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
	}*/

	return 0;
} 
