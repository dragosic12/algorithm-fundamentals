//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
std::pair<std::vector<int>,int> resolver(std::vector<int> const& v, int const&  p) {
    std::pair<std::vector<int>, int> sol;
    sol.second = 0;
    int contador = 1, aux = v[v.size()-1], i = v.size()-2, valMax = v[v.size() - 1], pos = i;
    for (; i >= 0; i--) {
        if (valMax < aux)
            valMax = aux;
        if (aux == v[i] ) {
            if (contador == 1) 
                pos = i;
            contador++;
        }
        else {
            if (contador >= p) {
                if (aux >= valMax) {
                    valMax = aux;
                    sol.first.push_back(pos+1);
                    if (contador > sol.second) 
                        sol.second = contador;
                }
            }
            contador = 1;
        }
        aux = v[i];
    }
    if (contador >= p) {
        if (aux >= valMax) {
            sol.first.push_back(pos+1);
            if (contador > sol.second) 
                sol.second = contador;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int h, p;
    std::cin >> h;
    if (!std::cin)
        return false;

    std::cin >> p;
    std::vector<int> v(h);

    for (int i = 0; i < v.size(); i++)
        std::cin >> v[i];

    auto sol = resolver(v,p);

    //escribir sol
    if (!sol.first.empty()) {
        std::cout << sol.second << " " << sol.first.size() << " " << sol.first[0];
        for (int i = 1; i < sol.first.size(); i++)
            std::cout << " " << sol.first[i];
        std::cout << std::endl;
    }
    else 
        std::cout << "0 0" << std::endl;
    

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