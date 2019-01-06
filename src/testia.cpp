/**
   @file testnuevaia.cpp
   @author Blanca Cano Camarero
   @date Enero 2019 
   @brief Test de prueba de ia.cpp
 */

#include <iostream>
#include "ia.h"
#include "diccionario.h"
#include "letras.h"

using namespace std;


void muestraSoluciones( IA ia, string letras, conjuntoLetras & cl)
{
  vector<string > soluciones = ia.mejorSolucion(letras, cl);

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
  
  conjuntoLetras cl;
  cl.analizarDiccionario(D);
  
  muestraSoluciones( ia, "cola" , cl );
  muestraSoluciones( ia, "yaxohnswe" , cl);
  muestraSoluciones( ia, "cadamentealambi" , cl);

  
  cout << " --  Fin de la prueba IA, todo correcto (o eso parece) -- " << endl; 
  
}

