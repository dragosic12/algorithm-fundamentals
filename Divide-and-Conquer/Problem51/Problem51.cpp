//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
char resolver(int ini, int fin, std::vector<char> const& v) {//Busqueda binaria 
    int m = (ini + fin) / 2;//mitad
    //Caso base 1 o 0 elementos
    if (ini + 1 == fin) {
        if (v[ini] + 1 != v[fin]) 
            return v[ini] + 1;
    }
    if (v[m] - v[ini] != m-ini) 
        return resolver(ini, m, v);
    else 
        return resolver(m, fin, v);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini, fin;
    std::cin >> ini >> fin;
    int tam = ini - fin - 1;
    std::vector <char> v(fin - ini);
    for (int i = 0; i < fin - ini; i++)
        std::cin >> v[i];

    //3 casos bases, cuando falta la mitad, cuando falta el primero y cuando falta el ultimo
    if (v[0] != ini)
        std::cout << ini << '\n';
    else if (v[v.size() - 1] != fin)
        std::cout << fin << '\n';
    else
        std::cout << resolver(0, v.size(), v) << '\n';
    // escribir sol


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