#include <iostream>
#include <vector>

using namespace std;

void printArray(int numlist[]){
    int arrSize = sizeof(numlist) - 1;
    // Prints full array
    for (int i = 0; i < arrSize; i++){
        cout << numlist[i] << " ";
    }
    cout << endl;
}

void bubbleSort (int numlist[]) {
    // Gets size of array and prints it
    int arrSize = sizeof(numlist) - 1;
    //cout << "Array Size: " << arrSize << endl;

    // Bubble Sort Algor
    for (int i = 0; i < arrSize - 1; i++){
    
        for(int j = 0; j < arrSize - i - 1; j++){
            if(numlist[j+1] > numlist[j]){
                
                swap(numlist[j], numlist[j + 1]);

                printArray(numlist);
            }
        }
        
    }

        // Prints full array
    for (int i = 0; i < arrSize; i++){
        cout << numlist[i] << " ";
    }
    
}


int main (){
    int lista1[] = {8,6,7,4,5,3,2};
    int lista2[10];  
    //vector<double> lista2;

    // Bubble sort 1 
    // Utiliza bubblesort para ordenar una lista de 7 elementos
    //cout <<
    printArray(lista1);
    bubbleSort(lista1);


    return 0;
}
