#pragma once
#include <string>
using namespace std;

class RFC {
  public:

  
  RFC();//Constructor por definición
  RFC(string,string,string);//Constructor por parámetros
  ~RFC();//Destructor

  string getNombre();//método para obtener nombre
  string getFecha();//método para obtener fecha
  string getLlave();//método para obtener llave

  friend std :: ostream& operator<<(std :: ostream&, RFC&);//sobrecarga de operador <<
  
  
  void setNombre(string);//modificador de nombre
  void setFecha(string);//modificador de fecha
  void setLlave(string);//modificador de llave  
  
  bool operator<(RFC);//sobrecarga de operador <
  bool operator<=(RFC);//sobrecarga de operador <=
  bool operator>(RFC);//sobrecarga de operador >

  private:
  string fecha;//variable fecha
  string nombre;//variable nombre
  string llave;//variable llave
};



RFC::RFC(){//constructor por variables vacías
  fecha="";
  nombre="";
  llave="";
}

RFC::RFC(string nombre,string fecha,string llave){//constructor con variables definidas
  this->fecha=fecha;
  this->nombre=nombre;
  this->llave=llave;
}

RFC :: ~RFC(){}//Destructor

string RFC::getNombre(){return nombre;}//Accesor de nombre
string RFC::getFecha(){return fecha;}//Accesor de fecha
string RFC::getLlave(){return llave;}//Accesor de llave

void RFC::setNombre(string nombre){this->nombre=nombre;}//modificador de nombre
void RFC::setFecha(string fecha){this->fecha=fecha;}//modificador de fecha
void RFC::setLlave(string llave){this->llave=llave;}//modificador de llave

/////////////////////////////////////

bool RFC :: operator<(RFC rfc){//sobrecarga de operador <
  if (nombre < rfc.getNombre())
    return nombre < rfc.getNombre();
  else if (nombre == rfc.getNombre())
    return fecha < rfc.getFecha();
  else if (fecha == rfc.getFecha())
    return llave < rfc.getLlave();
  return 0;
}

bool RFC :: operator<=(RFC rfc){//sobrecarga de operador <=
  if (nombre <= rfc.getNombre())
    return nombre <= rfc.getNombre();
  else if (nombre == rfc.getNombre())
    return fecha <= rfc.getFecha();
  else if (fecha == rfc.getFecha())
    return llave <= rfc.getLlave();
  return 0;
}

bool RFC :: operator>(RFC rfc){//sobrecarga de operador >
  if (nombre > rfc.getNombre())
    return nombre > rfc.getNombre();
  else if (nombre == rfc.getNombre())
    return fecha > rfc.getFecha();
  else if (fecha == rfc.getFecha())
    return llave > rfc.getLlave();
  return 0;
}

//cout objeto RFC
std :: ostream& operator<<(std :: ostream& salida, RFC& rfc){//sobrecarga de operador <<
  salida << rfc.getNombre() + rfc.getFecha() + rfc.getLlave();
  return salida;
}