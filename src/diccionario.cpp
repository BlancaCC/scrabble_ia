
/**
   @brief Implementación del TDA diccionario 
   @file diccionario.cpp  
   @author Blanca Cano Camarero 
   @date diciembre 2018
 */

#include <iostream>
using namespace std;

#include "diccionario.h"

#include <vector>
#include <string>
 

Diccionario::Diccionario()
{
  set<string> datos;
}


/**Diccionario::Diccionario( string palabra)
{
  set<string> datos;
  agregarPalabra( palabra); 
}
*/
Diccionario::Diccionario( string nombre_fichero)
{
  set<string> datos;

  ifstream fichero (nombre_fichero);

  // combrobamos que se ha abierto correctamente
  // en caso negativo mensaje de error y abortamos el programa
  if( ! fichero.is_open() )
    {
      cout << "No se ha podido abrir el fichero con las palabras" << endl;
      assert( fichero); 
    }

  string palabra;
  while ( fichero  >> palabra )
    {
      agregarPalabra( palabra); 
    }
  //para que no falte por añadir la última palabra
  agregarPalabra( palabra); 
  fichero.close(); 
  
}  // ~~~ constructor a partir de fichero con palabras 
 



// ################ funcines públicas ########################


void Diccionario::agregarPalabra( string palabra)
{
  datos.insert( palabra);

}
//~~~~~ agregarPalabra

int Diccionario::size() const 
{
  return datos.size();
}
//~~~~ size


vector<string> Diccionario::palabrasLongitud( int longitud)
{
  
  vector<string> encuentros; 

  for ( auto cit= datos.cbegin(); cit != datos.cend(); cit++)
    {
      if(cit->length() == longitud )
	encuentros.push_back( *cit ) ;
    }
  return encuentros; 
}
//~~~~ palabraLongitud

bool Diccionario::esta(string palabra) const 
{
  
  auto cit = datos.find(palabra);
  
  if (cit != datos.cend())
    return true;
  else
    return false; 
}
//~~~~ esta


// ~~~~~~~~~~~~~~~~ sobrecarga operadores entrada salida ~~~~~~~~~~~~~~~~~~~~~~~~
ostream & operator <<(ostream & os, const Diccionario & D)
{
  for ( auto cit = D.cbegin(); cit != D.cend(); cit++)
    {
      os << (*cit) << endl; 
    }
  return os;
}

//~~~~ operator << 


istream & operator >> (istream & is, Diccionario & D)
{
  string palabra;
  while ( getline(is, palabra))
    D.agregarPalabra(palabra);

  return is; 
}


//~~~~~~~~~~~~~~~~~ iteradores de diccionario  ~~~~~~~~~~~~~~~~~~~~~~~

set<string>::const_iterator Diccionario::cbegin() const
{
  return datos.cbegin();
}
set<string>::const_iterator Diccionario::cend()  const
{
  return datos.cend(); 
}

//~~~~~~ fin iterados 
