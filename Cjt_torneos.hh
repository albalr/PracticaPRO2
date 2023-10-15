/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_torneos
*/

#ifndef CONJ_TORNEOS_HH
#define CONJ_TORNEOS_HH

#include "Torneo.hh"
#include "Cjt_jugadores.hh"   
#include "Cjt_categorias.hh"

/** @class Cjt_torneos
    @brief Representa un conjunto de torneos.
*/
class Cjt_torneos {

private:
   /** @brief Representa un conjunto de torneos o circuito.
    */
   map<string, Torneo> circuito;  

public:
   //Constructoras

    /** @brief Creadora por defecto.
        
        Se ejecuta automáticamente al declarar un conjunto de torneos.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de torneos vacío.
    */
   Cjt_torneos();

   //Consultoras

   /** @brief Consultora de la existencia de un torneo.

      \pre Identificador sintácticamente correcto.
      \post El resultado es si existe o no el torneo con ese identificador.
    */
   bool existe_torneo(const string& identificador); 

   /** @brief Consultora del número de torneos.

      \pre <em>cierto</em>
      \post El resultado es el número de torneos del conjunto de torneos.
    */
   int numero_torneos();
   
   //Modificadoras

   /** @brief Reestablece los puntos de un jugador, dado de baja, en la edición anterior de un torneo que se vuelve a disputar. 
      \pre <em>cierto</em>
      \post Quedan reestablecidos a 0 los puntos del jugador con identificador <em>identificador_j</em>
    */
   void puntos_edicion_anterior(const string& identificador_j);

   /** @brief Añade un torneo.
      \pre El parámetro implícito está inicializado, torneo con un identificador y una categoría >= 1.
      \post El parámetro implícito pasa a contener los torneos originales más el torneo con identificador <em>id</em>.
    */
   void anadir_torneo(const string& id, int cat);

   /** @brief Elimina un torneo.
      \pre  String con un nombre/identificador sintácticamente correcto y un conjunto de jugadores.
      \post El parámetro implícito pasa a contener los torneos originales menos el torneo con el identificador del parámetro. A los jugadores que habían participado en el torneo, se les restan los puntos que habían obtenido y se actualiza el ranking.
    */
   void eliminar_torneo(const string& identificador, Cjt_jugadores& jugadores);

   /** @brief Inicia un torneo.
      \pre  <em>cierto</em>
      \post Queda iniciado el torneo con el identificador del parámetro, se leen las incripciones y se confecciona el cuadro de emparejamientos.
    */
   void iniciar_torneo(const string& identificador, Cjt_jugadores& jugadores); 

   /** @brief Finaliza un torneo.
      \pre  <em>cierto</em>
      \post Queda finalizado el torneo con el identifiacador del parámetro y se leen los puntos obtenidos, se confecciona el cuadro de resultados, se actualizan los puntos para el ranking y se actualizan las estadísticas globales de los jugadores y el ranking. 
    */
   void finalizar_torneo(const string& identificador, Cjt_jugadores& jugadores, Cjt_categorias& categorias);

   //Lectura y Escritura 

   /** @brief Operación de lectura.

      \pre Estan preparados en el canal estándar de entrada un entero T >= 0, que representa el numero de torneos iniciales que se leerán, seguido de T pares de string t y entero c >= 1, que son los datos de los torneos.
      \post El parametro implícito contiene el conjunto de torneos leídos del canal estándar de entrada.
    */
   void leer_torneos();

   /** @brief Operación de escritura.

      \pre El parámetro implícito está inicializado.
      \post Escribe las propiedades y el contenido del parámetro implícito por el canal estándar de salida. 
    */
   void listar_torneos(const Cjt_categorias& cat);

};
#endif
