#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// method that validates if a cell is within range
bool cellValid(int row, int col, int size){
    // target cell is greater than 0, and lower than array size
    return (row >= 0) && (col >=0) &&(col < size) && (row < size);
}

// method that validates if a cell has no obstacles in it
bool checkForObstacles(vector<vector<int>> target, int row, int col){
    // target cell is different from 0;
    return (target[row][col] != 0);
}

// method that validates if destination has been reached
bool destinationReached(int i, int j, int size){
    return (i == size - 1 && j == size - 1);
}


// calculate heuristics for specific cell
double calcFValue(int currX, int currY, int size, double cost){
    double h = abs(currX - size)+abs(currY - size);
    double f = cost + h;
    return f;
}



void aStar(vector<vector<int>> target, vector<char> solution, int size, int row, int col, double cost){
  int temp = 10000000, index;
  // final solution, which is given out to the user
  //temporarily stores the fvalues for each adjacent cell
  double fValues[4] = {10000000, 10000000, 10000000, 10000000};
  
  // obtain the direct distance between the origin and destination
  // x2, y2 is [size-1][size-1]
  // origin is [0][0]
  if (target[0][0] == 0){
    cout << "No hay solución" << endl;
    return;
  } else if (target[1][0]  == 0&& target [0][1] == 0){
    cout << "No hay solución" << endl;
    return;
  } else if (target[size -1][size - 1] == 0){
    cout << "No hay solución" << endl;
    return;
  }
  //while destination has not been reached
  
    //cout << "Mikimaik: " << cost;
    //branch out to all four directions, then perform the checks declared above
    // check if the cell is valid
    // check if the cell is an obstacle
    // check if the cell is the destination

    if (destinationReached(row, col, size) == true){
        for(int i = 0; i< solution.size(); i++){
            cout << solution[i];
        }
        cout << endl;
        return;
    }

    

    // checkRight
    if (cellValid(row, col + 1, size) == true && checkForObstacles(target, row, col + 1) == true){
        // if the cell is valid, evaluate an F value for it place it at the corresponding index
        //cout << "branchedRight" << endl;
        fValues[0] = calcFValue(row, col + 1, size, cost);
    }

    // checkLeft
    if (cellValid(row, col - 1, size) == true && checkForObstacles(target, row, col - 1) == true){
        // if the cell is valid, evaluate an F value for it place it at the corresponding index

        //cout << "branchedLeft" << endl;
        fValues[1] = calcFValue(row, col - 1, size, cost);
        
    }

    // checkUp
    if (cellValid(row -1, col, size) == true && checkForObstacles(target, row - 1, col) == true){
        // if the cell is valid, evaluate an F value for it place it at the corresponding index

        //cout << "branchedUp" << endl;
        fValues[2] = calcFValue(row - 1, col, size, cost);

    }

    // checkDown
    if (cellValid(row +1, col, size) == true && checkForObstacles(target, row + 1, col) == true){
        // if the cell is valid, evaluate an F value for it place it at the corresponding index
        //cout << "branchedDown" << endl;
        fValues[3] = calcFValue(row, col + 1, size, cost);


    }

    // go through the fValue array, find the lowest value, and write down its index
    for (int i = 0; i < 4; i++){
        if (fValues[i] < temp){
            temp = fValues[i];
            index = i;
        }
    }
    
    // depending on the index, push back the solution and move the current values to that direction
    switch(index) {
        case 0:
            solution.push_back('R'); 
            col += 1;
            break;
        case 1:
            solution.push_back('L');
            col -= 1;
            break;
        case 2: 
            solution.push_back('U');
            row -= 1;
            break;
        case 3:
            row += 1;
            solution.push_back('D');
    }

   // increase cost value for the next cycle
    aStar(target, solution, size, row, col, cost + 1);

  
  
}

bool validateNumber(int target){
    // if the number is valid, returns true
    if (target == 0 || target == 1){
        return true;
    }
    return false;
}

int main() {
    int n, catControl, errors = 0;
  
  vector<char> result;
  
  cout << "Largo del array: " ;
  cin >> n;
  while(cin.fail() || n < 0){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Largo del array: ";
        cin >> n;
}
vector<vector<int> > target(n, vector<int> (n, 0));
  for (int i = 0; i < n; i++){
    //cout << "Miguelin" << endl;
    for (int j = 0; j < n; j++){
        //cout << "Miguelin2" << endl;

        cin >> catControl;
        while(cin.fail() || validateNumber(catControl) == false){
            cout << "Entrada invalida en el indice ("  << i << ", " << j << ") " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            errors += 1;
            cin >> catControl;
        }
        target[i][j] = catControl;
    }
  }

  if (errors == 0){
    aStar(target, result, n, 0, 0, 0);
  } else {
    cout << "Error al introducir matriz, terminando ejecución..." << endl;
  }
}