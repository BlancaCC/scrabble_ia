/**
   @brief Implementación del TDA combinaciones
   @author Blanca Cano Camarero 
   @date Enero 2019
 */

#include "combinaciones.h"

Elemento::Elemento( string l, int i, int f)
{
  letras = l;
  inicio_generacion = i;
  fin_generacion = f;
}
 

Combinaciones::Combinaciones( string elementos)
{
  arbol_combinaciones.push_back( Elemento(elementos) ); 
}

// ¡ CON ESTE ALGORITMO SE PRODUCEN REPETICIONES! 
bool Combinaciones::GeneracionSiguiente()
{
  //leemos último elemento y obtenemos posición de los elementos de la generación que vamos a expandir
 
  int inicio = ( arbol_combinaciones.back() ).inicio_generacion;
  int fin = ( arbol_combinaciones.back() ).fin_generacion;


  ///< tomamos longitud mínima de la descendencia de 2, ya que no consideramos palabras a simpletes de letras
  int longitud = arbol_combinaciones[inicio].letras.length() ;
  if ( longitud > 2)
    {
      set<string> descendientes; ///< Utilizaremos set para evitar repeticiones, ( ejemplo ABBA )
      for( int padre = inicio ; padre < fin; padre++)
	{
	  // letra_quitar= padre-inicio
	  for( int letra_quitar= 0; letra_quitar< longitud ; letra_quitar++)
	    {
	      string nuevo_elemento = arbol_combinaciones[padre].letras; 
	      ///< Eliminamos la letra correspondiente
	      nuevo_elemento.erase( letra_quitar , 1);
	      descendientes.insert( nuevo_elemento);
	      //cout << nuevo_elemento << endl; 
	    }

	}
      // procedemos a añadirlos a arbolCombinaciones
      int pos_final = fin +  descendientes.size();
      ///< la posicion de inicio coincide con la de fin de sus padres
      
      for( auto cit = descendientes.cbegin(); cit != descendientes.cend(); cit++ )
	{
	  arbol_combinaciones.push_back( Elemento( (*cit) , fin, pos_final) );
	}
      return true; 
    }

  return false; //si longitud <= 1 
  
} //~~~~~~ fin generación siguiente 


vector<string> Combinaciones::UltimaGeneracion() const
{

  vector<string> generacion;
  
  int inicio = ( arbol_combinaciones.back() ).inicio_generacion;
  int fin = ( arbol_combinaciones.back() ).fin_generacion;

  for( int i=inicio; i< fin ; i++)
    {
      generacion.push_back( arbol_combinaciones[i].letras);
    }
  return generacion; 
  
} // ~~~~~~ ultimaGeneración














/**
bool analisisGeneracion( vector<string> & resultado , IA & ia, Combinaciones C)
{
  
  int inicio = C.( arbol_combinaciones.back() ).inicio_generacion;
  int fin = C.( arbol_combinaciones.back() ).fin_generacion;

  bool encontrado = false;
  
  for( int combinacion = inicio; combinacion < fin ; combinacion++)
    {
      unsigned long int llave = ia.traduce( C.arbol_combinaciones[ combinacion].letras);
      // comprobamos si está en el diccionario
      if ( ia.traduccion_diccionario.count(llave) )
	{
	  vector<string> incidencia = ia.traduccion_diccionario[llave];
	  encontrado = true; 

	  ///hacer con un set y luego traducir para evitar repeticiones de soluciones 
	  resultado.insert(resultado.begin(), incidencia.begin(), incidencia.end() ); 
	  cout << c.arbol_combinaciones[ combinacion].letras
	       << " Se encuentra" << endl; 
	}
      
    }
  return encontrado; 
} //~~~~~~ analisisGeneracion

*/
