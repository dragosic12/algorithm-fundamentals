//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin, int integrantes) {

    int mitad = (ini + fin) / 2;
    int k = ((int)v.size() -mitad) * integrantes;
    if (ini + 1 >= fin) {//2 elemento
        if (ini && fin == v.size())
            return v.size();
        if (v[ini] < k)
            return ini;
        else if (v[fin] < k)
            return fin;
        
    }

    if (v[mitad] < k) {
        return resolver(v, ini, mitad, integrantes);
    }
    else {
        return resolver(v, mitad + 1, fin, integrantes);
    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int dias, integrantes;
    std::cin >> dias >> integrantes;

    std::vector<int> estimaciones(dias);
    for (int i = 0; i < dias; ++i) {
        std::cin >> estimaciones[i];
    }

    int resultado = resolver(estimaciones, 0, estimaciones.size(), integrantes);

    if (resultado == estimaciones.size()) {
        std::cout << "SIN RACIONAMIENTO" << std::endl;
    }
    else {
        std::cout << resultado << std::endl;
    }
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