//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
    int nFuncionarios;
    std::vector<std::vector<int>> trabajos;
};

struct tSol {
    int satis;
    std::vector <int> s;
};

int estimar(int k, tDatos const & d, std::vector<bool>const & marcas, int satisMejor, int satisAct) {
    int i = k + 1, j = 0, satisMin = 0, satis = satisAct;
    while (i < d.trabajos.size() && satis <= satisMejor) {
        satisMin = satisMejor;
        
        while (j < d.trabajos[i].size()) {
            if (!marcas[j])
                satisMin = std::min(satisMin, d.trabajos[i][j]);
            j++;
        }

        satis += satisMin;
        j = 0;
        i++;
    }
    return satis;
}

// función que resuelve el problema
void vueltaAtras(int k, tDatos const& d, tSol& sol, std::vector<bool>& marcas, int& satisMejor, std::vector<int> & solMejor) {
    for (int i = 0; i < d.nFuncionarios; i++) {
        sol.s[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            sol.satis += d.trabajos[k][i];
            if (k == d.nFuncionarios - 1) {//Altura
                if (sol.satis < satisMejor) {
                    satisMejor = sol.satis;
                    solMejor = sol.s;
                }
            }
            else {
                if (estimar(k,d,marcas,satisMejor,sol.satis)<satisMejor)
                    vueltaAtras(k + 1, d, sol, marcas, satisMejor,solMejor);
            }

            sol.satis -= d.trabajos[k][i];
            marcas[i] = false;
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
    tDatos d;
    d.nFuncionarios = n;
    for (int i = 0; i < n; i++) {
        std::vector<int> aux(n);
        for (int j = 0; j < n; j++)
            std::cin >> aux[j];
        d.trabajos.push_back(aux);
    }

    //Inicializamos las marcas
    std::vector <bool> marcas(d.nFuncionarios, false);

    //Satis maxima
    int satisMejor = 0;
    for (int i = 0; i < d.nFuncionarios; i++)
        satisMejor += d.trabajos[i][i];


    //Inicializamos sol
    tSol sol;
    sol.satis = 0;
    sol.s.assign(d.nFuncionarios, 0);

    std::vector <int> solMejor;

    vueltaAtras(0, d, sol, marcas, satisMejor, solMejor);
    // escribir sol
    std::cout << satisMejor << '\n';

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