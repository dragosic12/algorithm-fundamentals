
//*****************
// IMPORTANTE
//
// DRAGOS IONUT CAMARASAN
// A08
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

//*******************************
// Aqui explicacion del algoritmo de vuelta atras. Como es el vector solucion y como se obtiene
//
//
//*******************************

template <class T >
using tMatriz = std::vector < std::vector <T> >;

// Para una cancion
struct tCancion {
    int duracion;  // Duracion de la cancion
    int satisfaccion;  // Puntuacion dada a la cancion
};

// Lectura de los datos de una cancion
std::istream& operator>> (std::istream& in, tCancion& d) {
    in >> d.duracion >> d.satisfaccion;
    return in;
}

// Para los datos de entrada
struct tDatos {
    int numCanciones;  // Numero de canciones
    int tiempoViajeIda; // Duracion del viaje de ida
    int tiempoViajeVuelta;  // Duracion del viaje de vuelta
    std::vector<tCancion> canciones;  // Duracion y puntuacion de cada cancion
};




// Aqui las funciones implementadas por el alumno

class comparador {
public:
    bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

int estimar(tDatos const& datos, int costeAct, int k) {
    int i = k + 1; int sumaCoste = costeAct; int sumaSuperf = 0;
    while (i < datos.canciones.size() &&
        sumaCoste + datos.canciones[i].duracion <= datos.tiempoViajeIda + datos.tiempoViajeVuelta) {
        sumaCoste += datos.canciones[i].duracion;
        sumaSuperf += datos.canciones[i].satisfaccion;
        ++i;
    }
    // La parte que queda sin completar . Como la division es entera se suma 1 al resultado
    // para asignar una cota superior a la variable entera
    if (i < datos.canciones.size() && sumaCoste < datos.tiempoViajeIda + datos.tiempoViajeVuelta)
        sumaSuperf += datos.canciones[i].satisfaccion *
        (datos.tiempoViajeIda+datos.tiempoViajeVuelta - sumaCoste) / datos.canciones[i].duracion + 1;
    return sumaSuperf;
}

int inicializarSatis(tDatos const& Obj, int costeMax) {
    int i = 0; int sumaSuperficie = 0; int sumaCoste = 0;
    while (i < Obj.canciones.size() &&
        sumaCoste + Obj.canciones[i].duracion <= costeMax) {
        sumaSuperficie += Obj.canciones[i].satisfaccion;
        sumaCoste += Obj.canciones[i].duracion;
        ++i;
    }
    return sumaSuperficie;
}



void vueltaAtras(int k,tDatos const&d, std::vector <int> & sol,
    int durActual, int satisActual, std::vector <int> &solMejor,
    int& satisMejor) {
    //Como solo hay 3 ramas, vamos a distinguir casos, el primero va para ida la cancion
    //el segundo para vuelta y el ultimo para No añadirla
    for (int i = 0; i < 2; ++i) {//IDA O VUELTA
        sol[k] = i;//Ida
        durActual += d.canciones[k].duracion;
        satisActual += d.canciones[k].satisfaccion;
        if (durActual <= d.tiempoViajeIda) {
            if (k == sol.size() - 1) {//La altura
                if (satisActual > satisMejor) {
                    satisMejor = satisActual;
                    solMejor = sol;
                }
            }
            else
                vueltaAtras(k + 1, d, sol, durActual, satisActual, solMejor, satisMejor);
        }
        durActual -= d.canciones[k].duracion;
        satisActual -= d.canciones[k].satisfaccion;
    }
    //NO
    sol[k] = 2;
    if (k == sol.size() - 1) {
        if (satisActual > satisMejor) {
            satisMejor = satisActual;
            solMejor = sol;
        }
    }
    else {
        if (estimar(d,durActual,k) + satisActual > satisMejor)
            vueltaAtras(k + 1, d, sol, durActual, satisActual, solMejor, satisMejor);
    }

}





bool  resuelveCaso() {
    // lectura de datos
    tDatos d;
    std::cin >> d.numCanciones >> d.tiempoViajeIda >> d.tiempoViajeVuelta;
    if (d.numCanciones == 0 && d.tiempoViajeIda == 0 && d.tiempoViajeVuelta == 0) return false;
    d.canciones.resize(d.numCanciones);
    for (int i = 0; i < d.numCanciones; ++i)
        std::cin >> d.canciones[i];

    // Preparar los datos para llamada a VA
    std::vector <int> sol(d.numCanciones);
    std::vector <int> solMejor;
    std::sort(d.canciones.begin(), d.canciones.end(), comparador());//Ordenamos vector de canciones
    int satisMejor = inicializarSatis(d, d.tiempoViajeIda+d.tiempoViajeVuelta);

    // llamada a VA
    vueltaAtras(0, d, sol, 0, 0, solMejor, satisMejor);

    // Escribir resultado
    if (satisMejor == 0)
        std::cout << "Imposible\n";
    else
        std::cout << satisMejor;

    return true;
}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
