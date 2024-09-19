//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int n, int m) {

    //Caso base
    if (m == 0) return n;
    if (m > 0) return resolver(m, n%m); //El porcenaje devuelve el resto y como la formula del 
    //teorema de euclides dice que mcd(a,b) == mcd (b,a%b) cuando b es mayor que 0 pues se utiliza %

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m, s;
    std::cin >> n >> m;
    if (n == 0 && m == 0)
        return false;

    int sol = resolver(n,m);

    // escribir sol
    std::cout << sol << std::endl;


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
