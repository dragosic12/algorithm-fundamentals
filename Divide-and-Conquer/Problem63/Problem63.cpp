//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
struct tMayoritario {
    int numMayor;
    int countMayor;
};

tMayoritario resolver(int ini, int fin, const std::vector<int>& v) {
    tMayoritario sol;

    if (ini + 1 == fin) {
        sol.numMayor = v[ini];
        sol.countMayor = 1;
        return sol;
    }

    int mitad = (ini + fin) / 2;
    tMayoritario izq = resolver(ini, mitad, v);
    tMayoritario der = resolver(mitad, fin, v);

    if (izq.numMayor == der.numMayor) {
        sol.numMayor = izq.numMayor;
        sol.countMayor = izq.countMayor + der.countMayor;
    }
    else {
        int countIzq = 0, countDer = 0;
        for (int i = ini; i < fin; ++i) {
            if (v[i] == izq.numMayor) {
                countIzq++;
            }
            else if (v[i] == der.numMayor) {
                countDer++;
            }
        }

        sol.numMayor = (countIzq > countDer) ? izq.numMayor : der.numMayor;
        sol.countMayor = std::max(countIzq, countDer);
    }

    return sol;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int aux, i = 0;
    std::cin >> aux;
    std::vector<int> v;

    while (aux != 0) {
        v.push_back(aux);
        std::cin >> aux;
    }
    if (v.empty()) {
        std::cout << "NO\n";
    }
    else {
        auto sol = resolver(0, v.size(), v);
        if (sol.countMayor > v.size() / 2) {
            std::cout << sol.numMayor << '\n';
        }
        else {
            std::cout << "NO\n";
        }
    }

    // escribir sol


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