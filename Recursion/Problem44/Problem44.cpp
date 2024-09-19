//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// // función que resuelve el problema
int resolver(int n, int m, std::vector<std::vector<int>> & v) {

    if (m == 0 || n == m) {
        return v[n][m] = 1;
    }else if ()

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;
    if (!std::cin)
        return false;

    //Para inicializar la matriz con el numero de filas y de columnas. El -1 indica que todos los valores son -1
    std::vector<std::vector<int>> v (n+1, std::vector<int>(m+1, -1)); 

    // escribir sol
    std::cout << resolver(n, m, v)  << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    // while (resuelveCaso())
        // ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}