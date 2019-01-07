/**
   @file juego.cpp
   @author Blanca Cano Camarero
   @brief Juego del scrabble
 */
#include <iostream>

#include <ia.h>
#include <letras.h>
#include <diccionario.h>

using namespace std;

/**
   Los parámetros de entrada son los siguientes: 
   - argv[1] : nombre del fichero con el diccionario
   - argv[2] : nombre del fichero con las letras
   - argv[3] : número de letras a generar aleatoriamente
   - argv[4] : modalidad: L gana longitud, P gana puntuación
 */
int main( int argc, char * argv [] )
{
  //~~~~~~~ preinicialización del juego ~~~~~~~~~~~

  // módulo para obtener puntuaciones
  conjuntoLetras cl ( argv[2]);
  Diccionario d ( argv[1]);
  string modo = argv[4]; 
  bool modo_puntos = ( modo == "P")? true : false;
  int cantidad = atoi(argv[3]);
  
  IA ia( d, modo_puntos,  cl.letrasValidas());

  //mesajes iniciales

  cout << " Bienvenido a esta maravillo juego de ingenio, risas y sonrisas : D" << endl;
  
  if( modo_puntos)
    {
      cout << " Usted a seleccionado jugar en modo puntos, aquí tiene las puntuaciones asociadas a cada  letra " << endl;
      cl.muestraPuntuacion();
    }
  else
    cout << " Usted ha seleccionado jugar en modo longitud" << endl;
  
  cout << "========================= <3 =======================" << endl; 

  //Comienza de juego

  bool jugando = true;
  string letras;
  string respuesta_usuario; 
    
  while( jugando )
    {
      // mostramos letras posibles
      letras = cl.sacaLetras( cantidad );
      cout << "Estas son las " << cantidad << " letras pedidas " << letras << endl
	   << "================================================" << endl
	   << "No sea tímido e introduzca una solución: ";
      // pedimos puntos y calculamos puntos teóricos
      cin >> respuesta_usuario;

      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl; 
      cout << "Puntos obtenidos en el teórico caso de que su repuesta sea válida, le dejo a usted mismo que se juzgue: " << endl
	   << ( (modo_puntos)?cl.puntuacionAsociada( respuesta_usuario):
		respuesta_usuario.length() ) << endl<< endl;  
      
      // calculamos soluciones
      cout << "Las mejores soluciones que yo conozco son: " << endl; 
      vector<string> soluciones = ia.mejorSolucion(letras, cl);
      
      for ( auto sol = soluciones.begin();
	    sol != soluciones.end(); sol++)
	{
	  cout << *sol << endl; 
	}

      // ¿continuar jugando?

      cout << "================================================" << endl
	<<"¿Desea usted otra ronda? [S/n) " ;
      cin >> respuesta_usuario;
      cout << "================================================" << endl; 

      if ( respuesta_usuario == "n" || respuesta_usuario == "N")
	jugando = false; 
	
    }

  cout << " Fin del juego, espero que haya tenido una experiencia agradable "
       << " positiva, revitalizante, divertida y repetible :D " << endl;
    
}
