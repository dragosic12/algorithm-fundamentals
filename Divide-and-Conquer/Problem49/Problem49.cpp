//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int izq(int ini, int fin, std::vector<int> const& v) {
    if (ini + 1 >= fin) return ini;
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] > v[mitad + 1]) return izq(mitad + 1, fin, v);
        else return izq(ini, mitad + 1, v);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    std::cin >> n;
    if (!std::cin)
        return false;

    std::vector<int> v(n);

    for (int &i : v)
        std::cin >> i;

    std::cout << v[izq(0,n,v)] << '\n';

    // escribir sol


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