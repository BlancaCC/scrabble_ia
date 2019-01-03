/**
   @brief programa de prueba de combinaciones 
   OJO QUE EN ANÁLISIS GENERACIÓN TODOS LOS RESULTADO SON VÁLIDO 
Y LO QUE SE HACE ES UN PRINT
 */

#include "combinaciones.h"

using namespace std;

int main()
{
  string letras = "01234";
  Combinaciones C (letras);

  vector<string> nulo;
  cout << "=========== otra generación ===========" << endl; 
  C.analisisGeneracion(nulo);

  while( C.GeneracionSiguiente())
    {
      cout << "=========== otra generación ===========" << endl; 
      C.analisisGeneracion(nulo);
    }
}
