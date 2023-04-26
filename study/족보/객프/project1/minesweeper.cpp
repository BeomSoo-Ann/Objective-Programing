#include "minesweeper.h"
void minesweeper(string input, string output)
{
	int SIZE = 8, t = 0;;
	char board[8][8];
	bool touchedBoard[8][8];
	bool gameOver = 0;

	ifstream fin;
	ofstream fout;
	fin.open(input);
	fout.open(output);
	
	if (fin.is_open()) {
		initTouched(touchedBoard);
		string command = "";


		while (!fin.eof()) {
			if (gameOver) break;

			if (command == "load") {
				fout << "Command: " << command;
				string file;
				fin >> file;
				fout << " " << file << endl;
				initBoard(board, file);
				//for (int i = 0; i < 8; i++) {
				//	for (int j = 0; j < 8; j++) {
				//		cout << board[i][j];
				//		;
				//	}
				//	cout << endl;
				//}	
			}

			if (command == "touch") {
				int x, y;
				fin >> x >> y;
				touchBoard(touchedBoard, x-1, y-1);
				t++;
				fout << "Command: " << command <<" " << x << " " << y << endl;
				if (board[x-1][y-1] == '*') gameOver = 1;
			}

			if (command == "display") {
				fout << "Command: " << command << endl;
				displayBoard(fout, board, touchedBoard, gameOver);
			}

			fin >> command;
		}
	}
	fin.close();
	
	gameOver = 1;
	fout << "Game Over" << endl << "~~~~~~~~~" << endl;
	displayBoard(fout, board, touchedBoard, gameOver);
	fout << "Spaces touched: " << t << endl;
	fout.close();

}

void initBoard(char board[][SIZE], string file)
{
	ifstream boardFile;
	boardFile.open(file);
	char a;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boardFile.get(a);
			board[i][j] = a;
		}
		boardFile.get(a);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int cnt = 0;
			if (board[i][j] != '*') {
				if (i != 0 && board[i - 1][j] == '*') cnt++;
				if (i != 7 && board[i + 1][j] == '*') cnt++;
				if (j != 0 && board[i][j - 1] == '*') cnt++;
				if (j != 7 && board[i][j + 1] == '*') cnt++;
				if (i != 0 && j != 0 && board[i - 1][j - 1] == '*') cnt++;
				if (i != 7 && j != 7 && board[i + 1][j + 1] == '*') cnt++;
				if (i != 0 && j != 7 && board[i - 1][j + 1] == '*') cnt++;
				if (i != 7 && j != 0 && board[i + 1][j - 1] == '*') cnt++;
				board[i][j] = cnt + 48;
			}
		}
	}
}



void displayBoard(ostream& out, char board[][SIZE], bool touchedBoard[][SIZE], bool gameOver)
{
	if (gameOver) {
		out << "Final Board" << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (touchedBoard[i][j] == true && board[i][j] == '*') out << board[i][j];
				else if (board[i][j] == '*') out << "@";
				else if (touchedBoard[i][j] == true) out << board[i][j];
				else out << '.';
			}
			out << endl;
		}
		out << endl;
	}
	else {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (touchedBoard[i][j] == true) out << board[i][j];
				else out << '.';
			}
			out << endl; 
		}
		out << endl;

	}
}

void initTouched( bool touchedBoard[][SIZE] )
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			touchedBoard[i][j] = false;
		}
	}
}

void touchBoard( bool board[][SIZE], int x, int y )
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		board[x][y] = true;
	}
}

int main(){
	minesweeper(/*Your command file path*/, /*Your output file path*/);
	
	return 0;
}