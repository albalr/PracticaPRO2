/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_jugadores
*/
#ifndef CONJ_JUGADORES_HH
#define CONJ_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#include <algorithm>
#endif

/** @class Cjt_jugadores
    @brief Representa un conjunto de jugadores.
*/

class Cjt_jugadores {

private: 

  /** @brief Representa el conjunto de jugadores.
  */
  map<string, Jugador> jugadores; 

  /** @brief Información del vector del ranking del circuito.
  */
  struct ranking {
    string identificador;
    int puntos;
    int posicion_anterior;
  };
  
  /** @brief Representa el ranking de jugadores del circuito.
  */
  vector<ranking> ranking_jugadores; 

  /** @brief Operación de comparación para la ordenación de un vector.
      
    \pre <em>cierto</em>
    \post Retorna verdadero o falso, para ordenar el ranking según los puntos y/o la posición anterior del jugador en el ranking.
  */
  static bool comp(const ranking& a, const ranking& b);

public:
  //Constructoras

  /** @brief Creadora por defecto.
      
      Se ejecuta automáticamente al declarar un conjunto de jugadores.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de jugadores vacío. 
  */
  Cjt_jugadores();

  //Consultoras

  /** @brief Consultora de un jugador.

    \pre Identificador sintácticamente correcto.
    \post El resultado son los datos que definen al jugador con el identificador del parámetro.
  */
  Jugador consultar_jugador(const string& identificador);

  /** @brief Consultora del nombre de un jugador.

    \pre pos_ranking >= 1
    \post El resultado es el nombre/identificador del jugador.
  */
  string consultar_nombre_jugador(int pos_ranking);

  /** @brief Consultora de la existencia de un jugador.

    \pre Identificador sintácticamente correcto.
    \post El resultado es si existe o no el jugador con el identificador del parámetro.
  */
  bool existe_jugador(const string& identificador);

  /** @brief Consultora del número de jugadores.

    \pre <em>cierto</em>
    \post El resultado es el número de jugadores del conjunto de jugadores.
  */
  int numero_jugadores();

  //Modificadoras

  /** @brief Añade un jugador.
    \pre El parámetro implícito está inicializado, con 0 puntos en el circuito, última posición en el ranking y estadísticas globales inicializadas a 0. 
    \post El parámetro implícito pasa a contener los jugadores originales más el jugador p.
  */
  void anadir_jugador(const string& identificador);

  /** @brief Elimina un jugador.
    \pre  String con un nombre/identificador sintácticamente correcto.
    \post El parámetro implícito pasa a contener los jugadores originales menos el jugador con el identificador del parámetro.
  */
  void eliminar_jugador(const string& identificador);
  
  /** @brief Actualiza el ranking del circuito.
    \pre  <em>cierto</em>
    \post Quedan actualizadas las posiciones del ranking del circuito, así como la posición anterior con la que comparar a los jugadores en caso de empate.
  */
  void actualizar_ranking_circuito();
  
  /** @brief Actualiza los puntos de un jugador del conjunto.
    \pre  puntos_torneo >= 0
    \post Se actualizan los puntos del jugador con el identificador del parámetro, o bien sumándole o bien restándole.
  */
  void actualizar_puntos(string identificador, int puntos_torneo, bool sumar);

  /** @brief Actualiza las estadísticas globales.
  \pre  <em>cierto</em>
  \post Quedan actualizados los juegos ganados y perdidos, los sets ganados y perdidos y los partidos ganados y perdidos.
  */
  void actualizar_estadisticas_globales(string ganador, string a, string b, string resultado);

  /** @brief Actualiza los torneos disputados.
  \pre  <em>cierto</em>
  \post Quedan actualizados los torneos disputados por cada jugador.
  */
  void actualizar_torneos_disputados(const string& identificador);

  //Lectura y Escritura
  
  /** @brief Operación de lectura.

    \pre Estan preparados en el canal estándar de entrada un entero P >= 0 que representa el número de elementos que leeremos, seguido de P strings con los nombres de los jugadores.
    \post El parámetro implícito contiene el conjunto de jugadores leídos del canal estándar de entrada.
  */
  void leer_jugadores();

  /** @brief Operación de escritura.

    \pre El parámetro implícito está inicializado.
    \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida.
  */
  void listar_jugadores();

  /** @brief Operación de escritura.

    \pre El parámetro implícito está inicializado.
    \post Escribe a los jugadores y sus puntos en orden, según su posición en el ranking. 
  */
  void listar_ranking();
    
};
#endif

