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

struct tCauc {
    bool esCauc;
    int suma;
};

// Aqui la funcion recursiva que resuelve el problema
tCauc resolver(int ini, int fin, std::vector<int> const& v) { //Mergesort con n log n por lo que 2 llamadas recursivas
    int m = (ini + fin) / 2;
    tCauc sol;
    if (ini + 1 == fin) {//Caso base 2 elemento

        sol.esCauc = true;
        if (v[ini] % 2 == 0 && v[fin] % 2 == 0)
            sol.suma = 2;
        else if (v[ini] % 2 == 0 || v[fin] % 2 == 0)
            sol.suma = 1;
        else
            sol.suma = 0;

        return sol;

    }

    tCauc izq = resolver(ini, m, v);
    tCauc der = resolver(m + 1, fin, v);

    if (!der.esCauc || !izq.esCauc)
        sol.esCauc = false;
    else
        sol.esCauc = std::abs(izq.suma - der.suma) <= 2;


    sol.suma = izq.suma + der.suma;
    return sol;





}

// Tratar cada caso
bool resuelveCaso() {
    // Lectura de los datos
    int num;
    std::cin >> num;
    if (num == 0) return false;
    std::vector<int> v(num);
    for (int i = 0; i < num; ++i) {
        std::cin >> v[i];
    }

    // resolver
    if (num == 1)
        std::cout << "SI" << '\n';
    else{
        auto sol = resolver(0, num - 1, v);
        // Escribir los resultados
        if (sol.esCauc) std::cout << "SI" << '\n';
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
