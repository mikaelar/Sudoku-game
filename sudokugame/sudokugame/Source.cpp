#include<iostream>
using namespace std;
const int N = 9;
const int SYMBOL = '_';
const int EASY = 1;
const int MEDIUM = 2;
const int HARD = 3;

void print(int random,int myArr[15][N][N], int number, char symbol,int row,int column) { 

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

bool isReady(int myArr[15][N][N], int row, int column, int number, int random) {

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

bool isCorrect(int myArr[15][N][N], int row, int column, int number,int random) {

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

	long long int myArr[15][N][N] = {
	{ { 0,4,5,0,2,3,9,8,7},
	  {8,0,6,4,7,9,2,1,0},
	  {7,0,9,0,5,0,3,0,6},
	  {5,6,0,2,0,1,7,9,4},
	  {9,0,2,0,6,4,0,3,1},
	  {3,0,4,8,0,7,0,5,2},
	  {4,0,7,0,1,2,5,0,9},
	  {2,5,0,9,4,6,0,7,8},
	  {6,0,1,7,0,5,0,2,0} },

	{   { 0,1,7,0,4,0,8,0,2},
		{ 4,2,9,6,0,8,0,5,0 },
		{ 6,8,3,0,5,2,7,9,4 },
		{ 2,5,4,0,9,7,0,8,1 },
		{ 3,7,0,2,6,0,9,4,5 },
		{ 0,0,1,5,0,4,3,2,0 },
		{ 1,9,6,0,2,5,4,0,8, },
		{ 0,3,2,4,1,0,5,7,9 },
		{ 7,0,5,8,3,0,2,1,6 } },

	{ {0, 6, 4, 0, 3, 8, 7, 2, 9},
		{ 3,1,2,6,7,9,5,4,0 },
		{ 8,9,7,0,4,5,1,0,6 },
		{ 1,0,6,8,0,2,0,5,4 },
		{ 9,0,5,0,6,7,0,1,2 },
		{ 2,0,0,4,0,1,6,9,7 },
		{ 0,2,9,0,8,3,4,0,1 },
		{ 0,5,1,7,0,0,9,0,3 },
		{ 4,0,3,9,0,6,2,7,0 } },

	{ {0, 6, 8, 0, 3, 7, 0, 9, 1},
		{ 3,0,2,8,9,4,6,7,0 },
		{ 7,9,4,0,6,0,3,0,2 },
		{ 1,8,3,4,0,2,5,6,9 },
		{ 6,4,0,3,5,9,0,2,0 },
		{ 0,2,5,1,0,6,0,3,4 },
		{ 8,3,6,0,1,0,2,0,7 },
		{ 4,7,1,6,2,0,9,5,3 },
		{ 2,0,9,7,4,3,8,1,6 } },

	{ {0, 3, 6, 0, 1, 0, 9, 2, 7},
		{ 4,5,1,2,9,0,3,6,0 },
		{ 9,0,2,0,8,3,0,4,1 },
		{ 1,8,0,0,6,0,2,0,3 },
		{ 2,0,3,1,0,9,0,5,0 },
		{ 5,6,7,8,0,2,1,0,4 },
		{ 0,0,8,0,2,0,4,0,5 },
		{ 3,1,0,9,0,6,7,0,2 },
		{ 7,0,4,3,0,8,6,1,9 } },

	{ {0, 2, 3, 0, 4, 6, 0, 5, 0},
		{ 6,0,5,3,0,0,4,7,0 },
		{ 0,4,9,0,1,0,6,3,0 },
		{ 3,0,0,6,0,4,0,2,1 },
		{ 1,0,4,2,0,0,3,0,0 },
		{ 2,5,0,9,3,0,8,4,7 },
		{ 0,6,1,0,7,0,2,0,3 },
		{ 4,0,7,1,0,3,0,9,0 },
		{ 9,0,2,5,6,8,7,0,4 } },

	{ {0,2,7,0,5,8,0,4,6},
	  {6,1,0,4,3,0,0,8,0},
	  {5,4,8,9,0,2,7,0,3},
	  {0,8,0,0,7,0,3,2,9},
	  {4,0,2,0,8,9,0,0,7},
	  {0,7,5,0,2,0,4,6,0},
	  {0,6,4,0,1,0,8,0,5},
	  {8,0,1,7,0,6,0,3,4},
	  {2,0,3,8,0,5,0,7,0} },

	{ {0,8,9,0,2,0,0,3,0},
	  {4,0,2,5,0,3,8,1,0},
	  {0,3,1,0,9,0,2,5,4},
	  {8,9,0,2,0,5,0,0,1},
	  {6,0,7,0,0,9,5,0,0},
	  {0,4,0,1,6,0,9,8,3},
	  {1,0,6,0,5,4,3,0,8},
	  {9,5,4,6,0,8,1,0,7},
	  {0,0,8,0,1,0,0,6,5} },

	{ {0,5,8,0,9,3,4,0,7},
	  {7,0,1,5,6,8,9,2,0},
	  {9,3,2,0,7,4,0,6,8},
	  {3,5,8,9,2,1,0,4,6},
	  {1,6,7,4,8,5,2,3,9},
	  {0,2,9,0,3,6,0,5,1},
	  {2,0,4,0,1,9,6,0,5},
	  {0,9,0,6,0,2,1,7,4},
	  {5,0,6,8,4,0,3,0,2} },

	{ {0,5,3,0,4,0,6,0,9},
	  {9,4,0,2,6,0,5,3,0},
	  {7,0,2,0,5,0,0,1,0},
	  {2,0,5,6,0,3,4,8,1},
	  {0,1,4,0,2,5,0,9,6},
	  {0,3,9,4,0,8,0,5,0},
	  {0,2,6,0,3,4,1,0,0},
	  {4,0,1,0,7,0,0,6,3},
	  {3,0,0,1,0,6,2,0,5} },

	{ {0,2,0,0,5,8,0,4,0},
	  {7,0,0,3,0,9,2,6,0},
	  {9,5,6,0,2,4,1,0,8},
	  {5,0,9,1,0,2,7,0,6},
	  {6,7,0,4,0,5,3,1,0},
	  {0,1,3,0,7,0,5,0,4},
	  {1,9,0,0,6,3,0,0,2},
	  {0,0,8,0,9,0,0,5,1},
	  {2,0,7,5,0,1,8,9,0},
	   },

	{ {0,3,4,0,5,0,2,0,6},
	  {5,2,0,8,0,9,0,7,0},
	  {6,0,7,0,2,0,1,5,0},
	  {0,6,0,0,9,3,7,8,4},
	  {7,0,0,0,4,0,9,0,0},
	  {0,4,0,7,0,8,0,6,5},
	  {4,0,8,0,3,0,6,0,9},
	  {0,1,0,9,0,6,5,0,0},
	  {9,0,0,4,0,1,0,3,2} },

	{ {0,0,6,0,2,7,0,0,5},
	  {8,1,0,4,0,9,0,2,0},
	  {2,0,0,0,5,0,4,0,6},
	  {7,0,1,0,3,6,0,5,4},
	  {9,0,3,0,1,0,0,8,0},
	  {0,5,0,2,9,0,7,0,1},
	  {1,0,9,0,8,0,5,0,3},
	  {0,8,0,5,0,1,0,6,9},
	  {5,0,2,0,4,0,1,0,8} },

	{ {0,2,3,0,0,4,0,7,0},
	  {0,0,4,2,0,1,3,0,0},
	  {8,0,6,0,3,0,2,4,9},
	  {0,8,5,0,0,0,7,0,0},
	  {2,3,7,0,5,0,1,8,0},
	  {4,0,9,8,1,0,5,0,3},
	  {0,0,8,0,2,3,4,0,0},
	  {3,0,1,0,0,0,6,5,0},
	  {7,0,2,1,0,6,0,3,8} },


	{ {0,7,2,0,6,0,8,0,5},
	  {9,8,0,3,0,5,0,2,0},
	  {6,0,4,0,1,2,0,9,3},
	  {0,0,7,1,0,0,9,4,0},
	  {2,9,0,5,0,6,0,7,1},
	  {0,4,0,2,9,7,0,6,0},
	  {7,0,5,0,3,1,4,0,6},
	  {8,3,0,7,0,4,0,5,0},
	  {4,0,9,0,5,0,2,0,7} }
	};

	//from 0 to 4
	int randomEasy;
	srand(time(NULL));
	randomEasy = rand() % 5 + 0;

	//from 5 to 9
	int randomMedium;
	srand(time(NULL));
	randomMedium = rand() % 5 + 5;

	//from 10 to 14
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
			if (myArr[random][i][j] == 0)
				cout << "_" << " ";
			else
				cout << myArr[random][i][j] << " ";
		}
		cout << endl;
	}

	int anotherArr[15][N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			anotherArr[random][i][j] = myArr[random][i][j];
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

	if (row < 0 || row > 9 || column < 0 || column>9 || number > 9 || number < 0) {
		while (row < 0 || row > 9 || column < 0 || column>9 || number > 9 || number < 0) {
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

			if (row < 0 || row > 9 || column < 0 || column>9 || number > 9 || number < 0) {
				while (row < 0 || row > 9 || column < 0 || column>9 || number > 9 || number < 0) {
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

				if (row < 0 || row > 9 || column < 0 || column>9 || number > 9 || number < 0) {
					while (row < 0 || row > 9 || column < 0 || column>9 || number > 9 || number < 0) {
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