//*****************
// IMPORTANTE
//
// Dragos Ionut Camarasan
// A08
//
//***************************************************
#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

struct tParcial {
    bool esParcial;
    int min;
    int max;
};

// Aqui la funcion recursiva que resuelve el problema
tParcial resolver(int ini, int fin, std::vector<int> const& v) { //Mergesort con n log n por lo que 2 llamadas recursivas
    int m = (ini + fin) / 2;
    tParcial sol;
    if (ini + 1 == fin) {//Caso base 2 elemento
        if (v[ini] <= v[fin])
            return{ true,v[ini],v[fin] };
        else
            return{ false };
    }

    tParcial izq = resolver(ini, m, v);
    tParcial der = resolver(m + 1, fin, v);

    if (!izq.esParcial || !der.esParcial)
        sol.esParcial = false;
    else {
        if (izq.min > der.min || der.max < izq.max)
            sol.esParcial = false;
        else
            sol.esParcial = true;
    }

    sol.min = std::min(izq.min, der.min);
    sol.max = std::max(izq.max, der.max);
    return sol;





}

// Tratar cada caso
bool resuelveCaso() {
    // Lectura de los datos
    int aux;
    std::cin >> aux;
    if (aux == 0) return false;
    std::vector<int> v;

    while (aux != 0) {
        v.push_back(aux);
        std::cin >> aux;
    }

    // resolver
    if (v.size() == 1)
        std::cout << "SI" << '\n';
    else {
        auto sol = resolver(0, v.size() - 1, v);
        // Escribir los resultados
        if (sol.esParcial) std::cout << "SI" << '\n';
        else std::cout << "NO\n";
    }
    return true;

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada.

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
