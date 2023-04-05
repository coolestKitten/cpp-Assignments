//Marco Antonio Gardida Cortés A01423221
//Alejandro Hidalgo Badillo
//Miguel Jiménez Padilla A01423189
//Silvio Emmanuel Prieto Caro
#include<iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include "RFC.h"
using namespace std;
int MAX=50;
//https://codemyn.blogspot.com/2019/07/metodos-de-ordenamiento-mergesort-en-c.html 
//https://resolviendoejerciciosdeprogramacion.blogspot.com/2014/05/algoritmos-de-ordenacion-quicksort-en-c.html

vector<RFC> merge(vector<RFC>& left, vector<RFC>& right)//Función que acomoda con un parámetro de vectores de izquierda y derecha  
{
   vector<RFC> result;//definir el resultado tipo vector 
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
   return result;
}

vector<RFC> mergeSort(vector<RFC>& m, double &timez) //Función que inicia el acomodamiento  
{                                                     //merge, le pasas el vector desacomodado por paso por referencia y una variable que tendrá el tiempo total.
  unsigned t0,t1;//Variables para definir tiempo
  t0=clock();// Tiempo inicial
   if (m.size() <= 1)//checa cuandpo el vector  es de un elemento 
      return m;        
 
   vector<RFC> left, right, result; //definir tres verctores tipo RFC de auxiliares
   int middle = ((int)m.size()+ 1) / 2; //definir el índice del medio
 
   for (int i = 0; i < middle; i++) {//for para checar del inicio al medio y agregarlos al vector de la izquierda
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {//for para checar del medio al final y agregarlos al vector de la derecha
      right.push_back(m[i]);
   }
 
   left = mergeSort(left, timez);//recursión para repetir lo anterior pero con el lado izquierdo
   right = mergeSort(right, timez);//recursión para repetir lo anterior pero con el lado derecho
   result = merge(left, right);//llama a merge de los vectores de left y right
   
   t1 =clock();
  timez = (double(t1-t0)/CLOCKS_PER_SEC);//tiempo final 
   return result;
}

////////////////////////////////////////////////////////

void quickSort(vector<RFC> &rfcs, int izq, int der, double &timex) {//Función que ordena RFCs con el método de quicksort
  //Los parámetros son: vector de RFCs con paso por referencia, índice del RFC inicial, índice del RFC final, variable para medir tiempo con paso por referencia
 
 unsigned t0,t1; //variables para medir tiempo

 RFC piv = rfcs[izq];//pivote igualado al RFC inicial
 int i = izq;//índice de RFC inicial
 int j = der;//índice de RFC final
 RFC aux;//objeto auxiliar tipo RFC

  //STARTS RUNNING
  t0=clock();//método para iniciar a contar tiempo

 while (i< j) { //comprueba que el extremo izquierdo sea menor que el derecho
  while ((rfcs[i]<=piv && i<j)) i++;//comparación entre el RFC izquierdo y el pivote
  while (rfcs[j] > piv) j--;//comparación entre el RFC derecho y el pivote
  if (i < j) {//comprobación 
   aux  = rfcs[i];//variable auxiliar igualada a RFC en lado izquierdo
   rfcs[i] = rfcs[j];//cambio de valor de RFC en lado izquierdo
   rfcs[j] = aux;//cambio de valores con el auxiliar
  }
 }

 rfcs[izq] = rfcs[j];//cambio de valores
 rfcs[j] = piv;//definición de nuevo pivote
 if (izq<j - 1)
  quickSort(rfcs, izq, j - 1,timex);//recursión recorriendo arreglo a la izquierda
 if (j + 1 <der)
  quickSort(rfcs, j + 1, der,timex);//recursión recorriendo arreglo a la derecha

  //ENDS RUNNING
  t1=clock();//función para terminar de calcular el tiempo
  timex = (double(t1-t0)/CLOCKS_PER_SEC);//regresar el tiempo por paso por referencia

}

///////////////////////////////////////////////////////////

void rellenarArray(vector<RFC> &rfcsQuick, vector<RFC> &rfcsMerge,int &length){
    length=MAX;
    string nombre,fecha,llave;//define las variables que se usarán para rellenar ambos vectores
    
  //65-90 ASCII
  srand(time(nullptr)); //esto es para que el random funcione correctamente

  for (int i=0; i<MAX; i++){  //for para el número de elemntos del vector
    for(int z=0; z<13; z++){//for para el número de caracteres que tiene el RFC
      if (z<4){//primeros elementos del RFC son letras
        //RFC[z]=65 + rand() % (90-65);
        //RFC+= 65 + rand() % (90-65);
        nombre+= 65 + rand() % (90-65);//randoom de una letra en código ascii
      }
      else if (z>=4 && z<10){//elementos del medio que son números
        //RFC[z]= rand() % 9;
        //RFC+=to_string(rand() % 9);
        fecha+= to_string(rand() % 9);//randoom de números del 0 al 9
      }
      else{//últimos elementos son letras
        //RFC[z]=65 + rand() % (90-65);
        //RFC+= 65 + rand() % (90-65);
        llave+= 65 + rand() % (90-65);//randoom de una letra en código ascii
      }
      
    }
    rfcsQuick.push_back(RFC(nombre,fecha,llave));
    rfcsMerge.push_back(RFC(nombre,fecha,llave));//se agregan a los vectores correspondientes

    nombre="";//se reinician variables
    fecha="";
    llave="";
  }
}

int main(){

    vector<RFC> rfcsQuick;//vector para quicksort
    vector<RFC> rfcsMerge;//vector para mergesort
    double timez=0;//time variable for merge sort
    double timex=0;//time variable for quick sort
    double timezz=0,timexx=0;

    int length;
    rellenarArray(rfcsQuick, rfcsMerge, length);//llamas para llenar vectores

   
    quickSort(rfcsQuick,0,length,timex);//llamas el método para ordenamiento quicksort
    rfcsMerge = mergeSort(rfcsMerge,timez);//llamas el método para ordenamiento Merge

    for (int t=0; t<length;t++){
      cout<<rfcsQuick[t]<<endl;//Herramienta para imprimir 
    }

    quickSort(rfcsQuick,0,length,timexx);//llamas el método para ordenamiento quicksort
    rfcsMerge = mergeSort(rfcsMerge,timezz);//llamas el método para ordenamiento Merge

    //cout<<"Tiempo de ejecución con Quick sort: "<<timex<<" segundos"<<endl;
    //cout<<"Tiempo de ejecución con Merge sort: "<<timez<<" segundos"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Algoritmo   "<<"Ejecución desordenado  "<<"Ejecución ordenado"<<endl;
    cout<<"MergeSort   "<<timez<<"                  "<<timezz<<"  "<<endl;
    cout<<"QuickSort   "<<timex<<"                  "<<timexx<<"  "<<endl;

    if(timez<timex){cout<<"MergeSort es más rápido cuando está desordenado"<<endl;}
    else{
      cout<<"QuickSort es más rápido cuando está desordenado"<<endl;
    }
    return 0;
}

