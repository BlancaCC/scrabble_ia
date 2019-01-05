/**
   @brief TDA combinaciones sin repetición y sin orden
   @file combinaciones.h 
   @author Blanca Cano Camarero 
   @date enero 2019
 */

#ifndef _COMBINACIONES_H_
#define _COMBINACIONES_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std; 

/**
   @brief Diseñado en especial  para string :D
   Significado de las variables privadas: 
   *- combinaciones: combinación característica de este nodo
 */
struct Elemento
{
  
  string letras;            ///< Combinación de este elemento 
  int inicio_generacion;    ///< Índice de inicio de la generación en la que se produzco tal combinación 
  int fin_generacion;       ///< Índice final de la generación 

  /**
     @brief Constructor de Elemento 
     @param l letras de la combinación 
     @param i, corresponde al inicio_generación 
     @param j : corresponde con el fin de la generación 
   */
  Elemento( string l, int i=0, int f=1);
  
}; 

struct Combinaciones
{
  /**
     @brief Vector cDevuelve vector con la última generación creadaon todas las combinaciones
   */
  vector<Elemento> arbol_combinaciones;

  /**
     @brief constructor de copia
     @param string sobre el que se quieren calcular las combinaciones sin orden y sin repetición de elementos 
   */
  Combinaciones( string elementos);

  /**
     @brief amplia la siguiente generación, añadiéndola al final de arbol_combinaciones
     @return  true si se ha podido generar, false en caso contrario 
   */
  bool GeneracionSiguiente();

  /**
     @brief Devuelve vector con la última generación creada
     @return Devuelve vector con la última generación creada
   */
  vector<string> UltimaGeneracion() const; 

}; 

#endif  //_COMBINACIONES_H_
