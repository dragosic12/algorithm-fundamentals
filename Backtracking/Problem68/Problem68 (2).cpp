//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void escribeSol(std::vector<int> sol) {
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i] == 0)
            std::cout << "azul";
        else if (sol[i] == 1)
            std::cout << "rojo";
        else
            std::cout << "verde";
        std::cout << ' ';
    }

    if (sol.size() == 0)
        std::cout << "SIN SOLUCION\n";

}

bool esVal(std::vector<int>& sol, std::vector<int>& contador, std::vector<int> piezas, int k) {
    bool esVal = true;
    if (k >= 2) {//no dos verdes juntas
        if (sol[k] == 2 && sol[k - 1] == 2)
            esVal = false;
    }

    if (piezas[2] > piezas[0])
        esVal = false;

    return esVal;
}

// función que resuelve el problema
void var(int n, int k, std::vector<int>& sol, std::vector<int>& contador, std::vector<int> & piezas, bool & haySol) {
    for (int i = 0; i < 3; i++) {
        sol[k] = i;
        piezas[i]++;
        if (sol[0] == 1) {//r abajo
            contador[i]--;
            if (contador[i] >= 0 && esVal(sol,contador,piezas,k)) {
                if (k == n - 1) {
                    if (piezas[1] > piezas[0] + piezas[2]) {
                        escribeSol(sol);
                        std::cout << '\n';
                        haySol = true;
                    }
                }
                else {
                    var(n, k + 1, sol,contador,piezas,haySol);
                }
            }
            contador[i]++;
        }
        piezas[i]--;

    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int altura, a,r,v;
    std::cin >> altura >> a >> r >> v;

    if (altura == 0)
        return false;

    

    std::vector<int> sol(altura);
    //necesitamos un contador de bolas
    std::vector<int> contador(3);
    contador[0] = a;
    contador[1] = r;
    contador[2] = v;
    std::vector<int> piezas(3,0);
    //std::vector<bool> marcas();
    bool haySol = false;

    var(altura, 0, sol,contador, piezas, haySol);
    if (!haySol)
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