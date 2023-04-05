#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<bool> > > soluciones; // vector para almacenar soluciones posibles
vector<int> distancias; // vector para almacenar las distancias de cada solucion

vector<vector<int> > buildMaze(int M, int N){
  vector <vector<int> > maze(M);
  int num;
  
  for(int i = 0; i < M; i++){
    
    for(int j = 0; j < N; j++ ){
      
      cin >> num;
      maze[i].push_back({num});
      //cout << "Mikimaik" << endl;
    }
  }
  return maze;
}

// metodo que obtiene una matriz de booleanos para modificar despues
vector<vector<bool> > buildSolution(vector<vector<int> > maze){
  vector<vector<bool> > solution;
  int filas = maze.size();
  int col = maze[0].size();
  
  solution.resize(filas, vector<bool>(col));
  return solution;
}

// metodo que determina si es seguro moverse a una casilla determinada
bool safePath(vector<vector<int> > maze, vector<vector<bool> > solution, int currx, int curry){
    return (currx >= 0 && currx < maze.size() && curry >= 0 && curry < maze.size() && maze[currx][curry] == 1 && !solution[currx][curry]);

}

// metodo que imprime una matriz de booleanos
void printSolution(vector<vector<bool> > array){
  for (int i = 0; i< array.size(); i++){
    for (int j = 0; j < array[0].size(); j++){
        cout << array[i][j] << " ";
      
    }
    cout << endl;
  }
  cout << endl;
}

void appendSolution(vector<vector<bool> > array, int dist){
  soluciones.push_back(array);
  distancias.push_back(dist);
}

// metodo recursivo que obtiene la solucion mas corta al laberinto
void getSolution(vector<vector<int> > maze, vector<vector<bool> > solution, int currx, int curry, int destx, int desty, int dist){

    
    if (currx == destx && curry == desty){
      solution[currx][curry] = true;
      appendSolution(solution, dist);
    }
    
    solution[currx][curry] = true;

    // metodo que va a hacia abajo
    if (safePath(maze, solution, currx + 1, curry)){
        getSolution(maze, solution, currx + 1, curry, destx, desty, dist + 1);
    }

    // metodo que va hacia la derecha
    if (safePath(maze, solution, currx, curry + 1)) {
        getSolution(maze, solution, currx, curry + 1, destx, desty, dist + 1);
    } 

    // metodo que va hacia arriba
    if (safePath(maze, solution, currx - 1, curry)) {
        getSolution(maze, solution, currx - 1, curry, destx, desty, dist + 1);
    }
    //metodo que va a la izquierda
    if (safePath(maze, solution, currx, curry - 1)){
        getSolution(maze, solution, currx, curry - 1, destx, desty, dist + 1);
    }
    // si ninguno se cumple inicia el backtracking
    solution[currx][curry] = false;

 
}



void getShortestSolution (vector<vector<vector<bool> > > soluciones, vector<int> distancias){
  int high = 0, index = 0;
  for(int i = 0; i< distancias.size(); i++){
    if (distancias[i] > high){
      high = distancias[i];
      index = i;
    } else {
      continue;
    }
  }
  cout << endl;
  printSolution(soluciones[index]);
  
}


int main(){
  int M,N;
  vector<vector<int> > prueba = {
        {1,0,0,0,0},
        {1,1,1,1,0},
        {0,0,1,1,0},
        {1,1,0,1,1},
        {0,0,0,0,1}

    };
  cout << "Numero de filas: ";
  cin >> M;
  cout << "Numero de columnas: ";
  cin >> N;
  
  vector<vector<int> > maze = buildMaze(M,N);
  vector<vector<bool> > solution = buildSolution(maze); // construye vector de solucion

  //printSolution(solution); 
    
  getSolution(maze, solution, 0, 0, solution.size() - 1, solution[0].size() - 1, 0); // inicia la recursión para obtener la solución
  getShortestSolution(soluciones, distancias);

  return 0;
}