/**
   @brief programa de prueba de combinaciones 
   @author Blanca Cano Camarero 
   @date Enero 2019
 */

#include "combinaciones.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
   @brief Muestra en pantalla la última generación creada de Combinacioness
   @param C estructura de combinaciones que mostrar en pantalla 
 */
void muestraGeneracion( const Combinaciones & C)
{
  vector<string> generacion=  C.UltimaGeneracion();

  for( int i=0 ; i< generacion.size(); i++)
    {
      cout << generacion[i] << " " ; 
    }
  cout << endl; 
}

// ~~~~~~~~~~~~~~


int main( int argc, char * argv [])
{
  //string letras = "01234";
  vector<string> letras ={"01234", "ABBAB"} ;

  for( int i= 0; i< letras.size(); i++)
    {
      cout << " COMBINACIONES DE " << letras[i] << endl; 
      Combinaciones C (letras[i]);
      vector<string> nulo;
      cout << "=========== otra generación ===========" << endl; 
      muestraGeneracion( C); 

      while( C.GeneracionSiguiente())
	{
	  cout << "=========== otra generación ===========" << endl; 
	  muestraGeneracion( C); 

	}
    }
}
