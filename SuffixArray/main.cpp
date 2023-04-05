#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> computeSubstringArray(string input){
  vector<string> suffArr;

  
  for (int i = 0; i<input.size(); i++){
    suffArr.push_back(input.substr(i));
  }
  return suffArr;
}

void prtVector(vector<string> suffArr){
  for (int i=0; i<suffArr.size(); i++){
    cout << suffArr[i] << endl;
  }
}

void insertionSort (vector<string> &numlist){

  for (int i = 1; i < numlist.size(); i++){
    
    string tmp = numlist[i];
    int j = i - 1;
    while (j >= 0 && numlist[j] > tmp){
      
      numlist[j + 1] = numlist[j];
      j--;

    }

    numlist[j + 1] = tmp;

  }

}

bool validateInput(string input){
  return (find_if(input.begin(), input.end(), ::isdigit) != input.end()) || (find_if(input.begin(), input.end(), ::isspace) != input.end()) || (find_if(input.begin(), input.end(), ::ispunct) != input.end());
}

int main() {
  string input;
  cout << "Introducir una palabra para obtener el Arreglo de Sufijos" 
    << endl
    << "(Solo la primera palabra será tomada en cuenta):" 
    << endl;

  while(true){
    cin >> input;
    if(validateInput(input)){
      cout << "Su palabra contiene un caracter invalido, intentelo de nuevo"
        << endl;
    }
    break;
  }
  cout << "Palabra: " << input << endl;
  vector<string> suffArr = computeSubstringArray(input);
  insertionSort(suffArr);
  prtVector(suffArr);
}