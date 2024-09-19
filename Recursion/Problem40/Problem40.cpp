//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// función que resuelve el problema
// Tiene que ser no final ya que en este caso el primer elemento siempre va a ser 1
std::string resolver( int n,  int e) {
    if (n == 1 || n == 0) 
        return std::to_string(n);
    else 
        return resolver(n / 2,e*10) + std::to_string(n%2);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
     int n;
    std::cin >> n;

    auto sol = resolver(n,1);
    // escribir sol
    std::cout << sol << std::endl;

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