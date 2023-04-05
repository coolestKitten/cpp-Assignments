#include <iostream>
#include <vector>

using namespace std;


vector<double> merge(vector<double>& left, vector<double>& right){ //Función que acomoda con un parámetro de vectores de izquierda y derecha  
   vector<double> result;//definir el resultado tipo vector 
   while ((int)left.size() > 0 || (int)right.size() > 0) {//un while que se repite mientras un vector left o right sea mayor o igual a 1
      if ((int)left.size() > 0 && (int)right.size() > 0) {//comprueba si left y right son mayores a 0 
         if (left.front() < right.front()) { //comprueba si el valor inicial del vector de left es menpor al de right    
            result.push_back(left.front()); //agrega el RFC al vector de resultado
            left.erase(left.begin());//elimina el elemento del iterador al inicio de izquierda
         } 
        else {
            result.push_back(right.front());//Agrega el primer elemento de derecha a resultado
            right.erase(right.begin());//elimina el elemento del iterador al inicio de derecha
         }
      }  else if ((int)left.size() > 0) {//comprueba si el vector izquierda es mayor a 0 
            for (int i = 0; i < (int)left.size(); i++) //for que  agrega a resultado los elementos de left 
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {//comprueba si el vector derecha es mayor a 0
            for (int i = 0; i < (int)right.size(); i++)//for que agrega a resultado los elementos de derecha
               result.push_back(right[i]);
            break;
      }
   }
   cout << "Mostrando Vector: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

   return result;
}

vector<double> mergeSort(vector<double>& m) //Función que inicia el acomodamiento  
{                                                     //merge, le pasas el vector desacomodado por paso por referencia y una variable que tendrá el tiempo total.
  unsigned t0,t1;//Variables para definir tiempo
  t0=clock();// Tiempo inicial
   if (m.size() <= 1)//checa cuandpo el vector  es de un elemento 
      return m;        
 
   vector<double> left, right, result; //definir tres verctores tipo RFC de auxiliares
   int middle = ((int)m.size()+ 1) / 2; //definir el índice del medio
 
   for (int i = 0; i < middle; i++) {//for para checar del inicio al medio y agregarlos al vector de la izquierda
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {//for para checar del medio al final y agregarlos al vector de la derecha
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);//recursión para repetir lo anterior pero con el lado izquierdo
   right = mergeSort(right);//recursión para repetir lo anterior pero con el lado derecho
   result = merge(left, right);//llama a merge de los vectores de left y right
   
   return result;
}


int main(){
    vector<double> numlist;
    int len, valor;

    cout << "Introducir Largo: ";
    cin >> len;
    cout << "Introducir valores: " << endl;

    for (int i = 0; i < len; i++){
        cin >> valor;
        numlist.push_back(valor);
    }

    numlist = mergeSort(numlist);

    return 0;
}