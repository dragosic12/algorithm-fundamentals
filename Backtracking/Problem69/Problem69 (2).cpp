//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool cuentaTres (std::vector<int>const& sol) {
    int a = sol[0], contador = 1;
    for (int i = 1; i < sol.size(); i++) {
        if (a == sol[i])
            contador++;
        else
            contador = 1;
        if (contador == 3)
            return false;
        a = sol[i];
    }

    return true;
}

bool esValida(std::vector<int> const& sol, std::vector<int> const& marcas, int const& consumoActual, int const&consumoMax) {
    if (consumoActual > consumoMax)
        return false;
    int i = 1, suma = marcas[0];
    
    while (i < marcas.size() ) {
        suma = std::abs(suma - marcas[i]);
        i++;
    }
    if (suma > 1)
        return false;

    return true;
}

// función que resuelve el problema
void vueltaAtras(int k, int ramas, int altura, std::vector<int> & sol, std::vector<int>const& consumoCadaBombilla, std::vector<int> &marcas,
    int consumoActual, int consumoMax, int & sal, std::vector<std::vector<int>> & v, int  contador) {
    for (int i = 0; i < ramas; i++) {
        sol[k] = i;
        consumoActual += consumoCadaBombilla[i];
        marcas[i]++;
        
        if (k == altura - 1 ) {
            if (esValida(sol, marcas, consumoActual, consumoMax)) {
                v.push_back(sol);
                if (cuentaTres(sol))
                    sal++;
            }
        }
        else {
            if (esValida(sol, marcas, consumoActual, consumoMax)) 
                vueltaAtras(k + 1, ramas, altura, sol, consumoCadaBombilla, marcas, consumoActual, consumoMax,sal,v, contador);

        }
        
        marcas[i]--;
        consumoActual -= consumoCadaBombilla[i];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longitud, numColores, consumoMax, sal = 0;
    std::cin >> longitud;
    if (longitud == 0)
        return false;

    std::cin >> numColores >> consumoMax;

    std::vector<int> consumoCadaBombilla(numColores);
    std::vector<int> marcas(numColores,0);
    int contador = 1;
    for (int i = 0; i < numColores; ++i) {
        std::cin >> consumoCadaBombilla[i];
    }

    std::vector<int> sol(longitud, -1);
    std::vector < std::vector<int>> v;

    vueltaAtras(0, numColores, longitud, sol, consumoCadaBombilla,marcas, 0, consumoMax, sal,v, contador);

    // escribir sol
    std::cout << sal << '\n';
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
