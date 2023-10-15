/**
 * @file Torneo.cc
 * @brief Implementación de la clase Torneo
 */
#include "Torneo.hh"

Torneo::Torneo(int cat) {
    categoria = cat;
}

int Torneo::consultar_categoria() const {
    return categoria;
}

void Torneo::restar_puntos(Cjt_jugadores& jugadores) {
    int size_t_anterior = torneo_anterior.size();

    if (size_t_anterior != 0) {
        
        for (int i = 0; i < size_t_anterior; ++i) {
            if (jugadores.existe_jugador(torneo_anterior[i].identificador)) jugadores.actualizar_puntos(torneo_anterior[i].identificador, torneo_anterior[i].puntos_torneo, false);
        }
    }
}

void Torneo::puntos_edicion_anterior_t(const string& identificador_j) {
    int size_t_anterior = torneo_anterior.size();

    for (int i = 0; i < size_t_anterior; i++) {
        if (identificador_j == torneo_anterior[i].identificador) {
            torneo_anterior[i].puntos_torneo = 0;
        }
    }
}

void Torneo::iniciar_torneo_t(Cjt_jugadores& jugadores) {
    int inscritos;
    cin >> inscritos;

    int pos_ranking;

    torneo_actual = vector<jugador_puntos>(inscritos);
    
    for (int i = 0; i < inscritos; ++i) {
        cin >> pos_ranking;
        torneo_actual[i].identificador = jugadores.consultar_nombre_jugador(pos_ranking);
        torneo_actual[i].puntos_torneo = 0;
    }
    generar_bintree_emp(arbol_emparejamiento, 2, 1, inscritos);

    escribir_bintree_emp(arbol_emparejamiento);
    cout << endl;
}

void Torneo::generar_bintree_emp(BinTree<int>& arbol_emparejamiento, int num_nodos, int raiz, int num_jugadores) {

    int valor_nodo = num_nodos + 1 - raiz;;

    if (valor_nodo <= num_jugadores) {
        BinTree<int> ai;
        generar_bintree_emp(ai, num_nodos * 2, raiz, num_jugadores); 
        BinTree<int> ad;
        generar_bintree_emp(ad, num_nodos * 2, valor_nodo, num_jugadores);
        arbol_emparejamiento = BinTree<int>(raiz, ai, ad); 
    }
    else arbol_emparejamiento = BinTree<int>(raiz);
}
                                       
void Torneo::escribir_bintree_emp(const BinTree<int>& a) {

    if (not a.left().empty() and not a.right().empty()) {
        cout << '(';
		escribir_bintree_emp(a.left()); 
		if (a.left().empty() and a.right().empty()) cout << a.value() << '.' << torneo_actual[a.value() - 1].identificador;
        else cout << ' ';
		escribir_bintree_emp(a.right());
        cout << ')';
    }
    else cout << a.value() << '.' << torneo_actual[a.value() - 1].identificador; 
}

void Torneo::finalizar_torneo_t(Cjt_jugadores& jugadores, Cjt_categorias& categorias) {

    leer_bintree_resultados(arbol_resultados, "0");
    
    BinTree<int> aux = arbol_emparejamiento;

    arbol_emparejamiento = arbol_ganadores(arbol_resultados, aux, jugadores);

    calcular_puntos(arbol_emparejamiento, 0, categorias);

    escribir_cuadro_resultados(arbol_emparejamiento, arbol_resultados);
    cout << endl;
    escribir_puntos_torneo(jugadores);

    if (torneo_anterior.size() != 0) restar_puntos(jugadores);

    torneo_anterior = torneo_actual;
    
    jugadores.actualizar_ranking_circuito();
}

void Torneo::leer_bintree_resultados(BinTree<string>& arbol_resultados, string marca) {
    string resultados;
    cin >> resultados; 

    if (resultados != marca) {
        BinTree<string> ai; 
        leer_bintree_resultados(ai, marca);
        BinTree<string> ad; 
        leer_bintree_resultados(ad, marca);
        arbol_resultados = BinTree<string>(resultados, ai, ad);
    }
}

