//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
int resolver(int n, bool& tieneUnos) {
    if (n == 0 || n == 1) {
        if (n == 1)
            tieneUnos = true;
        return 1;
    }
    else if (n < 10 && n>1)
        return n;
    else {
        int aux = (9 - (n % 10));

        int s = resolver(n / 10, tieneUnos);
        if (tieneUnos && n >= 10)
            return s * 9;
        else if (!tieneUnos && n >= 10) {
            if (n % 10 > 1)
                return s * 9 - aux;
            else
                return s * 9 - 8;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    std::cin >> n;
    if (!std::cin)
        return false;
    bool tieneUnos = false;
    std::cout << resolver(n, tieneUnos) << '\n';

    // escribir sol


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