//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void escribirSolucion(std::vector<char> sol) {
    for (int i = 0; i < sol.size(); ++i) 
        std::cout << sol[i];
    
    std::cout << '\n';
}

// función que resuelve el problema
void vueltaAtras(int k, char ramas, int altura, std::vector<char>& sol) {
    for (char i = 'a'; i < 'a'+ramas; ++i) {
        sol[k] = i;
        if (k == altura - 1) //Es sol
            escribirSolucion(sol);
        else
            vueltaAtras(k + 1, ramas, altura, sol);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;

    //n == cuantas letras a,b,c = 3   a,b = 2 RAMAS
    //m == combinaciones de letras  a a, a b = 2    a, b = 1 ALTIRA
    std::cin >> n >> m;
    if (!std::cin)
        return false;

    std::vector<char> sol(m);

    vueltaAtras(0,n,m,sol);

    // escribir sol
    std::cout << '\n';

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