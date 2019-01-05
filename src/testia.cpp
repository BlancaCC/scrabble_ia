/**
   @brief Fichero de prueba TEST IA
   @author Blanca Cano Camarero 
   @date enero 2019
 */

#include <iostream>

#include "ia.h"
#include "diccionario.h"
using namespace std; 

void muestraSolciones( IA ia, string letras)
{
  vector<string > soluciones = ia.mejorSolucion(letras);

  cout << "Soluciones encontradas para:  " << letras <<  endl; 
  for( auto sol= soluciones.cbegin(); sol != soluciones.cend(); sol++)
    cout << (*sol) << endl;
  
}


int main()
{
  Diccionario D;
  cin >> D;

  ///< Prueba del constructor
  bool modo_puntos = false; 
  IA ia( D, modo_puntos);

  muestraSoluciones( ia, "cola");
  muestraSoluciones( ia, "bejan");
  
  
  
}
