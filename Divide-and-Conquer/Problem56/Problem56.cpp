//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using lli = long long int;

// función que resuelve el problema

lli comprobar(std::vector <lli> const& v, lli tramo) {
    lli dias = 1; lli i = 0; lli suma = 0;
    while (i < (lli)v.size()) {
        if (suma + v[i] > tramo) {
            dias++;
            suma = v[i];
        }
        else
            suma += v[i];
        i++;
    }
    return dias;
}

int camion(std::vector<lli> const& v, lli ini, lli fin, lli d) {
    if (ini == fin) return ini;//Caso base un elemento
    else {
        lli m = (ini + fin) / 2;
        lli dias = comprobar(v, m);
        if (dias <= d+1)
            return camion(v, ini, m, d);
        else
            return camion(v, m + 1, fin, d);

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Función principal para tratar cada caso de prueba
bool resuelveCaso() {
    lli n, m;
    std::cin >> n >> m;

    if (n == 0 && m == 0)
        return false;


    std::vector<lli> v(n);
    lli ini = 0, fin = 0;
    for (lli i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (ini < v[i])
            ini = v[i];
        fin += v[i];
    }

    lli c = camion(v, ini, fin, m);
    std::cout << c << '\n';

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
