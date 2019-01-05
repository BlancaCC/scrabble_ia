/**
   @file ia.cpp 
   @author Blanca Cano Camarero 
   @brief Implementación de inteligencia artificial para jugar al scrabble 
   @date enero de 2019
 */

#include "nueva_ia.h"

IA::IA(  Diccionario & D, bool modo_puntos , string validas)
{
  conocimiento = Biblioteca( D , validas); 
  modo_puntuacion = modo_puntos;
} //~~~~~ fin del constructor 


bool IA::modoPuntuacion() const
{
  return modo_puntuacion; 
} //~~~~~ fin modo puntuación 



vector<string> IA::mejorSolucion( string letras )
{
  if ( modo_puntuacion )
    return solucionesLongitud( letras); //solucionesPuntos( letras);
  else
    return solucionesLongitud( letras); 
} // ~~~~~~~~ mejor solucion general 


//#### MÉTODOS DE BÚSQUEDA PARTICULARES  ########

vector<string> IA::solucionesLongitud( string letras )
{

  /*
    Lo interesante que permite Combinaciones es que en longitud, 
    los "padres" del árbol van a tener estrictamente mayor puntuación
    por tanto, en cuanto encontremos en una "generación" una solución
    sabremos que esa y sus hermanas serán las mejores soluciones
    y no hará falta seguir generando y explorando el árbol. 
   */
  
  Combinaciones C(letras);
  vector<string> soluciones;

  bool puedeDividirse =  true;
  bool encontrado = false;
  
  while (!encontrado &&  puedeDividirse )
    {
      vector<string> candidatos = C.UltimaGeneracion(); 
      for( auto candidato = candidatos.cbegin(); candidato != candidatos.cend(); candidato++ )
	{
	  //traducimo las letras actuales a la clave que tendría si estuviera en las posibles soluciones traduccion_diccionario 
	  unsigned long int codigo_primo = conocimiento.traduce( (*candidato) );
	  //comprobamos si se encuentra en las soluciones
	  if( conocimiento.traduccion_diccionario.count( codigo_primo))
	    {
	      vector<string> nuevas_soluciones  = conocimiento.traduccion_diccionario[codigo_primo];

	      //añadimos las nuevas soluciones al final del  vector de soluciones a devolver
	      soluciones.insert( soluciones.end(), nuevas_soluciones.begin(), nuevas_soluciones.end());
	      encontrado = true; 
	    } 
	} // for candidatos

      // si no se ha encontrado se genera la siguiente generación de combinaciones
      // y se guarda si es la última o no en puedeDivirse
      if ( !encontrado )
	puedeDividirse = C.GeneracionSiguiente(); 
  
    } // WHILE se puedan crear más generaciones o se encuentre

  return soluciones; 
  
} //~~~~~~ soluciones por longitud


vector<string> solucionesPuntos( string letras , conjuntoLetras & cl)
{
  /*
    Aquí no podemos aplicar la idea de soluccionesLongitud,
    si embargo podemos podar el árbol de la siguiente manera:

    Cuando se haya producciodo un encuentro de una solución está tendrá una puntuación asociada, 
    se eliminarán de la lista de candidatos a seguir explorando, los que potencialmente tengan  una puntuación menor
    
    Cuando se produzca una combinación con solución,
    almacenaremos la incidencia en un diccionario cuya clave es su puntuación
    Finalmemnte devolveremos la estructura con mayor puntuación. 
   */
  
  map < int, vector<string> > puntos_soluciones;
  int puntuacion_maxima = -1; //suponemos que la puntuación no puede ser negativa

  Combinacione C ( letras);

  bool seguirExplorando = true;

  while ( seguirExplorando )
    {
     vector<string> candidatos = C.UltimaGeneracion();
     
      for( auto candidato = candidatos.cbegin(); candidato != candidatos.cend(); candidato++ )
	{
	  // si el candidato es potencialmente de puntuación menor, directamente lo eliminamos
	  if ( cl.puntuacionAsociada(*candidato) < puntuacion_maxima)
	    {
	      //algoritmo para eliminar, no tengo fuerzas para continuar
	    }
	  else
	    {
	    
	      //traducimo las letras actuales a la clave que tendría si estuviera en las posibles soluciones traduccion_diccionario
	      unsigned long int codigo_primo = conocimiento.traduce( (*candidato) );
	  
	      //comprobamos si se encuentra en las soluciones
	      if( conocimiento.traduccion_diccionario.count( codigo_primo))
		{
		  //vemos la puntuación
	      
		  vector<string> nuevas_soluciones  = conocimiento.traduccion_diccionario[codigo_primo];

		  //añadimos las nuevas soluciones al final del  vector de soluciones a devolver
		  soluciones.insert( soluciones.end(), nuevas_soluciones.begin(), nuevas_soluciones.end());
		  encontrado = true; 
		}  
	    } // else potencial de puncuación mayor
	  
      seguirExplorando = C.GeneracionSiguiente(); 
    }

  
  return (puntuacion_maxima > -1)?  puntos_soluciones[ puntuacion_maxima] : vector <string> vacio; 
  
} // ~~~~~~ soluciones por puntos 
