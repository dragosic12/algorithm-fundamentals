
// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    int n;
    std::cin >> n;
    // Declaración de variables
    // Codigo del alumno
    int vecesReps = 1, aux;
    std::cin >> aux;
    if (aux == 0) 
        std::cout << n << " " << 1 << std::endl;
    else {
        while (n != 0) {
            // Aqui codigo del alumno
            if (aux < n) {
                aux = n;
                vecesReps = 1;
            }
            else if (aux == n)
                vecesReps++;

            std::cin >> n;
        }
        std::cout << aux << " " << vecesReps << std::endl;
    }
        
    
    // Escribir el resultado
    // Codigo del alumno

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
    for (int i = 0; i < numCasos; ++i) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}