BinTree<int> Torneo::arbol_ganadores(const BinTree<string>& arbol_resultados, const BinTree<int>& copia, Cjt_jugadores& jugadores) {

    if (not arbol_resultados.empty()) {

        BinTree<int> izquierda = arbol_ganadores(arbol_resultados.left(), copia.left(), jugadores);
        BinTree<int> derecha = arbol_ganadores(arbol_resultados.right(), copia.right(), jugadores);

        int ganador = escoger_ganador(arbol_resultados.value(), izquierda.value(), derecha.value());

        string gana = torneo_actual[ganador - 1].identificador;
        string a = torneo_actual[izquierda.value() - 1].identificador;
        string b = torneo_actual[derecha.value() - 1].identificador;;
    
        jugadores.actualizar_estadisticas_globales(gana, a, b, arbol_resultados.value());

        return BinTree<int>(ganador, izquierda, derecha);           
    }
    return BinTree<int>(copia.value());
}

int Torneo::escoger_ganador(string resultado, int a, int b) { 

    int size = resultado.length();

    if (resultado[size-3] - '0' > resultado[size-1] - '0') return a;

    else if (resultado[size-1] - '0' > resultado[size-3] - '0') return b;

    else {
        
        if (a < b) return a;

        else return b;
    }
}

void Torneo::calcular_puntos(const BinTree<int> &arbol_emparejamiento, int nivel, Cjt_categorias& categorias) {

    if (not arbol_emparejamiento.empty()) {

        if (nivel == 0) torneo_actual[arbol_emparejamiento.value() - 1].puntos_torneo = categorias.consultar_puntos_cat_nivel(categoria - 1, nivel);

        calcular_puntos(arbol_emparejamiento.left(), ++nivel, categorias);

        if (not arbol_emparejamiento.left().empty() and not arbol_emparejamiento.right().empty()) {

            if (arbol_emparejamiento.left().value() != arbol_emparejamiento.value()) torneo_actual[arbol_emparejamiento.left().value() - 1].puntos_torneo = categorias.consultar_puntos_cat_nivel(categoria - 1, nivel);
            else if (arbol_emparejamiento.right().value() != arbol_emparejamiento.value()) torneo_actual[arbol_emparejamiento.right().value() - 1].puntos_torneo = categorias.consultar_puntos_cat_nivel(categoria - 1, nivel);
        }

        calcular_puntos(arbol_emparejamiento.right(), nivel, categorias);
    }
}

void Torneo::escribir_cuadro_resultados(const BinTree<int>& emp, const BinTree<string>& res) {

    if (not res.empty()) {

        if (not emp.left().empty() and not emp.right().empty()) {
            
            cout << '(';
            cout << emp.left().value() << "." << torneo_actual[emp.left().value()-1].identificador;
            cout << " vs ";
            cout << emp.right().value() << "." << torneo_actual[emp.right().value()-1].identificador;
            cout << ' ' << res.value();

            escribir_cuadro_resultados(emp.left(), res.left());
            escribir_cuadro_resultados(emp.right(), res.right());;
        }
        cout << ')';
    }
}

void Torneo::escribir_puntos_torneo(Cjt_jugadores& jugadores) {
    int size_t_actual = torneo_actual.size();

    for (int i = 0; i < size_t_actual; ++i) {

        if (torneo_actual[i].puntos_torneo != 0) {

            cout << i+1 << '.' << torneo_actual[i].identificador << ' ' << torneo_actual[i].puntos_torneo << endl;
        }
        jugadores.actualizar_torneos_disputados(torneo_actual[i].identificador);
        jugadores.actualizar_puntos(torneo_actual[i].identificador, torneo_actual[i].puntos_torneo, true);
    }
}



