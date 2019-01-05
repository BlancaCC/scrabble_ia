/**
   @file testnuevaia.cpp
   @author Blanca Cano Camarero
   @date Enero 2019 
   @brief Test de prueba de ia.cpp
 */

#include <iostream>
#include "nueva_ia.h"
#include "diccionario.h"
using namespace std;


void muestraSoluciones( IA ia, string letras)
{
  vector<string > soluciones = ia.mejorSolucion(letras);

  string modo_juego = ia.modoPuntuacion() ? " puntos " : "longitud"; 
  
  cout << " -- Soluciones encontradas para   " << letras <<  " --"
       << endl  << "jugando  en modo " << modo_juego <<":" << endl ;
  
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
  muestraSoluciones( ia, "yaxohnswe");
  muestraSoluciones( ia, "cadamentealambi");

  
  cout << " --  Fin de la prueba IA, todo correcto (o eso parece) -- " << endl; 
  
}

