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


bool esValida(std::vector<int>const& sol, int const& k, std::vector<int> const&marcas, int const& altura, std::vector<int> const& piezasDeCadaColor) {
    if (marcas[0] > piezasDeCadaColor[0] || marcas[1] > piezasDeCadaColor[1] || marcas[2] > piezasDeCadaColor[2]) //Compruebo el numero de piezas que hay de cada color
        return false;
    if (sol[k] == 2 && sol[k - 1] == 2)//Si no hay 2 verdes juntas
        return false;
    if (marcas[2] > marcas[0] || (marcas[2] + marcas[0] >= (float)altura/2 && marcas[1] != 0))//Compruebo que las piezas verdes y azules no sean mayores a las rojas en funcion de la altura y que las piezas azules no sean menores a las verdes
        return false;
    return true;
}


// función que resuelve el problema
void vueltaAtras(int k, int m, int altura, std::vector<int>& sol, std::vector<int>& marcas, std::vector<int> & piezasDeCadaColor, bool & seEscribio) {
    for (int i = 0; i < m; ++i) {//Iteramos sobre los colores
        sol[k] = i;
        
        marcas[i]++;
        if (sol[0] == 1 ) {//Es sol porque en la base hay una roja
            if (esValida(sol, k, marcas, altura, piezasDeCadaColor)) {
                if (k == altura - 1) { //Llegamos al final
                    escribirSolucion(sol);
                    seEscribio = true;
                }
                else  // Sigue completando la solucion
                    vueltaAtras(k + 1, m, altura, sol, marcas, piezasDeCadaColor, seEscribio);
            }
        }
        marcas[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> piezasDeCadaColor(3);
    int n;
    std::cin >> n >> piezasDeCadaColor[0] >> piezasDeCadaColor[1] >> piezasDeCadaColor[2];
    
    if (n == 0)
        return false;

    std::vector <int> piezas(3);
    for (int& i : piezas) i++;

    std::vector<int> marcas(3, 0);
    bool seEscribio = false;

    std::vector <int> sol(n);

    if (piezasDeCadaColor[1] != 0 && piezasDeCadaColor[1] >= (float)n / 2) {
        vueltaAtras(0, 3, n, sol, marcas, piezasDeCadaColor, seEscribio);
        if (!seEscribio)
            std::cout << "SIN SOLUCION\n";
    }
    else
        std::cout << "SIN SOLUCION\n";
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