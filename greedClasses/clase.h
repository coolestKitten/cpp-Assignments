#pragma once
#include <iostream>
#include <string>

using namespace std;

class Clase{
    public:
        Clase();
        Clase(string, string, double, double);

        string getNombre();
        string getDias();
        double getHoraIni();
        double getHoraFin();

        void setNombre(string);
        void setDias(string);
        void setHoraIni(double);
        void setHoraFin(double);

        void imprimeClase();

    private:
        string nombre, dias;
        double horaIni, horaFin;
};

Clase::Clase(){
    nombre = "NULL";
    dias = "NULL";
    horaIni = 0;
    horaFin = 0;
}
Clase::Clase(string _nombre, string _dias, double _horaIni, double _horaFin){
    nombre = _nombre;
    dias = _dias;
    horaIni = _horaIni;
    horaFin = _horaFin;
}

string Clase::getNombre(){
    return nombre;
}
string Clase::getDias(){
    return dias;
}
double Clase::getHoraIni(){
    return horaIni;
}
double Clase::getHoraFin(){
    return horaFin;
}

void Clase::setNombre(string _nombre){
    nombre = _nombre;

}
void Clase::setDias(string _dias){
    dias = _dias;

}
void Clase::setHoraIni(double _horaIni){
    horaIni = _horaIni;

}
void Clase::setHoraFin(double _horaFin){
    horaFin = _horaFin;

}

void Clase::imprimeClase(){
    cout << nombre << " " << dias << " " << horaIni << "-" << horaFin << endl;
}