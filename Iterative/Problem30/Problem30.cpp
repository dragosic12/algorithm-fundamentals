//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>




int resolver(const std::vector<int>& v) {
    int i = 0, j = 1, sol = 1, cont = 1, st = 0;

    while (j < v.size()) {
        if (v[i] < v[j]) cont++;
        else if (cont > 1) cont--;

        if (cont == 3) {
            cont--;
            st = i;
        }
        else if ((j + 1) - st > sol)
            sol = j + 1 - st;

        i++;
        j++;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector <int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];


    
    // escribir sol

    if (n == 0)
        std::cout << "0\n";
    else
        std::cout << resolver(v) << '\n';

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