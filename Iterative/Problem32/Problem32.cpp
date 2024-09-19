//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// función que resuelve el problema
std::pair<int,int> resolver(std::vector<std::pair<char, int>> & v) {
    std::pair<int, int> sol;
    sol.first = 0;
    sol.second = v.size() - 1;
    int i = 0; 
    while (i <= sol.second) {
        if (v[i].first == 'v') i++;
        else if (v[i].first == 'a') {
            std::swap(v[sol.first], v[i]);
            sol.first++;
            i++;
        }
        else {
            std::swap(v[sol.second], v[i]);
            sol.second--;
        }
    } 


    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (!std::cin)
        return false;

    std::vector<std::pair<char, int>> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i].first >> v[i].second;

    
    auto sol = resolver(v);

    std::sort(v.begin(), v.begin() + sol.first);
    std::sort(v.begin() + sol.first, v.begin() + 1 + sol.second);
    std::sort(v.begin() + 1 + sol.second, v.end() );
    // escribir sol
    std::cout << "Azules:";
    for (int i = 0; i < sol.first; i++) 
        std::cout << " " << v[i].second;
    std::cout << std::endl;

    std::cout << "Verdes:";
    for (int i = sol.first; i < sol.second + 1; i++) 
        std::cout << " " << v[i].second;
    std::cout << std::endl;

    std::cout << "Rojas:";
    for (int i = sol.second + 1; i < v.size(); i++) 
        std::cout << " " << v[i].second;
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