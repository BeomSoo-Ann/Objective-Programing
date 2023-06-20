#include "minesweeper.h"

const int SIZE = 8;
using Matrix = char[SIZE][SIZE];

void minesweeper(string commands, string output);
void _load_(string board, Matrix &mat1, Matrix &mat2);
int _touch_(int x, int y, Matrix &mat1, Matrix &mat2);
void _display_(Matrix &mat, ofstream &file);
int find_mines(int x, int y, Matrix &mat);

int main()
{
	cout << "Testing minesweeper" << endl;

	minesweeper(".//test1commands.txt", "test1_output_mine.txt");
	minesweeper(".//test2commands.txt", "test2_output_mine.txt");
	minesweeper(".//test3commands.txt", "test3_output_mine.txt");
	minesweeper(".//test4commands.txt", "test4_output_mine.txt");
	minesweeper(".//test5commands.txt", "test5_output_mine.txt");
	minesweeper(".//test6commands.txt", "test6_output_mine.txt");
	minesweeper(".//test7commands.txt", "test7_output_mine.txt");
	minesweeper(".//test8commands.txt", "test8_output_mine.txt");
	minesweeper(".//test9commands.txt", "test9_output_mine.txt");
	minesweeper(".//test10commands.txt", "test10_output_mine.txt");

	return 0;
}

void minesweeper(string commands, string output)
{
	Matrix minefield;
	Matrix detectedfield;
	ifstream fin;
	ofstream fout;
	fin.open(commands);
	fout.open(output);

	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) // initialize detectedfield
		{
			detectedfield[i][j] = '.';
		}
	}

	while (1)
	{
		if (count == 54)
		{
			fout << "Game Over" << endl;
			fout << "~~~~~~~~~" << endl;
			fout << "Final Board" << endl;

			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					fout << detectedfield[i][j];
				}
				fout << endl;
			}
			fout << endl;

			fout << "Spaces touched: " << count << endl;

			break;
		}

		string line;
		getline(fin, line);

		string command = "";
		command = line.substr(0, line.find(" "));

		if (command == "load")
		{
			fout << "Command: " << line << endl;
			string board = "";
			board = line.substr(line.find(" ") + 1, line.length() - line.find(" ") - 2);
			_load_(board, minefield, detectedfield);
			continue;
		}

		if (command == "touch")
		{
			fout << "Command: " << line << endl;
			int x = 0;
			int y = 0;
			x = line[line.find(" ") + 1] - '0';
			y = line[line.find(" ") + 3] - '0';

			int check = _touch_(x, y, minefield, detectedfield);
			count++;

			if (check == 1)
			{
				fout << "Game Over" << endl;
				fout << "~~~~~~~~~" << endl;
				fout << "Final Board" << endl;

				for (int i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						fout << detectedfield[i][j];
					}
					fout << endl;
				}
				fout << endl;

				fout << "Spaces touched: " << count << endl;

				break;
			}

			continue;
		}

		if (command == "display\r")
		{
			fout << "Command: " << line << endl;
			_display_(detectedfield, fout);
			continue;
		}

		else
		{
			fout << "Game Over" << endl;
			fout << "~~~~~~~~~" << endl;
			fout << "Final Board" << endl;

			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (minefield[i][j] == '*')
					{
						minefield[i][j] = '@';
					}
					fout << minefield[i][j];
				}
				fout << endl;
			}
			fout << endl;

			fout << "Spaces touched: " << count << endl;

			break;
		}
	}

	fin.close();
	fout.close();
}

void _load_(string board, Matrix &mat1, Matrix &mat2)
{
	ifstream fin_board;
	fin_board.open(board);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			fin_board >> mat1[i][j];

			if (mat1[i][j] == '*')
			{
				mat2[i][j] = '@';
			}
		}
	}

	fin_board.close();
}

int _touch_(int x, int y, Matrix &mat1, Matrix &mat2)
{
	int lose;

	if (mat1[x - 1][y - 1] == '*')
	{
		mat2[x - 1][y - 1] = '*';
		lose = 1;
		return lose;
	}

	else
	{
		int mines = find_mines(x - 1, y - 1, mat1);
		char count_mines = mines + '0';
		mat2[x - 1][y - 1] = count_mines;

		lose = 0;
		return lose;
	}
}

void _display_(Matrix &mat, ofstream &file)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (mat[i][j] == '@')
			{
				mat[i][j] = '.';
			}

			file << mat[i][j];
		}
		file << endl;
	}
	file << endl;
}

int find_mines(int x, int y, Matrix &mat)
{
	int count = 0;

	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < SIZE && j >= 0 && j < SIZE)
			{
				if (mat[i][j] == '*' || mat[i][j] == '@')
				{
					count++;
				}
			}
		}
	}

	return count;
}