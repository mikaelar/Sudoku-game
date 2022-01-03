#include<iostream>
using namespace std;
const int N = 9;
const int SYMBOL = '_';
const int EASY = 1;
const int MEDIUM = 2;
const int HARD = 3;

void print(int random,int myArr[15][N][N], int number, char symbol) { 
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

bool isCorrect(int myArr[15][N][N], int row, int column, int number,int random) {

	for (int i = 0; i < N; i++) {
		if (myArr[random][i][column] == number) {
			return false;
		}
	}
	for (int i = 0; i < N; i++) {
		if (myArr[random][row][i] == number) {
			return false;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (myArr[random][i + (row - row % 3)][j + (column - column % 3)] == number) {
				return false;
			}
		}
	}
	return true;
}

int main() {

	long long int myArr[15][N][N] =
	{ { { 0,4,5,6,2,3,9,8,7},
	  {8,3,6,4,7,9,2,1,0},
	  {7,2,9,1,5,8,3,4,6},
	  {5,6,8,2,3,1,7,9,4},
	  {9,7,2,5,6,4,8,3,1},
	  {3,1,4,8,9,7,6,5,2},
	  {4,8,7,3,1,2,5,6,9},
	  {2,5,3,9,4,6,1,7,8},
	  {6,0,1,7,8,5,4,2,3} },

	{ { 0, 1, 7, 9, 4, 3, 8, 6, 2},
		{ 4,2,9,6,7,8,1,5,0 },
		{ 6,8,3,1,5,2,7,9,4 },
		{ 2,5,4,3,9,7,6,8,1 },
		{ 3,7,8,2,6,1,9,4,5 },
		{ 9,6,1,5,8,4,3,2,7 },
		{ 1,9,6,7,2,5,4,3,8, },
		{ 8,3,2,4,1,6,5,7,9 },
		{ 7,0,5,8,3,9,2,1,6 } },

	{ {0, 6, 4, 1, 3, 8, 7, 2, 9},
		{ 3,1,2,6,7,9,5,4,0 },
		{ 8,9,7,2,4,5,1,3,6 },
		{ 1,7,6,8,9,2,3,5,4 },
		{ 9,4,5,3,6,7,8,1,2 },
		{ 2,3,8,4,5,1,6,9,7 },
		{ 7,2,9,5,8,3,4,6,1 },
		{ 6,5,1,7,2,4,9,8,3 },
		{ 4,0,3,9,1,6,2,7,5 } },

	{ {0, 6, 8, 2, 3, 7, 4, 9, 1},
		{ 3,1,2,8,9,4,6,7,0 },
		{ 7,9,4,5,6,1,3,8,2 },
		{ 1,8,3,4,7,2,5,6,9 },
		{ 6,4,7,3,5,9,1,2,8 },
		{ 9,2,5,1,8,6,7,3,4 },
		{ 8,3,6,9,1,5,2,4,7 },
		{ 4,7,1,6,2,8,9,5,3 },
		{ 2,0,9,7,4,3,8,1,6 } },

	{ {0, 3, 6, 5, 1, 4, 9, 2, 7},
		{ 4,5,1,2,9,7,3,6,0 },
		{ 9,7,2,6,8,3,5,4,1 },
		{ 1,8,9,4,6,5,2,7,3 },
		{ 2,4,3,1,7,9,8,5,6 },
		{ 5,6,7,8,3,2,1,9,4 },
		{ 6,9,8,7,2,1,4,3,5 },
		{ 3,1,5,9,4,6,7,8,2 },
		{ 7,0,4,3,5,8,6,1,9 } },

	{ {0, 2, 3, 8, 4, 6, 1, 5, 9},
		{ 6,1,5,3,9,2,4,7,0 },
		{ 8,4,9,7,1,5,6,3,2 },
		{ 3,7,8,6,5,4,9,2,1 },
		{ 1,9,4,2,8,7,3,6,5 },
		{ 2,5,6,9,3,1,8,4,7 },
		{ 5,6,1,4,7,9,2,8,3 },
		{ 4,8,7,1,2,3,5,9,6 },
		{ 9,3,2,5,6,8,7,1,4 } },

	{ {0,2,7,1,5,8,9,4,6},
	  {6,1,9,4,3,7,5,8,0},
	  {5,4,8,9,6,2,7,1,3},
	  {1,8,6,5,7,4,3,2,9},
	  {4,3,2,6,8,9,1,5,7},
	  {9,7,5,3,2,1,4,6,8},
	  {7,6,4,2,1,3,8,9,5},
	  {8,5,1,7,9,6,2,3,4},
	  {2,9,3,8,4,5,6,7,1} },

	{ {0,8,9,4,2,1,7,3,6},
	  {4,6,2,5,7,3,8,1,0},
	  {7,3,1,8,9,6,2,5,4},
	  {8,9,3,2,4,5,6,7,1},
	  {6,1,7,3,8,9,5,4,2},
	  {2,4,5,1,6,7,9,8,3},
	  {1,2,6,7,5,4,3,9,8},
	  {9,5,4,6,3,8,1,2,7},
	  {3,7,8,9,1,2,4,6,5} },

	{ {0,5,8,2,9,3,4,1,7},
	  {7,4,1,5,6,8,9,2,0},
	  {9,3,2,1,7,4,5,6,8},
	  {3,5,8,9,2,1,7,4,6},
	  {1,6,7,4,8,5,2,3,9},
	  {4,2,9,7,3,6,8,5,1},
	  {2,7,4,3,1,9,6,8,5},
	  {8,9,3,6,5,2,1,7,4},
	  {5,1,6,8,4,7,3,9,2} },

	{ {0,5,3,8,4,7,6,2,9},
	  {9,4,8,2,6,1,5,3,0},
	  {7,6,2,3,5,9,8,1,4},
	  {2,7,5,6,9,3,4,8,1},
	  {8,1,4,7,2,5,3,9,6},
	  {6,3,9,4,1,8,7,5,2},
	  {5,2,6,9,3,4,1,7,8},
	  {4,8,1,5,7,2,9,6,3},
	  {3,9,7,1,8,6,2,4,5} },

	{ {0,2,1,6,5,8,9,4,7},
	  {7,8,4,3,1,9,2,6,0},
	  {9,5,6,7,2,4,1,3,8},
	  {5,4,9,1,3,2,7,8,6},
	  {6,7,2,4,8,5,3,1,9},
	  {8,1,3,9,7,6,5,2,4},
	  {1,9,5,8,6,3,4,7,2},
	  {2,6,7,5,4,1,8,9,3},
	  {} },

	{ {0,3,4,1,5,7,2,9,6},
	  {5,2,1,8,6,9,4,7,0},
	  {6,9,7,3,2,4,1,5,8},
	  {1,6,5,2,9,3,7,8,4},
	  {7,8,3,6,4,5,9,2,1},
	  {2,4,9,7,1,8,3,6,5},
	  {4,7,8,5,3,2,6,1,9},
	  {3,1,2,9,8,6,5,4,7},
	  {9,5,6,4,7,1,8,3,2} },

	{ {0,9,6,3,2,7,8,1,5},
	  {8,1,5,4,6,9,3,2,0},
	  {2,3,7,1,5,8,4,9,6},
	  {7,2,1,8,3,6,9,5,4},
	  {9,4,3,7,1,5,6,8,2},
	  {6,5,8,2,9,4,7,3,1},
	  {1,7,9,6,8,2,5,4,3},
	  {3,8,4,5,7,1,2,6,9},
	  {5,6,2,9,4,3,1,7,8} },

	{ {0,2,3,6,9,4,8,7,1},
	  {9,7,4,2,8,1,3,6,0},
	  {8,1,6,7,3,5,2,4,9},
	  {1,8,5,3,6,2,7,9,4},
	  {2,3,7,4,5,9,1,8,6},
	  {4,6,9,8,1,7,5,2,3},
	  {6,9,8,5,2,3,4,1,7},
	  {3,4,1,9,7,8,6,5,2},
	  {7,5,2,1,4,6,9,3,8} },


	{ {0,7,2,4,6,9,8,1,5},
	  {9,8,1,3,7,5,6,2,0},
	  {6,5,4,8,1,2,7,9,3},
	  {5,6,7,1,8,3,9,4,2},
	  {2,9,8,5,4,6,3,7,1},
	  {1,4,3,2,9,7,5,6,8},
	  {7,2,5,9,3,1,4,8,6},
	  {8,3,6,7,2,4,1,5,9},
	  {4,1,9,6,5,8,2,3,7} }
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
	cout << "Welcome to sudoku game. Please choose difficulty to play: 1 = easy, 2 = medium, 3 = hard: ";
	cin >> difficulty;
	cout << endl;
	if (difficulty == EASY)
		random = randomEasy;
	if (difficulty == MEDIUM)
		random = randomMedium;
	if (difficulty == HARD)
		random = randomHard;

	int zeroCounter = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (myArr[random][i][j] == 0) {
				zeroCounter++;
			}
		}
	}
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

	if (isCorrect(anotherArr, row, column, number, random))
		zeroCounter--;

	while (zeroCounter != 0) {
		if (isCorrect(anotherArr, row, column, number, random) || number == 0) {
			anotherArr[random][row][column] = number;

			print(random, anotherArr, number, (char)95);

			cout << endl;
			cout << "Insert a row: ";
			cin >> row;
			cout << "Insert a column: ";
			cin >> column;
			cout << "Insert a number: ";
			cin >> number;
			cout << endl;

		}
		if (!isCorrect(anotherArr, row, column, number, random)) {
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
			}
		}
		zeroCounter--;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (anotherArr[random][i][j] == 0)
				cout << number;
			else
			cout << anotherArr[random][i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	cout << "Congratulations! You solved the sudoku!" << endl;
	return 0;
}