//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// // función que resuelve el problema
long long int resolver(const std::vector <int> & v) {
    long long impares = 0;
    long long sol = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0 && impares != 0 ) 
            sol = sol + impares;
        else if (v[i] % 2 != 0)
            impares++;
        
    }

    // Calculamos el número total de parejas posibles
    

    return sol;
}

// // Resuelve un caso de prueba, leyendo de la entrada la
// // configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) 
        std::cin >> v[i];
     
    long long int sol = resolver(v);
    // escribir sol

    std::cout << sol << std::endl;;

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