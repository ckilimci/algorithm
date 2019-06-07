#include <iostream>
#include <vector>

#define COL 3
#define ROW 3

#define X 1
#define O 2

class TicTacToe {
	std::vector<std::vector<int> > board;
	void print();
	void getInput(int, int&, int&);
	bool done();
	bool won(int);
	int won();
	public:
	TicTacToe();
	int game();
};

TicTacToe::TicTacToe() {
	board = std::vector<std::vector<int> >(ROW, std::vector<int>(COL));
}

void TicTacToe::print() {
	for(int i=0; i<ROW; i++) {
		for(int j=0; j<COL-1; j++) {
			int place = board[i][j];
			if (place == X) std::cout << "X|";
			else if (place == O) std::cout << "O|";
			else std::cout << " |";
		}
		int place = board[i][COL-1];
		if (place == X) std::cout << "X";
		else if (place == O) std::cout << "O";
		else std::cout << " ";
		std::cout << std::endl;
		if (i == ROW-1) continue;
		for(int j=0; j<COL*2-1; j++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TicTacToe::getInput(int turn, int& row, int& col) {
	std::cout << "Enter Row and Column for ";
	if (turn == X)
		std::cout << "X" << std::endl;
	else
		std::cout << "O" << std::endl;
	std::cout << "   Row?";
	std::cin >> row;
	std::cout << "Column?";
	std::cin >> col;
}

bool TicTacToe::won(int player) {
	bool winning = false;
	// Search for rows
	for(int r=0; r<ROW; r++) {
		winning = true;
		for(int c=0; c<COL; c++) {
			if (board[r][c] != player) {
				winning = false;
				break;
			}
		}
		if (winning) break;
	}
	if (winning) return winning;
	winning = false;
	// Search for columns
	for(int c=0; c<COL; c++) {
		winning = true;
		for(int r=0; r<ROW; r++) {
			if (board[r][c] != player) {
				winning = false;
				break;
			}
		}
		if (winning) break;
	}
	if (winning) return winning;
	winning = true;
	// Search for diagomal 1 
	for(int c=0; c<COL; c++) {
		if (board[c][c] != player) {
			winning = false;
			break;
		}
	}
	if (winning) return winning;
	winning = true;
	// Search for diagomal 2
	for(int c=0; c<COL; c++) {
		if (board[c][COL-c-1] != player) {
			winning = false;
			break;
		}
	}
	return winning;
}

bool TicTacToe::done() {
	for(int r=0; r<ROW; r++) {
		for(int c=0; c<COL; c++) {
			if (board[r][c] == 0) return false;
		}
	}
	return true;
}

int TicTacToe::won() {
	if (won(X)) return X;
	if (won(O)) return O;
	if (done()) return -1;
	return 0;
}

int TicTacToe::game() {
	print();
	int row, col;
	bool turn = true;
	while (won() == 0) {
		if (turn) {
			getInput(X, row, col);
			board[row][col] = X;
		} else {
			getInput(O, row, col);
			board[row][col] = O;
		}
		print();
		turn = !turn;
	}
	return 0;
}

int main() {
	std::cout << "Hello Tic Tac" << std::endl;
	TicTacToe tictactoe;
	tictactoe.game();
	return 0;
}
