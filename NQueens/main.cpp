#include <iostream>
#include <vector>

using namespace std;

// method that checks if it's safe to place a queen on a particular square
// args: an array columns, two matrices, and the current coordinates
// returns: a boolean
bool checkSquare(int i, int j, int len, vector<bool> availableRows, vector<bool> diagBack, vector<bool> diagFront){
    if (availableRows[i] == true || diagBack[i+j] ==  true || diagFront[j-i + len-1] == true){
        // if the current row is not available or if the current diagonals are occupied, return false
        return false;
    }
    
    return true;
}


//  method that determines if it's possible to solve the nQueens problem with the current number of rows
//  args: reference to board for the solution, arrays for available rows and diagonals, int to keep track of column, number of rows
//  returns: a boolean
bool nQueens (vector<vector<int>> &solution, vector<bool> availableRows, vector<bool> diagBack, vector<bool> diagFront, int catControl, int len){
    if(catControl >= len){
        //if all queens have been placed down, return true
        return true;
    }

    // for every column in the board, perform the following
    for(int i = 0; i < len; i++){
        // if the current square is safe
        if(checkSquare(i, catControl, len, availableRows, diagBack, diagFront)){
            // place the queen on the current square, then update its status on all the arrays
            availableRows[i] = true; 
            diagBack[i + catControl] = true;
            diagFront[catControl - i + len - 1] = true;
            solution[i][catControl] = 1; 

            // check if the next placement is successful
            if(nQueens(solution, availableRows, diagBack, diagFront, catControl + 1, len)){
                return true;
            }

            // if it was not, remove the queen from the square, move to the next column
            availableRows[i] = false;
            diagBack[i + catControl] = false;
            diagFront[catControl - i + len - 1] = false;
            solution[i][catControl] = 0; 

        }
    }

    // if the end was reached and not all queens have been placed, return false
    return false;
}

bool validateNumber(int target){
    return (target == 4 || target  == 8);
}


// driver code
int main(){
    int len;
    cout << "Introducir valor de 'n' (4 u 8): ";
    cin >> len; 
    while(cin.fail() || validateNumber(len) == false){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> len;
    }

    // chessboard for the solution
    vector<vector<int>> chessboard (len, vector<int>(len, 0));

    //  boolean array marking all available rows
    vector <bool> availableRows(len, false);

    //  
    vector<bool> diagBack(2*len-1, false);
    vector<bool> diagFront(2*len-1, false);

    bool solution = nQueens(chessboard, availableRows, diagBack, diagFront, 0, len);
    if (solution == true){
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                cout << chessboard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "" << endl;
    }
    return 0;
}