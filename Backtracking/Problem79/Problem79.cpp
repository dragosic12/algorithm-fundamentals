//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esVal(std::vector<std::vector<int>> const& matriz, int i, std::vector<int>const& pesoAct) {
    for (int j = 0; j < pesoAct.size(); j++) {
        if (matriz[pesoAct[j]][i])
            return false;
    }
    return true;
}

// // función que resuelve el problema
void resolver(int k, int nAmigos, int nCanoas, int pesoMax, std::vector<int> pesos, std::vector<int> & sol,
    std::vector<bool>& marcas, std::vector<std::vector<int>> const& matriz,std::vector<std::vector<int>> &pesoAct,int & sal) {

    for (int i = 0; i < nAmigos; i++) {
        
        sol[k] += pesos[i];
        if (sol[k] <= pesoMax) {
            //pesoAct[k].push_back(i);
            if (!marcas[i]) {
                marcas[i] = true;
                if (k == nCanoas - 1) {
                    for (int j = 0; j < sol.size(); j++)
                        if (sol[i] != 0)
                            sal++;
                }
                else
                    resolver(k+1, nAmigos, nCanoas, pesoMax, pesos, sol, marcas, matriz, pesoAct,sal);
                marcas[i] = false;
            }
            //pesoAct[k].pop_back();
        }
        else {
            resolver(k + 1, nAmigos, nCanoas, pesoMax, pesos, sol, marcas, matriz, pesoAct, sal);
        }
        sol[k] -= pesos[i];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nAmigos, nCanoas, pesoMax, sal =0;
    std::cin >> nAmigos >> nCanoas >> pesoMax;

    std::vector<int> pesos(nAmigos);
    for (int i = 0; i < nAmigos; i++)
        std::cin >> pesos[i];

    std::vector<std::vector<int>> matriz (nAmigos, std::vector<int>(nAmigos));

    std::vector<int> sol(nCanoas,0);
    std::vector<bool> marcas(nAmigos,false);
    std::vector<std::vector<int>> pesoAct(nCanoas);

    for (int i = 0; i < nAmigos; i++)
        for (int j = 0; j < nAmigos; j++)
            std::cin >> matriz[i][j];

    resolver(0, nAmigos, nCanoas, pesoMax, pesos,sol, marcas, matriz, pesoAct, sal);

   

    if (sal != 0)
        std::cout << sal << '\n';
    else
        std::cout << "IMPOSIBLE\n";
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