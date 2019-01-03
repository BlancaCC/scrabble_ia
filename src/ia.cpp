/**
   @file ia.cpp 
   @author Blanca Cano Camarero 
   @brief Implementación de inteligencia artificial para jugar al scrabble 
   @date enero de 2019
 */


#include "ia.h"

//string por defecto "abcdefghijklmnopqrstuwxyz"
IA:: IA( Diccionario & soluciones, string validas)
{
  
  asignaPrimos(validas);
  traduceDiccionario(soluciones);
  
} //~~~~~~~~~~ fin constructor 


//string IA::devuelveSoluciones()
  
// ################# funciones privadas ##############

void IA::asignaPrimos( string validas)
{
  const string fichero_primos = "./data/primos"; 
  int primos_necesarios = validas.length();

  //abrimos con capacidad de lectura y escritura
  ifstream f_primos (fichero_primos);
  
  
  if(! f_primos.is_open() )
    {
      cout << "No se ha podido abrir el archivo con los primos " << endl; 
      assert(f_primos);
    }
  
  int indice = 0;
  int num_primo;
  
  while ( indice < primos_necesarios && f_primos >> num_primo)
    {
      // cout << validas[ indice] << " : " << num_primo << endl;
      primos[ validas[ indice] ] = num_primo; 
      indice++; 
    }
  
  //si el fichero contiene menos primos de los necersarios,
  // procedo a calcularlos y añadirlos al fichero
  f_primos.close();
  
  ofstream out_primos ( fichero_primos, ios::app);
  while( indice < primos_necesarios)
    {
      num_primo+= 2; 
      bool es_primo = true;
      for( int i = 0; es_primo && i < indice ; i++)
	{
	  if (num_primo % primos[ validas[i] ] == 0)
	    es_primo = false;
	}
      if( es_primo)
	{
	  //cout << validas[ indice] << " : " << num_primo<< " (ha sido primo de repesca)"<< endl;
	   primos[ validas[ indice] ] = num_primo; 
	   indice++;
	   out_primos << num_primo << endl; 
	}
    }
    out_primos.close(); 
} //~~~~~~~ fin asigna primos


void IA::traduceDiccionario( Diccionario & soluciones)
{
  for( auto cit = soluciones.cbegin(); cit != soluciones.cend(); cit++)
    {
      ///< calculamos la entrada de la tabla hash correspondiente
      ///< resultado de multiplicar cada caracter por su primo asociado
      string palabra = (*cit); 
     
     unsigned long long int entrada = 1;
      for( int i= 0; i< palabra.length(); i++)
	{

	  if ( primos.find((*cit)[i] ) != primos.end() )
	    entrada *= primos[ (*cit)[i] ];
	  else
	    {
	      entrada = 0;
	      cout << "No se ha enconctrado " << (*cit)[i] << endl;
	      break; 
	    }
	}
      // cout << "Se está leyendo "  << palabra << " código en tabla hash    " << entrada << endl; 
      
      traduccion_diccionario[ entrada ].push_back( (*cit));
    }
}  //~~~~~~~ traduceDiccionario 

unsigned long int IA::traduce ( string validas)
{unsigned long int
  unsigned long int indice = 1; 
  for( int i=0; i< validas.length(); i++)
    indice *= primos[ validas[i] ];

  return indice; 
} // traudce 


// ########## miembros públicos ############

vector<string> IA::devuelveSoluciones( string letras)
{
  Combinaciones C (letras);
  vector<string> soluciones;
  bool encontrado = false;

  
  unsigned long int llave = traduce(letras); 
  //si se encuentra tal solucion en el diccionario 
  if(  traduccion_diccionario.count( llave ))
    {
      return traduccion_diccionario[llave]; 
    }
  if( C.GeneracionSiguiente() && !encontrado  )
    {
      encontrado = C.analisisGeneracion( soluciones, (*this) ); 
    }
    return vector<string>(); 
} //~~~~~~ devuelveSoluciones

/*
  Util a la hora de implementar 

 C.analisisGeneracion(nulo);

  while( C.GeneracionSiguiente())
    {
      cout << "=========== otra generación ===========" << endl; 
      C.analisisGeneracion(nulo);
    }
 */
