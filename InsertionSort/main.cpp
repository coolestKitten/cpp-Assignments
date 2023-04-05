#include <iostream>

using namespace std;

void printArray(int numlist[]) { 
    int arrSize = sizeof(numlist);
    // Prints full array
    for (int i = 0; i < arrSize; i++) {
        cout << numlist[i] << " ";
    }
    cout << endl;
}

void insertionSort(int numlist[]) {
    int gatoControl, j, n = sizeof(numlist);
    cout << n << endl;
    printArray(numlist);
    
    for(int i = 1; i < n; i++) {
        gatoControl = numlist[i];
        j = i - 1;
        // cout << gatoControl << " " << j <<endl;

        while(j >= 0 && numlist[j] > gatoControl){
            numlist[j + 1] = numlist[j];
            j -= 1;
            
        }
        numlist[j + 1] = gatoControl;
        printArray(numlist);
    }

    printArray(numlist);

}

int main(){
    int lista1[] = {13,10,15,7,8,2,6,9};
    //printArray(lista1);
    insertionSort(lista1);
    return 0;    
}