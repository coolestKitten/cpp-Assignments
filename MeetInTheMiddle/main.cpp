#include <iostream>
#include <vector>

using namespace std;

// sort the array
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

// build all the permutations

void getPermutations(vector<int> target,int n, int r, int index, int data[], int i, vector<int> &output){
    if (index == r){
        int sum = 0;
        for (int j = 0; j < r; j++){
            sum += data[j];
        }
        //cout << sum << " " << endl;
        if(sum != 0){
            output.push_back(sum);
        }

        return;
    }
 
    if (i >= n)
        return;
 
    data[index] = target[i];
    getPermutations(target, n, r, index + 1, data, i + 1, output);
 
    getPermutations(target, n, r, index, data, i+1, output);
}

// add all the permutations, always save the highest one that doesn't exceed the desired result
int finalResult(vector<int> sideA, vector<int> sideB, int S){
    int finalSum = 0, catControl = 0;
    for(int i = 0; i< sideA.size(); i++){
    for(int j = 0; j < sideB.size(); j++){
        catControl = sideA[i] + sideB[j];
        if (catControl > finalSum && catControl <= S){
            finalSum = catControl;
        }
    }}
    return finalSum;
}

// splice it in half
// validations related to its size would go here
void spliceArray(vector<int> numbers, int S){
  int center = numbers.size()/2;
  vector<int> halfOne, halfTwo;

  // get the first array, starting at 0 and ending at the center
  for (int i =0; i< center; i++){
    halfOne.push_back(numbers[i]);
  }
  // obtain the second array from center to the end
  for (int i = center; i< numbers.size(); i++){
    halfTwo.push_back(numbers[i]);

  }
  // control variables to get all permutations
  int n1 = halfOne.size(), n2 = halfTwo.size(), X;
  int check1[n1], check2[n2];
  vector<int> permutationsSideA, permutationsSideB;

  // get all permutations for first half
  for(int i = 0; i<=n1; i++){
    getPermutations(halfOne, n1, i, 0, check1, 0, permutationsSideA);
  }

  // get all permutations for second half
  for(int i = 0; i<=n2; i++){
    getPermutations(halfTwo, n2, i, 0, check2, 0, permutationsSideB);

  }

    cout << "Resultado es: " << finalResult(permutationsSideB, permutationsSideA, S) << endl;
  
}


bool validateInputLen(int N){
    return (N < 0 || N > 40);
}

bool validateInputElem(int N){
    return (N < 0 || N > 1000000000);
}

int main() {
  //vector<int> test{3, 34, 4, 12, 5, 2};
  vector<int> numbers; 
  
  int S, catcontrol, temp;
  cout << "Valor de S: ";
  cin >> S;
  while(cin.fail() || S < 0){
    cout << "Entrada invalida, intentelo de nuevo" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Valor de S: ";
    cin >> S;
  }

  cout << "Largo del array: ";
  cin >> catcontrol;

   while(cin.fail() || validateInputLen(catcontrol) == true){
    cout << "Entrada invalida, intentelo de nuevo" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Largo del array: ";
    cin >> catcontrol;
  }

  for (int i = 0; i < catcontrol; i++){
    cout << "Elemento " << i << ": ";
    cin >> temp;
    while(cin.fail() || validateInputElem(temp) == true){
    cout << "Entrada invalida, intentelo de nuevo" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Elemento " << i << ": ";
    cin >> temp;
    }

    numbers.push_back(temp);
  }
  
  bubbleSort(numbers);
  spliceArray(numbers, S);
}