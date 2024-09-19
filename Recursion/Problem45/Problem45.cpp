//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

// función que resuelve el problema
int resolver(int n,int m, int val,std::vector<int> const& v, tMatriz & matriz) {
    if (m == v.size()) {
        if (v[m-1] == val)
            return val;
        else
            return 0;
    }
    else {
        if (v[n] + v[m] == val) 
            matriz[n][m] = val;
        matriz[n][m] = matriz[n][m] + resolver(n + 1, m + 1, val, v, matriz);
        return resolver(n + 1, m + 1, val, v, matriz);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m, val;
    std::cin >> n >> val;
    if (!std::cin)
        return false;
    std::vector<int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    tMatriz matriz(n , std::vector<int>(n, 0));

    std::cout << resolver(0,1,val,v,matriz) << '\n';

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