/**
   @brief: Implementación del TDA combinaciones
   @author Blanca Cano Camarero 
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
  arbol_combinaciones ( Elemento(elementos) ); 
}

bool Combinaciones::GeneracionSiguiente()
{
  //leemos último elemento y obtenemos posición de los elementos de la generación que vamos a expandir
 
  int inicio = ( arbol_combinaciones.back() ).inicio_generacion;
  int fin = ( arbol_combinaciones.back() ).inicio_generacion;

  //posicion final de la generacion futura
  int longitud = arbol_combinaciones[inicio].letras.length() ;
  if ( longitud > 1)
    {
      for( int padre = inicio ; padre < fin; padre++)
	{
	  int pos_final = (fin-inicio)*longitud+ fin;
	  // la posicion de inicio coincide con la de fin de sus padres
	  for( int letra_quitar= 0; letra_quitar< longitud ; letra_quitar++)
	    {
	      string nuevo_elemento = arbol_combinaciones[padre];
	      arbol_combinaciones.push_back( Elemento( nuevo_elemento.erase(nuevo_elemento.begin()+letra_quitar), fin, pos_final)); 
	    }
	}

    }

  return false; //si longitud <= 1 
  
} //~~~~~~ fin generación siguiente 


bool Combinaciones::analisisGeneracion( vector<string> & resultado)
{
  
  int inicio = ( arbol_combinaciones.back() ).inicio_generacion;
  int fin = ( arbol_combinaciones.back() ).inicio_generacion;

  for( int combinacion = inicio; combinacion < fin ; combincacion++)
    {
      //añadir comprobación de si está en la tabla hash
      cout << arbol_combinaciones[ combinacion].letras << endl; 
    }
}
