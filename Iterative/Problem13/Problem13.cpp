// DRAGOS IONUT CAMARASAN   
// A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// función que resuelve el problema
std::vector<int> resolver(std::vector<int> & v) {
    
    std::sort(v.begin(), v.end());
    int aux = v[0], m = 0, ini = 1;
    
    for (int i = 1; i < v.size(); i++) {
        if (aux != v[i]) {
            v[ini] = v[i];
            aux = v[i];
            ini++;
        }

    }
    v.resize(ini);
    
    return v;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    
    int n;
    std::cin >> n;
    
    if (!std::cin)
        return false;


    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    

    auto sol = resolver(v);

    // escribir sol
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

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