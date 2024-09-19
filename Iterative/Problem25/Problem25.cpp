//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
//Se trata de un rpoblema de ventana
int resolver(std::vector<int> const&v,int const& m) {
    int sal = 0, sumaParcial = 0, s = 0;
    
    
    
    for (int i = 0; i < m; i++) 
        sumaParcial = sumaParcial + v[i];

    s = sumaParcial;
    for (int j = 0; j < v.size() - m; j++) {
        sumaParcial = sumaParcial + v[j + m];
        sumaParcial = sumaParcial - v[j];
            if (sumaParcial >= s) {
                s = sumaParcial;
                sal = j+1;
            }
    }

    return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;
    if (n == 0 && m == 0)
        return false;
    std::vector<int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    int sol = resolver(v,m);
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