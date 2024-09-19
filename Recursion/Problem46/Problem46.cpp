// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;
struct tsolucion {
    lli n1, n2;
};

// función que resuelve el problema
tsolucion resolver(int n, int y)
{
    tsolucion sol;
    if (n == 0) { sol.n1 = 1; sol.n2 = 0; }
    else if (n == 1) { sol.n1 = 2*y; sol.n2 = 1; }
    else {
        sol = resolver(n - 1,y);
        lli aux = sol.n1 * 2 * y;
        lli a1 = 2 * (n - 1) * sol.n2;
        sol.n2 = sol.n1;
        sol.n1 = aux - a1;
        
        
    };
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, y;
    std::cin >> n;
    if (n == -1)
        return false;
    std::cin >> y;
    // escribir sol
    tsolucion sol = resolver(n, y);
    std::cout << sol.n1 << std::endl;


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
