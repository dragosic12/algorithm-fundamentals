//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int n, int e, int elev) {
    if (n < 10) {
        if (n % 2 == 1) {
            return e+(n-1)*elev;
        }
        else {
            return  e+(n+1)*elev;
        }
    
    } //Caso base
    else {
        if ((n % 10) % 2 == 1) {//impar
            
            
            return resolver(n / 10, e + (n % 10 - 1) * elev, elev*10);
        }
        else {
            return resolver(n / 10, e + (n % 10 + 1) * elev,elev*10);
        }
    
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    std::cin >> n;


    int sol = resolver(n,0, 1);
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