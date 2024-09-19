//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// // función que resuelve el problema
std::pair <int,std::vector<int>> resolver(const std::vector<int> & v, const int & error) {
    std::vector<int> aux;
    std::pair <int, std::vector<int>> salida;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != error) {
            salida.first++;
            salida.second.push_back(v[i]);
        }
    }
    return salida;
}

// // Resuelve un caso de prueba, leyendo de la entrada la
// // configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numDatos, erroneo;
    std::cin >> numDatos >> erroneo;
    std::vector<int> v(numDatos);

    for (int i = 0; i < numDatos; i++)
        std::cin >> v[i];

    auto sol = resolver(v,erroneo);

    // escribir sol
    std::cout << sol.first << std::endl;

    for (int i = 0; i < sol.second.size(); i++) 
        std::cout << sol.second[i] << " ";
    
    std::cout << std::endl;

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