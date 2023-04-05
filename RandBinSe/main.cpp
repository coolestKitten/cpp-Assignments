#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

//sort the array 
// bubble sort for vectors
vector<int> bubbleSort(vector<int> &numbers){
    int i, j;
    for (i = 0; i < numbers.size(); i++)
        for (j = 0; j < numbers.size() - i; j++)
            if (numbers[j] > numbers[j + 1]){
              numbers[i] += numbers[i+1];
              numbers[i+1] = numbers[i] - numbers[i+1];
              numbers[i] -= numbers[i+1];

            }
    return numbers; 
}

//generate a random number
int getRandom(int start, int end){
  srand(time(NULL));
  return (start + rand() % (end-start+1));
}

int binarySearch(vector<int> numbers, int start, int end, int target){
  if(end >= start){
    int center = getRandom(start, end);

    if(numbers[center] == target){
      return center; 
    } else if (numbers[center] > target){
      return binarySearch(numbers, start, center-1, target);
    } else {
      return binarySearch(numbers, center + 1, end, target);
    }
  } else if (end == 0){
    if (numbers[0] == target){
      return 0;
    }
  }
  return -1;
}

vector<int> searchDuplicates(int i, vector<int> numbers){
  int j = i -1, k = i + 1;
  vector<int> result;
  if(i != -1){
    //go through the array backwards 
    while(numbers[j] == numbers[i]){
      //cout << j << " " << numbers[j] << endl;
      result.push_back(j);
      j--;
    }
    result.push_back(i);
    //go through the array forwards
    while(numbers[k] == numbers[i]){
      //cout << k << " " << numbers[k] << endl;
      result.push_back(k);
      k++;
    }
  } else {
    result.push_back(-1);
  }
  

  return result;
}

//all we are really missing is to display the results array and check it for errors
int main() {
  vector<int> numbers; 
  
  int target, catcontrol, temp;
  cout << "Numero a Buscar: ";
  cin >> target;
  while(cin.fail() || target < 0){
    cout << "Entrada invalida, intentelo de nuevo" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Numero a Buscar: ";
    cin >> target;
  }

  cout << "largo del array" << endl;
  cin >> catcontrol;

  for (int i = 0; i < catcontrol; i++){
    cout << "Elemento " << i << ": ";
    cin >> temp;
    while(cin.fail()){
    cout << "Entrada invalida, intentelo de nuevo" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Elemento " << i << ": ";
    cin >> temp;
    }

    numbers.push_back(temp);
  }
  
  bubbleSort(numbers);

  cout << "Buscando " << target << " en el arreglo: { ";
  for (int i = 0; i< numbers.size(); i++){
    cout << numbers[i] << " ";
  }
  cout << "} "<< endl;
  
  
  
  
  
  int result = binarySearch(numbers, 0, numbers.size()-1, target);
  
  
    vector<int> finalResult = searchDuplicates(result, numbers);
    bubbleSort(finalResult);


  for (int i = 0; i< finalResult.size(); i++){
    if(finalResult[i] != -1){
      cout << "Numero encontrado en el indice: " << finalResult[i] << endl;
    } else {
      cout << "El número no fué encontrado" << endl;
    }
      
    
  }
  
  
  
  
  
  return 0;
}