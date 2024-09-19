//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//La ALTURA es el valor de la n, lo que nos da en la entrada de texto
//Las RAMAS son los tres valores posibles, que son el 0 = Azul, 1 = Rojo y 2 = Verde
//Todo ello da lugar al arbol de exploracion
//El vector sol va guardando todos los valores que va viendo en el arbol, con repeticion.
//Esto da lugar a que el vector solucion tiene como tamaño la altura del arbol y como valor las ramas del mismo

void escribirSolucion(std::vector <int > const& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            std::cout << "Azul ";
        else if (v[i] == 1)
            std::cout << "Rojo ";
        else
            std::cout << "Verde ";
    }
    std::cout << '\n';
}

// función que resuelve el problema
void vueltaAtras(int k,int m, int altura, std::vector<int> &sol) {
    for (int i = 0; i < m; ++i) {//Iteamos sobre los colores
        sol[k] = i;
        if (k == altura - 1) { // Es solucion
            escribirSolucion(sol);
        }
        else { // Sigue completando la solucion
            vueltaAtras(k+1,m,altura, sol);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == 0)
        return false;

    std::vector <int> piezas(3);
    for (int& i : piezas) i++;

    std::vector <int> sol(n);
    vueltaAtras(0,3,n,sol);

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