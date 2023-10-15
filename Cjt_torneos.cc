/**
 * @file Cjt_torneos.cc
 * @brief Implementación del Conjunto de Torneos
 */

#include "Cjt_torneos.hh"

Cjt_torneos::Cjt_torneos() {
}

bool Cjt_torneos::existe_torneo(const string& identificador) {

    map<string, Torneo>::const_iterator it = circuito.find(identificador);
    if (it == circuito.end()) return false;
    return true;
}

int Cjt_torneos::numero_torneos() {
    return circuito.size();
}

void Cjt_torneos::puntos_edicion_anterior(const string& identificador_j) {

    for (map<string, Torneo>::iterator it = circuito.begin(); it != circuito.end(); ++it) {

        (*it).second.puntos_edicion_anterior_t(identificador_j);
    }
}

void Cjt_torneos::anadir_torneo(const string& id, int cat) {
    
    Torneo t(cat);

    circuito.insert(make_pair(id, t));
}

void Cjt_torneos::eliminar_torneo(const string& identificador, Cjt_jugadores& jugadores) {

    map<string, Torneo>::iterator it = circuito.find(identificador);
    
    (*it).second.restar_puntos(jugadores);

    jugadores.actualizar_ranking_circuito();

    it = circuito.erase(it);
}

void Cjt_torneos::iniciar_torneo(const string& identificador, Cjt_jugadores& jugadores) {
    
    map<string, Torneo>::iterator it = circuito.find(identificador);
    (*it).second.iniciar_torneo_t(jugadores);
}

void Cjt_torneos::finalizar_torneo(const string& identificador, Cjt_jugadores& jugadores, Cjt_categorias& categorias) {
    
    map<string, Torneo>::iterator it = circuito.find(identificador);
    (*it).second.finalizar_torneo_t(jugadores, categorias);
}

void Cjt_torneos::leer_torneos() {
    int ntorneos;
    cin >> ntorneos;

    string identificador; 
    int categoria;

    for (int i = 0; i < ntorneos; ++i) {
        cin >> identificador >> categoria;
        Torneo t(categoria);
        circuito.insert(make_pair(identificador, t));
    }
}

void Cjt_torneos::listar_torneos(const Cjt_categorias& cat) {

    cout << circuito.size() << endl;
    
    for (map<string, Torneo>::const_iterator it = circuito.begin(); it != circuito.end(); ++it) {
        cout << (*it).first << " ";
        int i = (*it).second.consultar_categoria();
        cout << cat.consultar_identificador_cat(i) << endl;
    }
}