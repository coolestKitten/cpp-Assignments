#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N = 4;

void configureRandomly(vector<vector<int>> &board, vector<int>  &state) {

	srand(time(0));

	// for every column
	for (int i = 0; i < N; i++) {

		// Get a random row index
		state[i] = rand() % N;

		// place queen at randomized position
		board[state[i]][i] = 1;
	}
}


void printBoard(vector<vector<int>> board){

	for (int i = 0; i < N; i++) {
		cout << " ";
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void printState(vector<int> state){

	for (int i = 0; i < N; i++) {
		cout << " " << state[i] << " ";
	}
	cout << endl;
}

bool compareStates(vector<int> state1, vector<int> state2)
{

	for (int i = 0; i < N; i++) {
		if (state1[i] != state2[i]) {
			return false;
		}
	}
	return true;
}


void fill(vector<vector<int>> &board, int value){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = value;
		}
	}
}


int calculateObjective(vector<vector<int>> board, vector<int> state)
{
	int attacking = 0;

	int row, col;

	for (int i = 0; i < N; i++) {

		row = state[i], col = i - 1;
		while (col >= 0 && board[row][col] != 1) {
			col--;
		}
		if (col >= 0 && board[row][col] == 1) {
			attacking++;
		}

		row = state[i], col = i + 1;
		while (col < N && board[row][col] != 1) {
			col++;
		}
		if (col < N && board[row][col] == 1) {
			attacking++;
		}

		row = state[i] - 1, col = i - 1;
		while (col >= 0 && row >= 0 && board[row][col] != 1) {
			col--;
			row--;
		}
		if (col >= 0 && row >= 0 && board[row][col] == 1) {
			attacking++;
		}

		row = state[i] + 1, col = i + 1;
		while (col < N && row < N && board[row][col] != 1) {
			col++;
			row++;
		}
		if (col < N && row < N && board[row][col] == 1) {
			attacking++;
		}

		row = state[i] + 1, col = i - 1;
		while (col >= 0 && row < N && board[row][col] != 1) {
			col--;
			row++;
		}
		if (col >= 0 && row < N && board[row][col] == 1) {
			attacking++;
		}

		row = state[i] - 1, col = i + 1;
		while (col < N && row >= 0 && board[row][col] != 1) {
			col++;
			row--;
		}
		if (col < N && row >= 0 && board[row][col] == 1) {
			attacking++;
		}
	}

	return (int)(attacking / 2);
}


void generateBoard(vector<vector<int>> &board, vector<int> state) {
    fill(board, 0);
	for (int i = 0; i < N; i++) {
		board[state[i]][i] = 1;
	}
}


void copyState(vector<int> &state1, vector<int> state2) {
    
	for (int i = 0; i < N; i++) {
		state1[i] = state2[i];
	}
}

void getNeighbour(vector<vector<int>> &board, vector<int> &state) {

	vector<vector<int>> opBoard(N, vector<int>(N, 0));
	vector<int> opState(N, 0);

	copyState(opState, state);
	generateBoard(opBoard, opState);

	int opObjective = calculateObjective(opBoard, opState);

	vector<vector<int>> NeighbourBoard(N, vector<int>(N, 0));
	vector<int> NeighbourState(N, 0);

	copyState(NeighbourState, state);
	generateBoard(NeighbourBoard, NeighbourState);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (j != state[i]) {

				NeighbourState[i] = j;
				NeighbourBoard[NeighbourState[i]][i]= 1;
				NeighbourBoard[state[i]][i]= 0;

				int temp = calculateObjective(NeighbourBoard, NeighbourState);

				if (temp <= opObjective) {
					opObjective = temp;
					copyState(opState, NeighbourState);
					generateBoard(opBoard, opState);
				}

				NeighbourBoard[NeighbourState[i]][i] = 0;
				NeighbourState[i] = state[i];
				NeighbourBoard[state[i]][i] = 1;
			}
		}
	}

	copyState(state, opState);
	fill(board, 0);
	generateBoard(board, state);
}

void hillClimbing(vector<vector<int>> &board, vector<int> state)
{

	vector<vector<int>> neighbourBoard(N, vector<int>(N, 0));
	vector<int> neighbourState(N, 0);

	copyState(neighbourState, state);
	generateBoard(neighbourBoard, neighbourState);

	do {

		copyState(state, neighbourState);
		generateBoard(board, state);


		getNeighbour(neighbourBoard, neighbourState);

		if (compareStates(state, neighbourState)) {

            //printState(state);
			printBoard(board);
            
			break;
		}
		else if (calculateObjective(board, state) == calculateObjective(neighbourBoard, neighbourState)) {
			neighbourState[rand() % N]
				= rand() % N;
			generateBoard(neighbourBoard,
						neighbourState);
		}

	} while (true);
}


bool validateNumber(int target){
    return (target >= 4);
}

int main()
{
    cout << "Introducir valor de 'n': ";
    cin >> N; 
    while(cin.fail() || validateNumber(N) == false){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> N;
    }

	vector<int> state(N, 0);
	vector<vector<int>> board(N, vector<int>(N, 0));

	configureRandomly(board, state);

	
	hillClimbing(board, state);

	return 0;
}
