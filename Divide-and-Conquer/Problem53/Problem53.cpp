//*****************
// IMPORTANTE
//
// DRAGOS IONUT CAMARASAN
// A08
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo empleado
// Coste del algoritmo. Incluye recurrencia y desplegado de la recurrencia
//
// Y no olvides poner comentarios en el codigo
//*******************************

// Aqui las funciones implementadas por el alumno
std::pair<int, int> resolver(int ini, int fin, const std::vector<int>& v1, const std::vector<int>& v2) {
    // Caso base: una sola posición
    if (ini + 1 == fin) {
        // Verificar condiciones y devolver resultado
        if (ini == 0 && v1[ini] > v2[ini])
            return { -1, 0 };
        if (v1[ini] == v2[ini])
            return { ini,ini };
        return { ini, fin };
    }

    int m = (ini + fin) / 2;

    // Búsqueda binaria
    if (v1[m] > v2[m])
        return resolver(ini, m, v1, v2);
    else if (v1[m] < v2[m])
        return resolver(m, fin, v1, v2);
    else
        return { m, m };
}


bool resuelveCaso()
{
    int numElem;
    std::cin >> numElem;
    if (numElem == 0) return false;
    std::vector<int> v1(numElem);
    std::vector<int> v2(numElem);
    for (int& i : v1) std::cin >> i;
    for (int& i : v2) std::cin >> i;

    // Aqui codigo del alumno
    auto sol = resolver(0, numElem,  v1, v2);

    if (sol.first == sol.second )
        std::cout << "SI " << sol.first << '\n';
    else
        std::cout << "NO " << sol.first << ' ' << sol.second << '\n';
     
    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}