// DRAGOS IONUT CAMARASAN
// A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
int resolver(std::vector<int> const& v) {
    int sal = v[0]; int vecesReps = 1; int maxVeces = 1;
    for (int i = 1; i < v.size(); ++i)
        if (v[i] == v[i - 1]) {
            vecesReps++;
            if (maxVeces < vecesReps) { 
                maxVeces = vecesReps;
                sal = v[i]; 
            }
        }
        else vecesReps  = 1;
    return sal;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == -1)
        return false;
    std::vector <int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());
    int sol = resolver(v);

    // escribir sol
    std::cout << sol << std::endl;

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
