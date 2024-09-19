﻿//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector <int> resolver(std::vector <int> const&  v1, std::vector <int> const& v2) {
    std::vector <int> sal;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            sal.push_back(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j]) {
            sal.push_back(v2[j]);
            j++;
        }
        else if (v1[i] == v2[j]) {
            i++;
            j++;
        }

    }

    while (i < v1.size()) {
        sal.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()) {
        sal.push_back(v2[j]);
        j++;
    }


    return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector <int> v1;
    std::vector <int> v2;

    int aux;
    std::cin >> aux;
    while (aux != 0) {
        v1.push_back(aux);
        std::cin >> aux;
    }

    std::cin >> aux;
    while (aux != 0) {
        v2.push_back(aux);
        std::cin >> aux;
    }
    

    auto sol = resolver(v1,v2);
    // escribir sol

    for (int i = 0; i < sol.size(); i++) 
        std::cout << sol[i] << " ";
    std::cout << std::endl;
    
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