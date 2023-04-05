#include <iostream>
#include <vector>

using namespace std;

void imprimeVector(vector<int> numlist){
    cout << "Mostrando Vector: ";
    for(int i = 0; i < numlist.size(); i++){
        cout << numlist[i] << " ";
    }
    cout << endl;


}

void hanoi(int n, vector<int> pilar1, vector<int> pilar2, vector<int> pilar3){
    // llena el primer pilar con los discos necesarios, en orden
    for(int i = 1; i <= n; i++){
        pilar1.push_back(i);
    }
    imprimeVector(pilar1);
    imprimeVector(pilar2);
    imprimeVector(pilar3);

    // si el numero de discos es 1, solo se agrega el primer elemento del primer pilar al ultimo pilar
    if(n == 1){
        //cout << pilar1[0];
        cout << "--------------------------------------" << endl;
        pilar3.push_back(pilar1[0]);
        pilar1.pop_back();
        imprimeVector(pilar1);
        imprimeVector(pilar2);
        imprimeVector(pilar3);
    } else {
        cout << "--------------------------------------" << endl;
        
    }

}


int main(){
    vector<int> pilar1, pilar2, pilar3;
    int n = 1;
    cout << "---------- Torres de Hanoi -----------" << endl;
    hanoi(n, pilar1, pilar2, pilar3);
    return 0;
}