//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


struct tDatos {
    int nJuguetes;
    int nNinios;
    std::vector <std::vector<int>> matriz;
};

struct tSol {
    int satis;
    std::vector<int> sol;
};

//Tenemos que calcular los objetos que hay por debajo para ver si tomamos esa rama o no
int estimar(tDatos d,int stisActual, int satisMejor, std::vector<bool> marcas,int k) {
    int i = k + 1, sumaSatis = stisActual, maxVector = 0;
        int j = 0;
    while (i < d.matriz.size() && sumaSatis <= satisMejor) {//Recorremos los vectores
        //Dentro de cada vector buscamos el elemento mas grande que no se haya usado antes
        maxVector = 0;
        
        ///////////////ESTO HAY QUE COMPROBARLOOOOOOO SOLO J++///////////////////////
        j++;
        while (j < d.matriz[i].size()) {
            if (!marcas[j])
                maxVector = std::max(maxVector,d.matriz[i][j]);
            j++;
        }
        j = 0;
        
        sumaSatis += maxVector;
        i++;
    }

    return sumaSatis;

}

/////////////////////////////////////////
// HAY QUE HACER LA ESTIMACION CON EL VECTOR DE ACUMULADOS
// función que resuelve el problema
void vueltaAtras(int k, tDatos const& d, tSol& s, int& satisMejor, std::vector<bool>& marcas, std::vector<int> &solMejor) {
    for (int i = 0; i < d.nJuguetes; i++) {
        s.sol[k] = i;
        if (!marcas[i]) {//Si el juguete no esta asignado
            marcas[i] = true;
            s.satis += d.matriz[k][i];
            if (k == d.nNinios - 1) {//Altura
                if (s.satis > satisMejor) {
                    satisMejor = s.satis;
                    solMejor = s.sol;
                }
            }
            else {
                if (estimar(d,s.satis,satisMejor,marcas,k) >satisMejor)
                    vueltaAtras(k + 1, d, s, satisMejor, marcas,solMejor);
            }
            s.satis -= d.matriz[k][i];
            marcas[i] = false;
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos d;
    std::cin >> d.nJuguetes;
    if (!std::cin)
        return false;
    std::cin >> d.nNinios;

    for (int i = 0; i < d.nNinios; i++) {
        std::vector<int> aux(d.nJuguetes);
        for (int j = 0; j < d.nJuguetes; j++)
            std::cin >> aux[j];
        d.matriz.push_back(aux);
    }

    std::vector<bool> marcas(d.nJuguetes, false);//Vector de marcas para ir marcando los regalos que ya se han asignado
    //Calculamos cual es la mejor satisfaccion
    
    
    int satisMejor = 0;
    for (int i = 0; i < d.nNinios; ++i) //Tomamos el valor maximo de cada uno de los vectores
        satisMejor += d.matriz[i][i];


    tSol s;
    s.sol.assign(d.nNinios, 0);
    s.satis = 0;
    std::vector<int> solMejor;
    vueltaAtras(0, d, s, satisMejor, marcas, solMejor);

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