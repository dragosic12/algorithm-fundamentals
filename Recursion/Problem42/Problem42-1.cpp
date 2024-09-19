//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>


struct tSol {
    long long int sol;
    bool tieneUnos;
};

// función que resuelve el problema
tSol resolver(long long int n) {
    if (n == 0 || n == 1) 
        return { 1, n == 1 };
    else if (n < 10 && n > 1) 
        return { n, false };
    else {
        long long int aux = (9 - (n % 10));

        tSol s = resolver(n / 10);

        // Modificar tieneUnos en el retorno
        if (s.tieneUnos && n >= 10) 
            return { s.sol * 9, true };
        else if (!s.tieneUnos && n >= 10) {
            if (n % 10 > 1) {
                return { s.sol * 9 - aux, false };
            }
            else {
                return { s.sol * 9 - 8, false };
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    long long int n;
    std::cin >> n;
    if (!std::cin)
        return false;

    // escribir sol
    std::cout << resolver(n).sol << '\n';


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