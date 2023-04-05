#include <vector>
#include <iostream>

using namespace std;

struct Point {
    int x,y;

};

struct Line {
    Point start, end;

    Line(Point _start, Point _end){
        start = _start;
        end = _end;
    }
};

void displayMatrix(vector<vector<int> > matrix, int n){
  for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
          
          cout << matrix[i][j] << " ";
        }
        cout<< endl;
  }
  
} 

// Part 1: Floyd's Algorithm

vector<vector<int> > modMatrix (vector<vector<int> > mainMatrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (mainMatrix[i][j] == -1){
              mainMatrix[i][j] = 1000000000;  
            }
        }
    }
    return mainMatrix;
}

vector<vector<int> > floydAlgorithm (vector<vector<int> > mainMatrix, int n){
    vector<vector<int> > aTemp = modMatrix(mainMatrix, n);
    
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                aTemp[i][j] = min(aTemp[i][j], (aTemp[i][k] + aTemp[k][j]));
            }
        }
    }

    return aTemp;
}

// Part 2: Traveler's Algorithm



// Part 3: Maximum Flow Algorithm



int main(){
    int n = 4;

    vector<bool> visited(false, n);

    vector<vector<int>> test{
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    vector<vector<int>> flow{
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}
    };

    vector<Point> locations{ {200,500}, {300,100}, {450,150}, {520,480}};

    displayMatrix(floydAlgorithm(test, n), n);


    return 0;
}