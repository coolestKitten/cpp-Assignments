#include <vector>
#include <iostream>

using namespace std;

// method that checks if a knight can be placed on a specific square
//  args: control variable for length, destination coords, and the board for the result
// returns: a boolean
bool knightSafe(int len, int i, int j, vector<vector<int>> board){
    //  should probably check if a move is valid on top of checking if it's safe
    // perform validity check first
    // if i is greater than 0 and within range, and j is greater than 0 and within range, and the destination on the board is available
    return (i >= 0 && i < len && j >= 0 && j < len && board[i][j] == -1);

}


// recursive method that solves the knight's tour problem using branch and bound methodology
//  args: 
//  returns: a boolean
bool knightsTour(vector<vector<int>> &board, vector<int> movesX, vector<int> movesY, int len,int currX, int currY, int catcontrol){
    // if stop condition is reached, return true, end the cycle
    int destX, destY;

    if(catcontrol == len * len){
        return true;
    }

    // for every possible move, attempt the following
    for(int i = 0; i < 8; i++){
        // if the current square is safe
        destX = currX + movesX[i];
        destY = currY + movesY[i];
        if(knightSafe(len, destX, destY, board) == true){
            // mark square as visited

            board[destX][destY] = catcontrol;

            // check if the next placement is successful
            if(knightsTour(board, movesX, movesY, len, destX, destY, catcontrol + 1) == true){
                return true;
            }
            
            //cout << "Bactracking " << endl;
            // if not, remove the knight from the current position
            board[destX][destY] = -1;

        }
    }
    
    return false;
}

int main(){
    int len = 8;

    // these arrays are the knight's possible moves 
    // 
    vector<int> movesX{2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> movesY{1, 2, 2, 1, -1, -2, -2, -1};

    // board for the solution
    vector<vector<int>> chessboard (len, vector<int>(len, -1));
    chessboard[0][0] = 0;

    if (knightsTour(chessboard, movesX, movesY, len, 0, 0, 1) == false){
        cout << "No hay Solución" << endl;
        for(int i = 0; i< len; i++){
        for(int j = 0; j< len; j++){
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
        }
        cout << endl;
    } else {
        for(int i = 0; i< len; i++){
        for(int j = 0; j< len; j++){
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
        }
        cout << endl;
    }

    return 0;
}