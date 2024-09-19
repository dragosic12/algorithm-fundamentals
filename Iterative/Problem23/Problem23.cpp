// DRAGOS IONUT CAMARASAN
// A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
std::pair <int, int> resolver(std::vector <int> const& v, int const& t) {
    std::pair <int, int> sal;
    int longMax = 0, longActual = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > t) {
            
            longActual++;
            if (longMax < longActual) {
                longMax = longActual;
                sal.second = i;
                sal.first = i - longMax + 1;
            }
        }
        else
            longActual = 0;

    }

    return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, t;
    std::cin >> n >> t;
    std::vector<int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    auto sol = resolver(v,t);
    // escribir sol

    std::cout << sol.first << " " << sol.second << std::endl;;
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