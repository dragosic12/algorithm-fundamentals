//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
//std::vector <int> resolver(std::vector <int> const& v, int const& valMaximo) {
//    std::vector <int> aux(valMaximo);
//    std::vector <int> sol;
//
//    int vecesRep = 1,  maxVeces = 1, max = -1;
//    for (int i = 0; i < v.size(); i++) {
//        aux[v[i]-1]++;
//        if (max == -1) 
//            max = aux[v[i]-1];
//        
//        if (max < aux[v[i]-1]) 
//            max = aux[v[i]-1];
//        
//    }
//    for (int i = aux.size()-1; i>0; i--) {
//        if (aux[i] == max)
//            sol.push_back(i+1);
//    }
//    
//    return sol;
//}

std::vector<int>resolver(std::vector<int>const& v, int maximoValores) { // Cuenta el numero de apariciones 
    std::vector<int>apariciones(maximoValores);
    for (int n : v)++apariciones[n - 1];
    // Calcula el maximo del vector apariciones 
    int aparicionesMax = apariciones[0];
    for (int n : apariciones)
        aparicionesMax = std::max(aparicionesMax, n);
    //Anadeasol los valores que aparecen aparicionesMax veces 
    std::vector<int>sol;
    for (int i = 0; i < apariciones.size(); ++i)
        if (apariciones[i] == aparicionesMax)
            sol.push_back(i + 1);
    //sesuma1porque los valores 
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numVeces, valMaximo;
    std::cin >> numVeces;
    if (numVeces == -1)
        return false;

    std::cin >> valMaximo;

    std::vector <int> v(numVeces);

    for (int i = 0; i < numVeces; i++)
        std::cin >> v[i];


    auto sol = resolver(v,valMaximo);

    // escribir sol

    std::cout << sol[sol.size() - 1];
    for (int i = sol.size() - 1; i > 0; --i)
        std::cout << ' ' << sol[i - 1];
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
