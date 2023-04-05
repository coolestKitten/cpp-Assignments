#include <iostream>
#include <vector>

using namespace std;

vector<int> getValues(){
    int valores, valor;
    vector<int> denominaciones;
    cout << "Introducir cantidad de valores: ";
    cin >> valores;
    while(cin.fail()){
        cout << "Entrada invalida, intentelo de nuevo: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> valores;
    }

    cout << "Introduzca " << valores << " denominaciones de menor a mayor: " << endl;
    while (valores > 0){
        cin >> valor;
        while(cin.fail()){
            cout << "Entrada invalida, intentelo de nuevo: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> valor;
        }
        denominaciones.push_back(valor);
        valores--;
    }
    return denominaciones;
}

void getChange(vector<int> valores, int C, int i){
    if (C == 0){
        return; 
    } else {
        if (C > valores [i] || C == valores[i]){
            cout << valores[i] << endl;
            //cout << "MikiMaik" << endl;
            C -= valores[i];
            //cout <<"Remaining Change: "<< C<< endl;
        } else if (valores[i] > C){
            //cout << "MikiMaikn't" << endl;
            i--;
            //cout << "Current value: " << i << endl;
        }
        getChange(valores, C, i);
    }

}

int main (){
    vector<int> monedas = getValues();
    int cantValor = monedas.size() - 1;
    int C, P, Q;
    bool gatoControl = true;
    cout << "Cantidad a pagar: ";
    cin >> P;
    while(cin.fail()){
        cout << "Entrada invalida, intentelo de nuevo:" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> P;
    }
    cout << "Cantidad pagada: ";
    cin >> Q;
    while(cin.fail()){
        cout << "Entrada invalida, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> Q;
    }
    C = Q - P;
    cout << C << endl;
    cout << "Comenzando Cálculo..." << endl;
    getChange(monedas, C, cantValor);

    return 0;
}