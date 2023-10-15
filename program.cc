/** @mainpage
 
    En esta práctica, basada en el diseño modular, simularemos la gestión deportiva y el cálculo del ranking de un circuito de torneos de tenis, muy similar al ATP tour y al WTA tour, aunque con algunas simplificaciones.
    El programa ofrece una serie de comandos para hacer más real la experiencia de un circuito de torneos de tenis. 

    Las clases implementadas, con el fin de cumplir la modularidad, son las clases Jugador, Cjt_jugadores, Torneo, Cjt_torneos y Cjt_categorias. 

*/

/** @file main.cc

    @brief Programa principal para el ejercicio <em>Circuito de torneos de tenis</em>.
*/

#include "Cjt_jugadores.hh"
#include "Cjt_torneos.hh"
#include "Cjt_categorias.hh"

int main() {

    //se lee el conjunto de categorías, con sus puntos por niveles
    int categoria_max, nivel_max;
    cin >> categoria_max >> nivel_max;
    
    Cjt_categorias categorias(categoria_max, nivel_max); 
    categorias.leer_categorias(); 

    //se lee el conjunto de torneos
    Cjt_torneos circuito; 
    circuito.leer_torneos(); 

    //se lee el conjunto de jugadores
    Cjt_jugadores jugadores; 
    jugadores.leer_jugadores();

    string comando; 
    cin >> comando; 

    while (comando != "fin") {

        //añadir un nuevo jugador al conjunto de jugadores
        if (comando == "nuevo_jugador" or comando == "nj") {
            string nombre;
            cin >> nombre;
            
            if (comando == "nuevo_jugador") cout << "#nuevo_jugador " << nombre << endl;
            else cout << "#nj " << nombre << endl;

            if (jugadores.existe_jugador(nombre)) cout << "error: ya existe un jugador con ese nombre" << endl; 
            else {
                jugadores.anadir_jugador(nombre);
                cout << jugadores.numero_jugadores() << endl;
            }
        }

        //añadir un nuevo torneo al conjunto de torneos o circuito
        else if (comando == "nuevo_torneo" or comando == "nt") {
            string nombre; 
            cin >> nombre;
            int categoria; 
            cin >> categoria;

            if (comando == "nuevo_torneo") cout << "#nuevo_torneo " << nombre << ' ' << categoria << endl;
            else cout << "#nt " << nombre << ' ' << categoria << endl;

            Torneo nt(categoria); 
        
            if (categoria < 1 or categoria > categorias.categoria_maxima()) cout << "error: la categoria no existe" << endl;
            else if (circuito.existe_torneo(nombre)) cout << "error: ya existe un torneo con ese nombre" << endl;
            else {
                circuito.anadir_torneo(nombre, categoria);
                cout << circuito.numero_torneos() << endl;
            }
        }

        //eliminar un jugador del conjunto de jugadores
        else if (comando == "baja_jugador" or comando == "bj") {
            string identificador_jugador;
            cin >> identificador_jugador;
            
            if (comando == "baja_jugador") cout << "#baja_jugador " << identificador_jugador << endl;
            else cout << "#bj " << identificador_jugador << endl;

            if (not jugadores.existe_jugador(identificador_jugador)) cout << "error: el jugador no existe" << endl;
            else {
                jugadores.eliminar_jugador(identificador_jugador); 
                circuito.puntos_edicion_anterior(identificador_jugador);
                cout << jugadores.numero_jugadores() << endl;
            }
        }

        //eliminar un torneo del conjunto de torneos o circuito
        else if (comando == "baja_torneo" or comando == "bt") {
            string identificador_torneo;
            cin >> identificador_torneo;

            if (comando == "baja_torneo") cout << "#baja_torneo " << identificador_torneo << endl;
            else cout << "#bt " << identificador_torneo << endl;

            if (not circuito.existe_torneo(identificador_torneo)) cout << "error: el torneo no existe" << endl;
            else {
                circuito.eliminar_torneo(identificador_torneo, jugadores); 
                cout << circuito.numero_torneos() << endl;
            }
        }

        //se inicia un torneo
        else if (comando == "iniciar_torneo" or comando == "it") {
            string identificador_torneo;
            cin >> identificador_torneo;

            if (comando == "iniciar_torneo") cout << "#iniciar_torneo " << identificador_torneo << endl;
            else cout << "#it " << identificador_torneo << endl;

            circuito.iniciar_torneo(identificador_torneo, jugadores);
        }

        //se finaliza un torneo
        else if (comando == "finalizar_torneo" or comando == "ft") {
            string identificador_torneo;
            cin >> identificador_torneo;
            if (comando == "finalizar_torneo") cout << "#finalizar_torneo " << identificador_torneo << endl;
            else cout << "#ft " << identificador_torneo << endl;
            circuito.finalizar_torneo(identificador_torneo, jugadores, categorias);
        }

        //se imprime el ranking, con los nombres de los jugadores y los puntos que tienen
        else if (comando == "listar_ranking" or comando == "lr") {
            if (comando == "listar_ranking") cout << "#listar_ranking" << endl;
            else cout << "#lr" << endl;
            jugadores.listar_ranking();
        }

        //se imprimen los jugadores del conjunto de jugadores, ordenados según el identificador, con todos sus atributos
        else if (comando == "listar_jugadores" or comando == "lj") {
            if (comando == "listar_jugadores") cout << "#listar_jugadores" << endl;
            else cout << "#lj" << endl;
            jugadores.listar_jugadores();
        }

        //se imprime la información de un jugador concreto
        else if (comando == "consultar_jugador" or comando == "cj") {
            string identificador_jugador;
            cin >> identificador_jugador;

            if (comando == "consultar_jugador") cout << "#consultar_jugador " << identificador_jugador << endl;
            else cout << "#cj " << identificador_jugador << endl;

            if (not jugadores.existe_jugador(identificador_jugador)) cout << "error: el jugador no existe" << endl;
            else {
                Jugador p = jugadores.consultar_jugador(identificador_jugador);
                cout << identificador_jugador << ' ';
                p.listar_jugador();
            }
        }

        //se imprimen los torneos del conjunto de torneos o circuito
        else if (comando == "listar_torneos" or comando == "lt") {
            if (comando == "listar_torneos") cout << "#listar_torneos" << endl;
            else cout << "#lt" << endl;
            circuito.listar_torneos(categorias);
        }

        //se imprimen el nombre y la tabla de puntos por nivel de las diferentes categorías
        else if (comando == "listar_categorias" or comando == "lc") {
            if (comando == "listar_categorias") cout << "#listar_categorias" << endl;
            else cout << "#lc" << endl;
            categorias.listar_categorias();
        }

        cin >> comando;
    }  
}