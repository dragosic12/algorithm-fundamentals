//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//////////////////////////////////////////
//HAY QUE HACER LO DEL VECTOR DE ACUMULADOS SINO DA ERROR EN EL DOMJUDGE

// función que resuelve el problema
void resolver(int n, int m, int k, std::vector <int>& sol, std::vector <std::vector<int>> const&sat, std::vector<bool> & marcas, int& contMax, int & contActual, std::vector <int > const& acum) {
    for (int i = 0; i < m; i++) {
        sol[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            contActual += sat[k][i];
                if (k == n - 1) {
                    if (contActual > contMax) 
                        contMax = contActual;
                }
                else {
                    if (contActual + acum[k+1] > contMax)
                        resolver(n, m, k + 1, sol, sat, marcas, contMax, contActual,acum);
                }
            contActual -= sat[k][i];
            marcas[i] = false;
        }


    }



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int nJuguetes, nNinios, max = 0, contActual = 0;
    std::cin >> nJuguetes;

    if (!std::cin)
        return false;

    std::cin >> nNinios;

    std::vector <int> sol(nNinios);
    std::vector <std::vector<int>> sat(nNinios, std::vector<int>(nJuguetes));
    // escribir sol
    for (int j = 0; j < nNinios; j++) 
        for (int i = 0; i < nJuguetes; i++) 
            std::cin >> sat[j][i];
        
    
    std::vector<bool> marcas(nJuguetes,false);

    for (int k = 0; k < nNinios; k++)
        max += sat[k][k];

    // Calcula el vector de maximos
    std::vector <int > acum(nNinios);
    for (int i = 0; i < nNinios; ++i) {
        int auxMax = sat[i][0];
        for (int j = 1; j < nJuguetes; ++j)
            if (auxMax < sat[i][j]) auxMax = sat[i][j];
        acum[i] = auxMax;
    }

    for (int i = (int)acum.size() - 1; i > 0; --i) {
        acum[i - 1] += acum[i];
    }

    resolver(nNinios, nJuguetes, 0, sol, sat, marcas, max, contActual,acum);

    std::cout << max << '\n';

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