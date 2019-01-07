# Práctica final

Creación de un programa que da letras, pide respuesta y da la mejor palabra que conozca que se pueda formar con tales combinaciones. 
Blanca Cana Camarero
Enero 2019 

## Desarrollo del proyecto

El programa se ha diseñado con los siguientes módulos:
- diccionario
- letras  
- biblioteca
- combinaciones
- ia 
- juego

Procedemos a comentarlos.

### Diccionario

Puede encontrar el código fuente en:
- include/diccionario.h
- src/diccioanario.cpp

Así como un test en src/testdiccionario.cpp

Este módulo es utilizado como estructura para guardar las combinaciones válidas de nuestro juego.
Para ver en profundizad sus miembros ver la documentación gnerada con doxigen.  


### Letras  
Emancipándonos un tanto de la estructura propuesta en el guión final, he decido agrupar cantidad de letras y bolsa de letras en un mismo módulo con el objetivo de aprovechar la frecuencia para con un algoritmo generar de esta forma las puntaciones. Por lo demás he respetado la funcionalidades que se le pide a cada uno e incluso completado. 


### Biblioteca  

La idea de la biblioteca es que a partir de un diccionario genera una tabla hash, donde cada entrada almacena
todas las palabras con las mismas combinaciones de letras. 

### Combinaciones  
Combinaciones es un árbol camuflado, que genera combinaciones con repetición y sin orden.  
Además tiene la peculiaridad de que no se construye del tirón si no que conforme se vaya demandando. 

### ia  
Estructura que simula a un jugador. Unifica los módulos biblioteca y combinaciones con el objetivo de encontrar con ello 
las soluciones válidas. 

Para dotar el juego de una mayor dificultad bastará con darle un diccionario más completo. 
(Los diccionarios de los que se disponen la verdad es que son bastante incompletos con el español al uso). 

### Juego   
Programa principal si lo que se desea es jugar. 
