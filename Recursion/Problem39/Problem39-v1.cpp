﻿//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int resolver(int n, int m, int v, int e) {
    if (n < 10 && m< 10) return (v + (n % 10 + m % 10) % 10 * e);
    else {
        
        return resolver(n / 10, m / 10, (v+ (n%10 + m%10)%10*e), e * 10);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;


    int sol = resolver(n,m, 0, 1);
    // escribir sol
    std::cout << sol << " " << sol << std::endl;
         
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}