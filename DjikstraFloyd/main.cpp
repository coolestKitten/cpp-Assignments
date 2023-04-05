#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

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

int chooseShortestPath(vector<int> row){
  for(int i = 0; i< row.size(); i++){
    if(row[i] != 0 && row[i] ){
    
    }
  }

}

void dijkstraAlgorithm (vector<vector<int> > mainMatrix, int n){
  vector<vector<int> > aTemp = modMatrix(mainMatrix, n);
  vector<bool> visited(n, false);
  int start= 0, selected = 0, path = 0;
  for (int i = 0; i < n; i++){
    chooseShortestPath(aTemp[i]);
    
  }
  
  
}

int main() {
  int n, x;

  cout << "input: ";
  cin >> n;
  while(cin.fail() || x <= 0){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> x;
   }

  vector<vector<int> > mainMatrix (n, vector<int> (n, 0));

  for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
          cin >> x;
          while(cin.fail() || x < -1){
            cout << "Entrada invalida, intentelo de nuevo" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> x;
          }
          mainMatrix[i][j] = x;
        }
    cout << endl;
  }

  //displayMatrix(mainMatrix, n);
  cout << "Dijkstra:" << endl;
  dijkstraAlgorithm(mainMatrix, n);
  cout << "Floyd:" << endl;
  displayMatrix(floydAlgorithm(mainMatrix, n), n);


  
}