//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int inv(int n, int e) {
    if (n < 10) return n+e*10;
    else 
        return inv(n / 10, e * 10 + n % 10);
    
}

int comp(int n, int e, int c) {
    if (n < 10) 
        return e + (abs(n - 9)) * c;
    else 
        return comp(n / 10, e + (abs((n % 10)-9)) * c, c * 10);
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    int s = comp(n, 0, 1);
    std::cout << s << " ";

    int i = inv(s,0);
    if (n % 10 == 0 && n/10 >= 9) 
        std::cout << i << "0" << std::endl;
    else
        std::cout << i << std::endl;
    // escribir sol


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