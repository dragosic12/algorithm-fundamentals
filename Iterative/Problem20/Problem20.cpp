//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n,m;
    long long int total = 0;
    std::cin >> n;

    if (n == -1)
        return false;

    std::vector <int> v(n);

    for (int &i:v) {
        std::cin >> i;
        total += i;
    }


    std::vector<long long int> acc(v.size() + 1);

    acc[0] = total;
    for (int i = 1; i < v.size(); i++) {
        total -= v[i - 1];
        acc[i] = total;
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> n;
        std::cout << acc[n - 1] << '\n';
    }

    std::cout << "---\n";

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
