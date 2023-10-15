/**
 * @file Jugador.cc
 * @brief Implementación de la clase Jugador
 */
#include "Jugador.hh"

Jugador::Jugador() {
    puntos = 0;
    torneos_disputados = 0; 

    partidos.first = 0; 
    partidos.second = 0;
    sets.first = 0;
    sets.second = 0; 
    juegos.first = 0; 
    juegos.second = 0;
}

int Jugador::consultar_posicion_ranking() {
    return pos_ranking;
}

void Jugador::actualizar_puntos_jugador(int p, bool sumar) {
    if (sumar) puntos += p;
    else puntos -= p;
}

void Jugador::modificar_posicion_ranking(int pos) {
    pos_ranking = pos;
}   

void Jugador::modificar_torneos_disputados() {
    ++torneos_disputados;
}

void Jugador::modificar_partidos_ganados(int partidos_ganados) {
    partidos.first += partidos_ganados;
}

void Jugador::modificar_partidos_perdidos(int partidos_perdidos) {
    partidos.second += partidos_perdidos;
}

void Jugador::modificar_sets_ganados(int sets_ganados) {
    sets.first += sets_ganados;
}

void Jugador::modificar_sets_perdidos(int sets_perdidos) {
    sets.second += sets_perdidos;
}

void Jugador::modificar_juegos_ganados(int juegos_ganados) {
    juegos.first += juegos_ganados;
}

void Jugador::modificar_juegos_perdidos(int juegos_perdidos) {
    juegos.second += juegos_perdidos;
}

void Jugador::listar_jugador() { 
    cout << "Rk:" << pos_ranking << ' '; 
    cout << "Ps:" << puntos << ' ';
    cout << "Ts:" << torneos_disputados << ' ';
    cout << "WM:" << partidos.first << ' ';
    cout << "LM:" << partidos.second << ' ';
    cout << "WS:" << sets.first << ' ';
    cout << "LS:" << sets.second << ' ';
    cout << "WG:" << juegos.first << ' ';
    cout << "LG:" << juegos.second << endl;
}

