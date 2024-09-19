// DRAGOS IONUT CAMARASAN
// A08
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
#include <iostream>
#include <fstream>
#include <vector>



// Explicacion de la solucion del problema


// Coste de la solucion implementada. Se debe justificar indicando 
// la recurrencia y desplegandola 

// Funcion recursiva que resuelve el problema

//int resolver(int ini, int fin, int x, std::vector <int> const& v) {
//
//    int m = (ini + fin) / 2;
//    if (v[m] > v[ini]) { //a)
//        if (x < v[m]) {//Esta en la izquierda por debajo de la mitad
//            if (x > v[ini]) {//izq
//
//            }
//            else if (x < v[ini]) {//der
//
//            }
//        }
//        if (x > v[m]) {//Esta a la derecha de la m y punto por encima
//
//        }
//    }
//    else if (v[m] < v[ini]) {//b)
//
//    } 
//
//
//}


#include <iostream>
#include <fstream>
#include <vector>

// Función recursiva para buscar el valor en el vector rotado
int resolver(int ini, int fin, int x, const std::vector<int>& v) {
    if (ini > fin) return 0; // Caso base: rango vacío

    int m = (ini + fin) / 2;

    if (v[m] == x) return 1; // Encontramos el valor

    // Comprobamos en qué mitad puede estar el valor
    if (v[ini] < v[m]) { // Caso A
        if (x >= v[ini] && x < v[m])
            return resolver(ini, m - 1, x, v);
        else
            return resolver(m + 1, fin, x, v);
    }
    else if (v[ini] > v[m]) { // Caso B
        if (x > v[m] && x <= v[fin])
            return resolver(m + 1, fin, x, v);
        else
            return resolver(ini, m - 1, x, v);
    }
    else { // Elementos consecutivos son iguales
        if (v[m] == x) return 1; // Encontramos el valor
        else return resolver(m + 1, fin, x, v); // Buscamos en la mitad derecha
    }
}

// Función principal
bool resuelveCaso() {
    // Lectura de los datos
    int numElem, x;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::cin >> x;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;

    // Llamada a la función recursiva
    int sol = resolver(0, numElem - 1, x, v);

    // Escribir los resultados
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
