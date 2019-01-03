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

  /**
     @brief A cada caracter válido le asocia un número primo diferente
   */
  void asignaPrimos(string validas);

  /**
     @brief traduce las palabras de un diccionario a un primo, 
     Crea map donde a cada uno de los anteriores primos le asocia una palabra :D
   */
  void traduceDiccionario( Diccionario & soluciones);

  /**
     @brief Devuelve el primo asociado a una combinación 
     @param validad combinacio de letras 

   */
  unsigned long int traduce( string validas); 

 
 public:

  /**
     @brief constructor de la IA
     @param dicccionario, vocabulario del que dispondrá nuestra IA
     @param letras válidas 
   */
  IA( Diccionario & soluciones, string validas = "abcdefghijklmnopqrstuvwxyz" );

  /**
     @brief Devuelve las soluciones
     OJO IMPORTANTE QU ECOMBINCACIONES SEA UNA CLASE AMIGA
     @param String de caracteres con el que hacer las combincaioens
     @return Devuelve un vector de string con todas las soluciones
  */
  vector<string> devuelveSoluciones( string letras); 

  friend  class Combinaciones; //Hacer esta clase amiga

    
}; 



#endif //_IA_H
