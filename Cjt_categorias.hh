/** @file Cjt_categorias.hh
    @brief Especificación de la clase Cjt_categorias
*/

#ifndef CONJ_CATEGORIAS_HH
#define CONJ_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_categorias
    @brief Representa un conjunto de categorías.
*/
class Cjt_categorias {

private: 

  /** @brief Nombres de las categorías del circuito.
  */
  vector<string> nombres_categorias;

  /** @brief Matriz con los puntos por nivel y categoría.
  */
  vector<vector<int> > puntos_nivel; 

public:

  //Constructoras

  /** @brief Creadora por defecto.
    Se ejecuta automáticamente al declarar un conjunto de categorías.
    \pre categoria_max >= 1, nivel_max >= 4
    \post El resultado es un conjunto de categorías con nivel y categoría máxima.
  */
  Cjt_categorias(int categoria_max, int nivel_max); 
    
  //Consultoras 

  /** @brief Consultora de la categoría máxima.

    \pre <em>cierto</em>
    \post El resultado es la categoría máxima del torneo.
  */
  int categoria_maxima();

  /** @brief Consultora del identificador de la categoría.

    \pre cat >= 1
    \post El resultado es el nombre de la categoría.
  */
  string consultar_identificador_cat(int cat) const;
  

  /** @brief Consultora de los puntos por nivel y categoría.

    \pre categoria >= 1, nivel >= 4
    \post El resultado son los puntos que ha ganado un jugador según el nivel en el que ha quedado y la categoría del torneo.
  */  
  int consultar_puntos_cat_nivel(int categoria, int nivel) const;

  //Lectura y Escritura

  /** @brief Operación de lectura.

    \pre Está preparada en el canal estándard de entrada una secuencia de C strings, que son los nombres de las categorías, y de C x K enteros >= 0, que representan los puntos por categoría c y nivel k.
    \post El parámetro implícito contiene el conjunto de categorías leídos del canal estándar d'entrada.
  */
  void leer_categorias();

  /** @brief Operación de escritura.

    \pre El parámetro implícito está inicializado.
    \post Escribe los identificadores de las categorías y la tabla de puntos por niveles del parámetro implícito por el canal estándar de salida. 
  */
  void listar_categorias();
};
#endif