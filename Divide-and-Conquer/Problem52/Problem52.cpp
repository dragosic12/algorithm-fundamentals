//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int ini, int fin, int x, std::vector<int> const& v) {
    int m = (ini + fin) / 2;
    if (ini + 1 >= fin) {
        if (v[ini] == x + ini)
            return v[ini];
        else
            return 0;
    }
    if (x + m == v[m])
        return v[m];
    if (v[m] > x+m) //Si es mayor vamos para la izquierda
        return resolver(ini, m, x, v);
    else
        return resolver(m, fin, x, v);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);

    for (int& i : v)
        std::cin >> i;

    auto sol = resolver(0,n,m,v);
    // escribir sol
    if (sol != 0)
        std::cout << sol << '\n';
    else
        std::cout << "NO" << '\n';
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