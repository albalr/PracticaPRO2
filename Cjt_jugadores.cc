/**
 * @file Cjt_jugadores.cc
 * @brief Implementación de la clase Conjunto de Jugadores
 */
#include "Cjt_jugadores.hh"

Cjt_jugadores::Cjt_jugadores() {
}

Jugador Cjt_jugadores::consultar_jugador(const string& identificador) {
    return jugadores[identificador];
}

string Cjt_jugadores::consultar_nombre_jugador(int pos_ranking) {
    string nombre = ranking_jugadores[pos_ranking-1].identificador;
    return nombre;
}

bool Cjt_jugadores::existe_jugador(const string& identificador) {

    map<string, Jugador>::const_iterator it = jugadores.find(identificador);
    if (it == jugadores.end()) return false;
    else return true;
}

int Cjt_jugadores::numero_jugadores() {
    return jugadores.size();
}

void Cjt_jugadores::anadir_jugador(const string& id) {
    Jugador np;
    ranking nr;

    if (ranking_jugadores.size() != 0) np.modificar_posicion_ranking(ranking_jugadores.size()+1);
    else np.modificar_posicion_ranking(1);

    jugadores.insert(make_pair(id, np));

    nr.identificador = id;
    nr.posicion_anterior = ranking_jugadores.size()+1; 
    nr.puntos = 0;

    ranking_jugadores.push_back(nr);

}

void Cjt_jugadores::eliminar_jugador(const string& identificador) {

    map<string, Jugador>::iterator it = jugadores.find(identificador);

    int njugadores = ranking_jugadores.size();
    int i = (*it).second.consultar_posicion_ranking() - 1;;

    for (int j = i; j < njugadores - 1; ++j) {
        ranking_jugadores[j] = ranking_jugadores[j+1];

        map<string, Jugador>::iterator it = jugadores.find(ranking_jugadores[j].identificador);
        (*it).second.modificar_posicion_ranking(j+1);
        ranking_jugadores[j].posicion_anterior = j+1; 
    }

    ranking_jugadores.pop_back();
    it = jugadores.erase(it);
}

bool Cjt_jugadores::comp(const ranking& a, const ranking& b) {

    if (a.puntos != b.puntos) return a.puntos > b.puntos;
    return a.posicion_anterior < b.posicion_anterior;
}

void Cjt_jugadores::actualizar_ranking_circuito() {

    sort(ranking_jugadores.begin(), ranking_jugadores.end(), comp);

    int size_ranking = ranking_jugadores.size();
    
    for (int i = 0; i < size_ranking; ++i) {
        
        map<string, Jugador>::iterator it = jugadores.find(ranking_jugadores[i].identificador);
        (*it).second.modificar_posicion_ranking(i+1);
        ranking_jugadores[i].posicion_anterior = i+1;
    }
}

void Cjt_jugadores::actualizar_puntos(const string identificador, int puntos_torneo, bool sumar) {

    map<string, Jugador>::iterator it = jugadores.find(identificador);
    int posicion;

    if (sumar) {

        (*it).second.actualizar_puntos_jugador(puntos_torneo, true);
        posicion = (*it).second.consultar_posicion_ranking();

        ranking_jugadores[posicion - 1].puntos += puntos_torneo;

    }
    else {

        (*it).second.actualizar_puntos_jugador(puntos_torneo, false);
        posicion = (*it).second.consultar_posicion_ranking();

        ranking_jugadores[posicion - 1].puntos -= puntos_torneo;
    }
}
 
void Cjt_jugadores::actualizar_estadisticas_globales(string ganador, string a, string b, string resultado) {


    map<string, Jugador>::iterator it_a = jugadores.find(a);
    map<string, Jugador>::iterator it_b = jugadores.find(b);

    pair<int, int> partidos_a;
    pair<int, int> partidos_b;

    //partidos ganados a
    if (ganador == a) {
        ++partidos_a.first;
        ++partidos_b.second;
    }

    //partidos ganados b
    else {
        ++partidos_a.second;
        ++partidos_b.first;
    }

    (*it_a).second.modificar_partidos_ganados(partidos_a.first);
    (*it_b).second.modificar_partidos_ganados(partidos_b.first);
    (*it_a).second.modificar_partidos_perdidos(partidos_a.second);
    (*it_b).second.modificar_partidos_perdidos(partidos_b.second);

    pair<int, int> sets_a;
    pair<int, int> sets_b;

    pair<int, int> juegos_a;
    pair<int, int> juegos_b;

    int size_resultado = resultado.length();
    int i = 0; //a
    int j = 2; //b

    while (size_resultado > 3 and j < size_resultado and i < size_resultado) {

        //sets ganados
        if (resultado[i] - '0' > resultado[j] - '0') ++sets_a.first;
        else ++sets_b.first;

        //juegos ganados
        juegos_a.first += resultado[i] - '0';
        juegos_b.first += resultado[j] - '0';

        i += 4;
        j += 4;
    }

    //sets perdidos
    sets_a.second += sets_b.first;
    sets_b.second += sets_a.first;

    //juegos perdidos
    juegos_a.second += juegos_b.first;
    juegos_b.second += juegos_a.first;

    (*it_a).second.modificar_sets_ganados(sets_a.first);
    (*it_b).second.modificar_sets_ganados(sets_b.first);

    (*it_a).second.modificar_sets_perdidos(sets_a.second);
    (*it_b).second.modificar_sets_perdidos(sets_b.second);

    (*it_a).second.modificar_juegos_perdidos(juegos_a.second);
    (*it_b).second.modificar_juegos_perdidos(juegos_b.second);

    (*it_a).second.modificar_juegos_ganados(juegos_a.first);
    (*it_b).second.modificar_juegos_ganados(juegos_b.first);
}

void Cjt_jugadores::actualizar_torneos_disputados(const string& identificador) {

    map<string, Jugador>::iterator it = jugadores.find(identificador);
    (*it).second.modificar_torneos_disputados();
}

void Cjt_jugadores::leer_jugadores() {
    int num_jugadores;
    cin >> num_jugadores;

    ranking_jugadores = vector<ranking>(num_jugadores);

    for (int i = 0; i < num_jugadores; ++i) {
        cin >> ranking_jugadores[i].identificador;
        ranking_jugadores[i].posicion_anterior = i+1;
        Jugador p;
        p.modificar_posicion_ranking(i+1);
        jugadores.insert(make_pair(ranking_jugadores[i].identificador, p));
    }
}

void Cjt_jugadores::listar_jugadores() {
    
    cout << jugadores.size() << endl;

    for (map<string, Jugador>::iterator it = jugadores.begin(); it != jugadores.end(); ++it) {
        cout << (*it).first << " "; 
        (*it).second.listar_jugador();
    }
}

void Cjt_jugadores::listar_ranking() {
    int jugadores_size = jugadores.size();

    for (int i = 1; i <= jugadores_size; ++i) {
        cout << i << ' ' << ranking_jugadores[i-1].identificador << ' ' << ranking_jugadores[i-1].puntos << endl;
    }
}


