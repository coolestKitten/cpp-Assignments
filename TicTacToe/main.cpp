#include <iostream>
#include <vector>

using namespace std;

// method that checks if a square is free 
// args: board, row index, col index
// returns a boolean
bool isFree(vector<vector<int>> board, int row, int col){
    return (board[row][col] == -1);
}

/*
// method that checks if a given player has won the game
bool checkWin(vector<vector<int>> board, int row, int col){
    
    return false;
}
*/





// cpu should always mirror moves
// method that gets the mirror index of a given square
bool mirrorMove(vector<vector<int>> &board, vector<int> corMirrX, vector<int> corMirrY, vector<int> edMirrX, vector<int> edMirrY,int mark){
    // check corner mirrors
    for(int i = 0; i< 4; i++){
        if(isFree(board, corMirrX[i], corMirrY[i])){
            board[i][i] = mark;
            return true;
        }
    }
    // check edge mirrors
    for(int i = 0; i< 4; i++){
        if(isFree(board, edMirrX[i], edMirrY[i])){
            board[i][i] = mark;
            return true;
        }
    }
    return false;

}

// how do we automate response?
// cpu places mark at 5, automatically
// if it's occupied, evaluate corners first
bool placeMark(vector<vector<int>> &board, vector<int> cornersX, vector<int> cornersY, vector<int> edgesX, vector<int> edgesY, int mark){
    // check the center if it's free
    if (isFree(board, 1, 1)){
        board[1][1] = mark;
        return true;
    }
    // check the corners next, mirror move if necessary
    // corners = {0, 0}{2, 0}{0, 2}{2, 2}
    for(int i = 0; i< 4; i++){
        if(isFree(board, cornersX[i], cornersY[i])){
            board[i][i] = mark;
            return true;
        }
    }
    
    // check the edges, mirror move if necessary
    for(int i = 0; i< 4; i++){
        if(isFree(board, edgesX[i], edgesY[i])){
            board[i][i] = mark;
            return true;
        }
    }
    return false;
}

void printBoard(vector<vector<int>> board){
    for(int i = 0; i< 3; i++){
        for(int j = 0; j< 3; i++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// method that houses the game itself
void ticTacToe(vector<vector<int>> &board, vector<int> cornersX, vector<int> cornersY, vector<int> edgesX, vector<int> edgesY,
                vector<int> corMirrX, vector<int> corMirrY, vector<int> edMirrX, vector<int> edMirrY,int mark, int timer){
    int playerMove;

    if(mark == 0){
        // place mark first, if not, mirror move
        if(placeMark(board, cornersX, cornersY, edgesX, edgesY, mark)){
            printBoard(board);
        } else if (mirrorMove(board, corMirrX, corMirrY, edMirrX, edMirrY, mark)){
            printBoard(board);
        } else {
            printBoard(board);

        }
    } else {
        cout << "Player's Turn: "; 
        cin >> playerMove;
        // place player mark depending on input 
        switch(playerMove){
            case 1:
                board[0][0] = mark;
                break;
            case 2:
                board[1][0] = mark;
                break;
            case 3:
                board[2][0] = mark;
                break;
            case 4:
                board[0][1] = mark;
                break;
            case 5:
                board[1][1] = mark;
                break;
            case 6: 
                board[2][1] = mark;
                break;
            case 7:
                board[0][2] = mark;
                break;
            case 8:
                board[1][2] = mark;
                break;
            case 9:
                board[2][2] = mark;
                break;
        }
    }

    if (timer ==  0){
        return;
    } else if (timer % 2 == 0){
        ticTacToe(board, cornersX, cornersY, edgesX, edgesY, corMirrX, corMirrY, edMirrX, edMirrY, 1, timer -1);
    } else {
        ticTacToe(board, cornersX, cornersY, edgesX, edgesY, corMirrX, corMirrY, edMirrX, edMirrY, 0, timer -1);

    }
    

}

int main(){
    vector<vector<int>> board(3, vector<int>(3, -1));

    // -1 = free
    // 0 = player 1
    // 1 = player 2

    /*
    input for placing marks
    {1, 2, 3}
    {4, 5, 6}
    {7, 8, 9}
    
    */
    int timer = 9;
    int mark = 0;
    bool first = true;

    vector<int> cornerRows {0, 2, 0, 2};
    vector<int> cornerCols {0, 0, 2, 2};
    // edges = {0,1}{1,2}{1,0}{2,1}
    vector<int> edgesRow {0, 1, 1, 2};
    vector<int> edgesCol {1, 2, 0, 1};

    vector<int> cornerMirrR {2, 0, 2, 0};
    vector<int> cornerMirrC {2, 2, 0, 0};
    vector<int> edMirrRow {2, 1, 1, 0};
    vector<int> edMirrCol {1, 0, 2, 1};

    ticTacToe(board, cornerRows, cornerCols, edgesRow, edgesCol, cornerMirrR, cornerMirrC, edMirrRow, edMirrCol, 0, 9);

    return 0;
}