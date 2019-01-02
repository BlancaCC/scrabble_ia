/**
   @file ia.h
   @author Blanca Cano Camarero 
   @brief TDA de inteligencia artificial para jugar al scrabble 
   @date enero de 2019
 */


#ifndef _IA_H_
#define _IA_H_

#include<iostream>
#include <vector>
#include <string>
#include <map>

#include "diccionario.h"
#include "combinaciones.h"

#include <fstream>
#include <assert.h>

using namespace std; 

/**
   @brief TDA IA Jugador del scrabble

 */
class IA
{
 private:
  // ~~~~~~~~~~~~ variables y métodos de carga ~~~~~~~~~~~
  map< char, int> primos;
  map< unsigned  long int, vector<string> > traduccion_diccionario;

  void asignaPrimos(string validas);
  void traduceDiccionario( Diccionario & soluciones);

 
 public:

  /**
     @brief constructor de la IA
     @param dicccionario, vocabulario del que dispondrá nuestra IA
     @param letras válidas 
   */
  IA( Diccionario & soluciones, string validas = "abcdefghijklmnopqrstuvwxyz" );

  string devuelveSoluciones( string letras); 

  //friend bool Combinaciones.analisisGeneracion; //Hacer esta clase amiga

    
}; 



#endif //_IA_H
