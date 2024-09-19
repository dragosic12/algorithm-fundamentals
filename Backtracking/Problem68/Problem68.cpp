//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tMarcas {
    std::vector<bool> vector; 
    tMarcas(int n) : vector(n, false) {} 
};


//La ALTURA es el valor de la n, lo que nos da en la entrada de texto
//Las RAMAS son los tres valores posibles, que son el 0 = Azul, 1 = Rojo y 2 = Verde
//Todo ello da lugar al arbol de exploracion
//El vector sol va guardando todos los valores que va viendo en el arbol, con repeticion.
//Esto da lugar a que el vector solucion tiene como tamaño la altura del arbol y como valor las ramas del mismo

void escribirSolucion(std::vector <int > const& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            std::cout << "azul ";
        else if (v[i] == 1)
            std::cout << "rojo ";
        else
            std::cout << "verde ";
    }
    std::cout << '\n';
}


bool esValida(std::vector<int>const& sol, int const& k, std::vector<int> const&l, int const& altura, std::vector<int> const& num) {
    if (l[0] > num[0] || l[1] > num[1] || l[2] > num[2])
        return false;
    if (sol[k] == 2 && sol[k - 1] == 2)//Si no hay 2 verdes juntas
        return false;
    if (l[2] > l[0] || (l[2] + l[0] >= (float)altura/2 && l[1] != 0))
        return false;
    return true;
}


// función que resuelve el problema
void vueltaAtras(int k, int m, int altura, std::vector<int>& sol, std::vector<int>& l, std::vector<int> const& num) {
    for (int i = 0; i < m; ++i) {//Iteamos sobre los colores
        sol[k] = i;
        
        l[i]++;
        if (sol[0] == 1 ) {//Es sol  
            if (esValida(sol, k, l, altura, num)) {
                if (k == altura - 1)
                    escribirSolucion(sol);
                else  // Sigue completando la solucion
                    vueltaAtras(k + 1, m, altura, sol, l, num);
            }
        }
        l[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> num(3);
    int n;
    std::cin >> n >> num[0] >> num[1] >> num[2];
    int max = std::max(num[0], num[1]);
    max = std::max(max, num[2]);//Aqui obtenemos el maximo de piezas que hay para crear la matriz de marcajes, en la cual vamos a ir marcando las 
    if (n == 0)
        return false;

    std::vector <int> piezas(3);
    for (int& i : piezas) i++;

    std::vector<int> l(3, 0);


    std::vector <int> sol(n);
    if (num[1]!=0 && (n / num[1] < n / 2 || num[1] == n))
        vueltaAtras(0, 3, n, sol, l, num);
    else
        std::cout << "SIN SOLUCION";
    std::cout << '\n';
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