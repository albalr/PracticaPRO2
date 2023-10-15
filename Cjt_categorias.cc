/**
 * @file Cjt_categorias.cc
 * @brief Implementación del conjunto de categorías
 */

#include "Cjt_categorias.hh"

Cjt_categorias::Cjt_categorias(int categoria_max, int nivel_max) {

    nombres_categorias = vector<string>(categoria_max);
    puntos_nivel = vector<vector<int> >(categoria_max, vector<int>(nivel_max)); 
}

int Cjt_categorias::categoria_maxima() {
    return nombres_categorias.size();
}

string Cjt_categorias::consultar_identificador_cat(int cat) const {
    return nombres_categorias[cat-1];
}

int Cjt_categorias::consultar_puntos_cat_nivel(int categoria, int nivel) const {
    return puntos_nivel[categoria][nivel];
}

void Cjt_categorias::leer_categorias() {
    int categorias_size = nombres_categorias.size();
    int puntos_size = puntos_nivel[0].size();

    for (int i = 0; i < categorias_size; ++i) cin >> nombres_categorias[i];

    for (int i = 0; i < categorias_size; ++i) {
        for (int j = 0; j < puntos_size; ++j) {
            cin >> puntos_nivel[i][j];
        }
    }
}

void Cjt_categorias::listar_categorias() {
    int categorias_size = nombres_categorias.size();
    int puntos_size = puntos_nivel[0].size();

    cout << categorias_size << ' ' << puntos_size << endl;

    for (int i = 0; i < categorias_size; ++i) {
        cout << nombres_categorias[i]; 

        for (int j = 0; j < puntos_size; ++j) {
            cout << ' ' << puntos_nivel[i][j];
        }
        cout << endl;
    }
}
                                 
