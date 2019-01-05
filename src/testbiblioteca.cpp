/**
   @brief Fichero de prueba TEST IA
   @author Blanca Cano Camarero 
   @date enero 2019
 */

#include <iostream>

#include "biblioteca.h"
#include "diccionario.h"
using namespace std; 

int main()
{
  Diccionario D;
  cin >> D;

  ///< Prueba del constructor
  Biblioteca B ( D); 
}
