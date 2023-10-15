/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH_
#define _TORNEO_HH_

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std; 
#include <vector>
#include "BinTree.hh"
#include <cmath>
#endif

/** @class Torneo
    @brief Representa un torneo.
*/ 

class Torneo {

private: 

  /** @brief Categoría de un torneo.
  */
  int categoria;

  /** @brief Conjunto de información que define a los jugadores del torneo actual y/o anterior.
  */
  struct jugador_puntos {
      string identificador; 
      int puntos_torneo;
  };

  /** @brief Representa los jugadores y sus puntos en la edición anterior de un torneo.
  */
  vector<jugador_puntos> torneo_anterior;

  /** @brief Representa los jugadores y sus puntos en la edición actual de un torneo.
  */
  vector<jugador_puntos> torneo_actual;

  /** @brief Representa los emparejamientos iniciales de un torneo que se va a iniciar.
  */
  BinTree<int> arbol_emparejamiento;

  /** @brief Representa los resultados de los diferentes partidos que se han jugado.
  */
  BinTree<string> arbol_resultados;

  /** @brief Confecciona el árbol de emparejamientos inicial.
      
    \pre <em>cierto</em>
    \post Queda generado el árbol de emparejamientos, las hojas son los partidos que se van a disputar inicialmente, los otros valores son provisionales.
  */
  static void generar_bintree_emp(BinTree<int>& arbol_emparejamiento, int num_nodos, int raiz, int num_jugadores);

  /** @brief Escribe las hojas del árbol de emparejamiento.
      
    \pre <em>cierto</em>
    \post Se escriben los enfrentamientos inciales del torneo que se va a disputar.
  */
  void escribir_bintree_emp(const BinTree<int>& arbol_emparejamiento);

  /** @brief Lee los resultados de los diferentes partidos del torneo.
      
    \pre <em>cierto</em>
    \post Queda confeccionado un árbol con los diferentes resultados del torneo. 
  */
  static void leer_bintree_resultados(BinTree<string>& arbol_resultados, string marca);

  /** @brief Confecciona el árbol con los ganadores correspondientes de cada partido. 
      
    \pre <em>cierto</em>
    \post Queda generado el árbol de ganadores, en función del árbol de resultados.
  */
  BinTree<int> arbol_ganadores(const BinTree<string>& arbol_resultados, const BinTree<int>& aux, Cjt_jugadores& jugadores);

  /** @brief Elige el ganador de un partido. 
      
    \pre <em>cierto</em>
    \post Retorna el ganador, en función del resultado del partido.
  */
  static int escoger_ganador(string resultado, int a, int b);

  /** @brief Calcula los puntos que gana cada jugador. 
      
    \pre nivel >= 4
    \post Calcula los puntos que gana cada jugador, en función del nivel en el que esté y de la categoría del torneo.
  */
  void calcular_puntos(const BinTree<int>& arbol_emparejamiento, int nivel, Cjt_categorias& categorias);

  /** @brief Escribe el ranking local del torneo que se ha disputado.
      
    \pre <em>cierto</em>
    \post Escribe a los jugadores por orden del ranking local del torneo, junto con los puntos que ha ganado.
  */
  void escribir_puntos_torneo(Cjt_jugadores& jugadores);

  /** @brief Escribe el cuadro de resultados definitivo del torneo.
      
    \pre <em>cierto</em>
    \post Escribe todos los partidos jugados en el torneo, con sus contrincantes y con el resultado que han obtenido.
  */
  void escribir_cuadro_resultados(const BinTree<int>& arbol_emparejamiento, const BinTree<string>& arbol_resultados);

public:

  //Constructoras

  /** @brief Creadora con valores concretos. 

      \pre <em>cierto</em>
      \post El resultado es un torneo con categoría >= 1.
  */
  Torneo(int categoria);

  //Consultoras

  /** @brief Consultora de la categoría del torneo.
      \pre <em>cierto</em>
      \post El resultado es la categoría a la que pertenece el torneo.
  */
  int consultar_categoria() const;

  //Modificadoras

  /** @brief Resta los puntos a los jugadores que participaron en un torneo que se vuelve a disputar.
    \pre  <em>cierto</em>
    \post Se restan los puntos a todos los jugadores de la edición anterior de un torneo que se vuelve a disputar y que aún forman parte del circuito. 
  */
  void restar_puntos(Cjt_jugadores& jugadores);

  /** @brief Reestablece los puntos de un jugador, dado de baja, en la edición anterior de un torneo. 
    \pre <em>cierto</em>
    \post Quedan reestablecidos a 0 los puntos del jugador con identificador <em>identificador_j</em>.
  */
  void puntos_edicion_anterior_t(const string& identificador_j);

  /** @brief Inicia un torneo.
    \pre  <em>cierto</em>
    \post Queda iniciado el torneo, se leen las incripciones y se confecciona el cuadro de emparejamiento.
  */
  void iniciar_torneo_t(Cjt_jugadores& jugadores);

  /** @brief Finaliza un torneo.
    \pre  <em>cierto</em>
    \post Queda finalizado el torneo, se leen los puntos obtenidos, se confecciona el cuadro de resultados, se actualizan los puntos para el ranking y se actualizan las estadísticas globales de los jugadores y el ranking.
  */
  void finalizar_torneo_t(Cjt_jugadores& jugadores, Cjt_categorias& categorias);
};
#endif
