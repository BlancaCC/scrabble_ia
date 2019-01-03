/**
   @brief TDA combinaciones sin repetición y sin orden
   @author Blanca Cano Camarero 
   @date enero 2019
 */

#ifndef _COMBINACIONES_H_
#define _COMBINACIONES_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

/**
   @brief Diseñado en especial  para string :D
   Significado de las variables privadas: 
   *- combinaciones: combinación característica de este nodo
 */
struct Elemento
{
  string letras;
  int inicio_generacion;
  int fin_generacion;

  Elemento( string l, int i=0, int f=1);
}; 

class Combinaciones
{
 private:

  vector<Elemento> arbol_combinaciones;

 public:
  Combinaciones( string elementos);

  /**
     @brief amplia la siguiente generación dentro del vector
     @return  true si se ha podido generar, false en caso contrario 
   */
  bool GeneracionSiguiente();

  /**
     @brief analiza la siguiente generación
     @param resultado, vector con soluciones
     @param validos, diccionario con comprobaciones
     @return Devuelve true si ha encontrado alguna solución,
     false en su defecto 
   */
  bool analisisGeneracion( vector<string> & resultados, map< unsigned  long int, vector<string> > & validos ); 
  
}; 
  
#endif  //_COMBINACIONES_H_
