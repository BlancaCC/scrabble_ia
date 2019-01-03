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

  //posicion final de la generacion futura
  int longitud = arbol_combinaciones[inicio].letras.length() ;
  if ( longitud > 2)
    {
      for( int padre = inicio ; padre < fin; padre++)
      //for( int padre = inicio ; padre < longitud && padre < fin; padre++)
	{
	  // int pos_final = (longitud-1)(longitud+2) / 2; 
	  int pos_final = (fin-inicio)*longitud+ fin;
	  // la posicion de inicio coincide con la de fin de sus padres
	  
	  for( int letra_quitar= padre-inicio; letra_quitar< longitud ; letra_quitar++)
	    {
	      string nuevo_elemento = arbol_combinaciones[padre].letras; 
	      ///< Eliminamos la letra correspondiente
	      nuevo_elemento.erase( letra_quitar , 1);
	      string nuevas_letras = nuevo_elemento; 

	      arbol_combinaciones.push_back( Elemento( nuevas_letras, fin, pos_final) ); 
	    }
	}
      return true; 
    }

  return false; //si longitud <= 1 
  
} //~~~~~~ fin generación siguiente 


bool Combinaciones::analisisGeneracion( vector<string> & resultado , IA & ia)
{
  
  int inicio = ( arbol_combinaciones.back() ).inicio_generacion;
  int fin = ( arbol_combinaciones.back() ).fin_generacion;

  bool encontrado = false;
  
  for( int combinacion = inicio; combinacion < fin ; combinacion++)
    {
      unsigned long int llave = ia.traduce( arbol_combinaciones[ combinacion].letras);
      // comprobamos si está en el diccionario
      if ( ia.traduccion_diccionario.count(llave) )
	{
	  vector<string> incidencia = resultadotraduccion_diccionario[llave];
	  encontrado = true; 

	  ///hacer con un set y luego traducir para evitar repeticiones de soluciones 
	  resultado.insert(resultado.begin(), incidencia.begin(), incidencia.end() ); 
	  cout << arbol_combinaciones[ combinacion].letras
	       << " Se encuentra" << endl; 
	}
      
    }
  return encontrado; 
} //~~~~~~ analisisGeneracion
