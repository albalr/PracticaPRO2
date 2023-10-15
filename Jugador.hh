/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef _JUGADOR_HH_
#define _JUGADOR_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std; 
#endif

/** @class Jugador
    @brief Representa un jugador.
*/

class Jugador {

private: 

  /** @brief Posición del ranking en la que está el jugador.
  */
  int pos_ranking; 

  /** @brief Puntos del jugador.
  */
  int puntos; 

  /** @brief Torneos disputados por el jugador.
  */  
  int torneos_disputados; 

  /** @brief Partidos ganados y perdidos, respectivamente.
  */
  pair<int, int> partidos; 

  /** @brief Sets ganados y perdidos, respectivamente.
  */
  pair<int, int> sets; 

  /** @brief Juegos ganados y perdidos, respectivamente.
  */
  pair<int, int> juegos; 

public:
  //Constructoras

  /** @brief Creadora por defecto.
        
    Se ejecuta automáticamente al declarar un jugador.
    \pre <em>cierto</em>
    \post El resultado es un jugador con 0 puntos, situado en última posición del ranking y con las estadísticas globales inicializadas a 0.
  */
  Jugador();

  //Consultoras 

  /** @brief Consultora de la posición del ranking.
    \pre <em>cierto</em>
    \post El resultado es la posicion del ranking del parámetro implícito.
  */
  int consultar_posicion_ranking();

  //Modificadoras

  /** @brief Actualizan los puntos del jugador, sumando o restando.
    \pre p >= 1
    \post Quedan actualizados los puntos del jugador.
  */
  void actualizar_puntos_jugador(int p, bool sumar);

  /** @brief Modifica la posición del jugador en el ranking
    \pre  i >= 1 
    \post Queda actualizada la posición del jugador en el ranking.
  */
  void modificar_posicion_ranking(int i);

  /** @brief Modifica los torneos disputados por el jugador.
    \pre <em>cierto</em>
    \post Queda añadido un torneo disputado más por el jugador.
  */
  void modificar_torneos_disputados();

  /** @brief Modifica los partidos ganados por el jugador.
    \pre partidos_ganados >= 1
    \post Quedan actualizados los partidos ganados.
  */
  void modificar_partidos_ganados(int partidos_ganados);

  /** @brief Modifica los partidos perdidos por el jugador.
    \pre partidos_perdidos >= 1
    \post Quedan actualizados los partidos perdidos.
  */
  void modificar_partidos_perdidos(int partidos_perdidos);

  /** @brief Modifica los sets ganados por el jugador.
    \pre sets_ganados >= 1
    \post Quedan actualizados los sets ganados.
  */
  void modificar_sets_ganados(int sets_ganados);

  /** @brief Modifica los sets perdidos por el jugador.
    \pre sets_perdidos >= 1
    \post Quedan actualizados los sets perdidos.
  */
  void modificar_sets_perdidos(int sets_perdidos);

  /** @brief Modifica los juegos ganados por el jugador.
    \pre juegos_ganados >= 1
    \post Quedan actualizados los juegos ganados.
  */
  void modificar_juegos_ganados(int juegos_ganados);

  /** @brief Modifica los juegos perdidos por el jugador.
    \pre juegos_perdidos >= 1
    \post Quedan actualizados los juegos perdidos.
  */
  void modificar_juegos_perdidos(int juegos_perdidos);

  //Escritura

  /** @brief Operación de escritura.

      \pre El parámetro implícito está inicializado.
      \post Escribe el identificador del jugador y todos sus atributos.
    */
  void listar_jugador();

};
#endif
