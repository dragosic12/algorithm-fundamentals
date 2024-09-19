//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



struct tPartidos {
    std::string ganador;
    int ronda;
    int partidosJugados;
};

// Función auxiliar para determinar si un partido se jugó
bool seJugoPartido(const std::string& jugador1, const std::string& jugador2) {
    return jugador1 != "NP" && jugador2 != "NP";
}

std::string algunJugador(const std::string& jugador1, const std::string& jugador2) {
    if (jugador1 != "NP")
        return jugador1;
    if (jugador2 != "NP")
        return jugador2;
    return "NP";
}

// Función que cuenta el número de partidos jugados hasta la ronda indicada
tPartidos contarPartidos(int ini, int fin, int ronda, std::vector<std::string> const & v) {
    tPartidos sol{"",0,0};
    int m = (ini + fin) / 2;
    
    if (ini + 2 == fin) {//Caso base 2 jugadores
        if (seJugoPartido(v[ini], v[ini+1])) 
            sol.partidosJugados++;
        
        
        sol.ronda++;
        sol.ganador = algunJugador(v[ini],v[ini+1]);
        return sol;
    }

    auto izq = contarPartidos(ini, m, ronda, v);
    auto der = contarPartidos(m, fin, ronda, v);

    if (sol.ronda <= ronda)
        sol.partidosJugados = izq.partidosJugados + der.partidosJugados;
    sol.ronda = izq.ronda + 1;
    if (seJugoPartido(izq.ganador, der.ganador)) {
        if (sol.ronda <= ronda)
            sol.partidosJugados = izq.partidosJugados + der.partidosJugados + 1;
    }
    
    sol.ganador = algunJugador(izq.ganador, der.ganador);
    

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la configuración
// y escribiendo la respuesta
bool resuelveCaso() {
    // Leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;

    if (!std::cin)
        return false;

    std::vector<std::string> v(n);
    for (std::string& i : v) std::cin >> i;

    // Calcular el número de partidos jugados hasta la ronda indicada
    tPartidos sol = contarPartidos(0, n , m, v);

    // Escribir la solución
    std::cout << sol.partidosJugados<< '\n';

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}