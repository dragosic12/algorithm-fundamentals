//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// función que resuelve el problema
std::pair<std::vector<std::string>, std::vector<std::string>> resolver(std::vector<std::pair<std::string, int>> const& v, int const& altura) {
    std::pair<std::vector<std::string>, std::vector<std::string>> a;
    //first bajos
    //second altos
    for (int i = v.size()-1; i >= 0; i--) {
        if (v[i].second > altura) 
            a.second.push_back(v[i].first);
        else 
            a.first.push_back(v[i].first);
        
    }
    std::sort(a.first.begin(), a.first.end());
    std::sort(a.second.begin(), a.second.end());
    return a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, altura;
    std::cin >> n;
    if (!std::cin)
        return false;

    std::cin >> altura;
    std::vector<std::pair<std::string,int>> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i].first >> v[i].second;

    auto sol = resolver(v,altura);

    // escribir sol
    std::cout << "Bajos:";
    for (int i = 0; i < sol.first.size(); i++)
        std::cout << " " <<  sol.first[i] ;
    std::cout << std::endl << "Altos:";
    for (int i = 0; i < sol.second.size(); i++)
        std::cout << " " << sol.second[i];
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