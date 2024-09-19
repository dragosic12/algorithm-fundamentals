
//*****************
// IMPORTANTE
//
// DRAGOS IONUT CAMARASAN
// A08
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct tDatos {
    std::string id;
    int altura;
    int piso;
};

//El coste de la funcion es del orden de n ya que se recorren todos los elementos al menos una vez
//el coste de hacer todas las operaciones que hay dentro de la funcion son constantes O(1)
//y por lo tanto sumandolas todas son inferiores a O(n) ya que este ultimo es mas grande
//n representa el numero de edificios que se reciben por argumento en la funcion. Este numero
//de edificios es edificios.size(). Por lo tanto si multiplicamos el coste de cada una de las vueltas
//que da el bucle nos quedaria el siguiente coste: O(n) = n*(4*O(1)) + 3*O(1). Como 4*O(1) sigue siendo
//constante, despreciamos el valor de 4 y nos quedamos con O(1) y al igual con el 3, por lo tanto, nos
//queda que O(n) = n*O(1). En resumen es un coste lineal ya que se recorren todos los elementos una vez

// Aqui la función implementada por el alumno
std::vector<std::string> resolver(const std::vector<tDatos>& edificios) {
    
    std::vector<std::string>salida;//O(1)

    int max = edificios[edificios.size() - 1].altura;//O(1)
    if (edificios[edificios.size() - 1].piso > -1) //O(1)
        salida.push_back(edificios[edificios.size() - 1].id);//O(1)
    

    for (int i = edificios.size() - 2; i >= 0; i--) { //O(n)
        if (max < edificios[i].piso) {//O(1)
            salida.push_back(edificios[i].id);//O(1)
        }
        if (max < edificios[i].altura)//O(1)
            max = edificios[i].altura;//O(1)
    }


    return salida;
}



bool resuelveCaso() {
    int numEdificios;
    std::cin >> numEdificios;
    if (numEdificios == 0) return false;
    std::vector<tDatos> edificios(numEdificios);
    for (int i = 0; i < numEdificios; ++i) {
        std::cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;
    }

    auto sol = resolver(edificios);

    if (!sol.empty()) {
        std::cout << sol.size() << std::endl;
        for (const auto& edificio : sol) {
            std::cout << edificio << " ";
        }
        std::cout << std::endl;
    }
    else 
        std::cout << "Ninguno" << std::endl;
    

    // LLamada a la funcion que resuelve el problema



    // Escribir el resultado


    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}