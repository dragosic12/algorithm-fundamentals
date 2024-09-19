//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
//Final cuando no se realiza ninguna solucion con los datos devueltos
//No Final cuando si que se modifica lo devuelto
//Interesante cuando no contiene 0 y cada digito divide a la suma de todos los digitos que lo precenden 
// y divide a la suma de los que lo preceden (se hace final y no final, ambas)
int resolver(int n, int suma) {
    if (n < 10) 
        return (suma % (n % 10) != 0) ? 0 : n;
    else {
        if (n % 10 == 0) return 0; //Caso en el que hay un 0
        int aux = suma % (n % 10);

        if (suma != 0 && aux != 0) return 0;
        int k = resolver(n / 10, suma + n % 10);
        if (k == 0) return 0;

        return ((k % (n % 10) == 0)) ? k + n % 10 : 0;

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    int sol = resolver(n, 0);
    // escribir sol

    if (sol != 0)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;
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