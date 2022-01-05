/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Mikaela Rumenova Ezekieva
* @idnumber 1MI0600003
* @compiler VC
*
* <cpp file with all the functions, neccessary for the game>
*
*/

#include<iostream>
#include<fstream>
using namespace std;
const int N = 9; //counter for the number of rows and columns 
const int NUMBER_OF_DIFFICULTIES = 15;
const int SYMBOL = '_';
const int EASY = 1; //first level of difficulty
const int MEDIUM = 2; //second level of difficulty
const int HARD = 3; //third level of difficulty

//function to print the sudoku every time
void print(int random,int myArr[NUMBER_OF_DIFFICULTIES][N][N], int number, char symbol,int row,int column) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				 if (myArr[random][i][j] == 0) {
					cout << symbol << " ";
				}
				else
					cout << myArr[random][i][j] << " ";
			}
			cout << endl;
		}
}

//function to check whether the sudoku is ready
bool isReady(int myArr[NUMBER_OF_DIFFICULTIES][N][N], int row, int column, int number, int random) {

	int counterReady = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (myArr[random][i][j] != 0) {
				counterReady++;
			}
		}
	}
	if (counterReady == 80 && number!=0)
		return true;

	return false;
}

//function to check whether the input number is correct for the position that is pointed out
bool isCorrect(int myArr[NUMBER_OF_DIFFICULTIES][N][N], int row, int column, int number,int random) {

	for (int i = 0; i < N; i++) {
		if (myArr[random][i][column] == number&&number!=0) {
			return false;
		}
	}
	for (int i = 0; i < N; i++) {
		if (myArr[random][row][i] == number && number != 0) {
			return false;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (myArr[random][i + (row - row % 3)][j + (column - column % 3)] == number && number != 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {

	int input;
	ifstream sudokuFile;
	sudokuFile.open("sudoku.txt");
	long int sudokuArray[NUMBER_OF_DIFFICULTIES][N][N];
	for (int i = 0; i < 15 && !sudokuFile.eof(); i++) {
		for (int j = 0; j < N && !sudokuFile.eof(); j++) {
			for (int m = 0; m < N && !sudokuFile.eof(); m++) {
				sudokuFile >> input;
				sudokuArray[i][j][m] = input;
			}
		}
	}
	sudokuFile.close();

	//sudokus number in the file: from 0 to 4
	int randomEasy;
	srand(time(NULL));
	randomEasy = rand() % 5 + 0;

	//sudokus number in the file: from 5 to 9
	int randomMedium;
	srand(time(NULL));
	randomMedium = rand() % 5 + 5;

	//sudokus number in the file: from 10 to 14
	int randomHard;
	srand(time(NULL));
	randomHard = rand() % 5 + 10;

	int random = 0;
	int difficulty = 0;
	cout << " Welcome to sudoku game." << endl;
	cout << " 1 = easy,\n 2 = medium,\n 3 = hard \n Please choose difficulty to play: ";
	cin >> difficulty;

	if (difficulty < 1 || difficulty>3) {
		while (difficulty < 1 || difficulty>3) {
			cout << " You have choosen wrong level of difficulty. Please insert another between 1 and 3: ";
			cin >> difficulty;
		}
	}

	cout << endl;
	if (difficulty == EASY)
		random = randomEasy;
	if (difficulty == MEDIUM)
		random = randomMedium;
	if (difficulty == HARD)
		random = randomHard;

	cout << "Here is your sudoku: ";
	cout << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sudokuArray[random][i][j] == 0)
				cout << "_" << " ";
			else
				cout << sudokuArray[random][i][j] << " ";
		}
		cout << endl;
	}

	int anotherArr[NUMBER_OF_DIFFICULTIES][N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			anotherArr[random][i][j] = sudokuArray[random][i][j];
		}
	}

	cout << endl;
	int row, column, number;
	cout << "Insert a row: ";
	cin >> row;
	cout << "Insert a column: ";
	cin >> column;
	cout << "Insert a number: ";
	cin >> number;
	cout << endl;

	if (row < 0 || row > N || column < 0 || column> N || number > N || number < 0) {
		while (row < 0 || row > N || column < 0 || column> N || number > N || number < 0) {
			cout << "Please insert correct data:";
			cout << endl;
			cout << "Insert a row: ";
			cin >> row;
			cout << "Insert a column: ";
			cin >> column;
			cout << "Insert a number: ";
			cin >> number;
			cout << endl;
		}
	}

	while (!isReady(anotherArr, row, column, number, random)) {
		if (isCorrect(anotherArr, row, column, number, random) || number == 0) {
			if (number == 0 && anotherArr[random][row][column] != 0) {
				anotherArr[random][row][column] = 0;
			}
			anotherArr[random][row][column] = number;

			print(random, anotherArr, number, (char)95, row, column);

			cout << endl;
			cout << "Insert a row: ";
			cin >> row;
			cout << "Insert a column: ";
			cin >> column;
			cout << "Insert a number: ";
			cin >> number;
			cout << endl;

			if (row < 0 || row > N || column < 0 || column> N || number > N || number < 0) {
				while (row < 0 || row > N || column < 0 || column>N || number > N || number < 0) {
					cout << endl;
					cout << "Please insert correct data:";
					cout << endl;
					cout << "Insert a row: ";
					cin >> row;
					cout << "Insert a column: ";
					cin >> column;
					cout << "Insert a number: ";
					cin >> number;
					cout << endl;
				}
			}

		}
		if (!isCorrect(anotherArr, row, column, number, random) && number != 0) {
			while (!isCorrect(anotherArr, row, column, number, random)) {
				cout << endl;
				cout << "You have to insert another values!" << endl;
				cout << endl;
				cout << "Insert a row: ";
				cin >> row;
				cout << "Insert a column: ";
				cin >> column;
				cout << "Insert a number: ";
				cin >> number;
				cout << endl;

				if (row < 0 || row > N || column < 0 || column> N || number > N || number < 0) {
					while (row < 0 || row > N || column < 0 || column> N || number > N || number < 0) {
						cout << endl;
						cout << "Please insert correct data:";
						cout << endl;
						cout << "Insert a row: ";
						cin >> row;
						cout << "Insert a column: ";
						cin >> column;
						cout << "Insert a number: ";
						cin >> number;
						cout << endl;
					}
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (anotherArr[random][i][j] == 0)
				cout << number << " ";
			else
				cout << anotherArr[random][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Congratulations! You solved the sudoku!" << endl;
	return 0;
}