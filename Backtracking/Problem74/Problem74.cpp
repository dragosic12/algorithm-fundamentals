//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
    int nHabitantes;
    int nInvitados;
    int nHada;
    std::vector<std::vector<int>> matriz;
};

struct tSol {
    int satis;
    std::vector<int> sol;
};

bool hayHada(std::vector<int> const & sol, int const& nHada) {
    bool encontrado = false;
    int i = 0, puestoLista = 0;
    while (i < sol.size() && !encontrado) {
        if (sol[i] == i) 
            puestoLista++;
        
        if (nHada == sol[i])
            encontrado = true;
        i++;
    }

    int tercio =  sol.size()/3;
    if (puestoLista >  sol.size()/3)
        return false;

    if (!encontrado)
        return false;
    return true;
}

// función que resuelve el problema
void vueltaAtras(int k, tDatos const& d, tSol &s, std::vector<bool> & marcas, int & satisMejor, int & contador, std::vector<std::vector<int>> &v) {
    for (int i = 0; i < d.nHabitantes; i++) {
        s.sol[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            if (d.matriz[k][i] > 0) {//Comprueba que no sea negativo
                s.satis += d.matriz[k][i];
                if (k == d.nInvitados - 1) {//Es solucion
                    if (hayHada(s.sol,d.nHada)) {//Comprobar si hay algun hada y si mas de un tercio de los puestos coincide con los de la lista
                        if (s.satis > satisMejor) {
                            satisMejor = s.satis;
                            v.clear();
                            v.push_back(s.sol);
                            contador = 1;
                        }
                        else if (s.satis == satisMejor) {
                            v.push_back(s.sol);
                            contador++;
                        }
                    }
                }
                else
                    vueltaAtras(k + 1, d, s, marcas, satisMejor, contador,v);

                s.satis -= d.matriz[k][i];
            }
            marcas[i] = false;
        }
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos d;
    std::cin >> d.nHabitantes;
    if (d.nHabitantes == 0)
        return false;

    std::cin >> d.nInvitados >> d.nHada;
    

    for (int i = 0; i < d.nInvitados; i++) {
        std::vector<int> aux(d.nHabitantes);
        for (int j = 0; j < d.nHabitantes ; j++)
            std::cin >> aux[j];
        d.matriz.push_back(aux);
    }

    std::vector<bool> marcas(d.nHabitantes,false);

    tSol s;
    s.satis = 0;
    s.sol.assign(d.nInvitados,0);
    
    int satisMejor = 0, contador = 0;
    std::vector<std::vector<int>> v;
    /*for (int i = 0; i < d.nHabitantes; i++)
        satisMejor += d.matriz[i][i];*/

    vueltaAtras(0,d,s,marcas, satisMejor,contador,v);
    if (contador > 0)
        std::cout << satisMejor << ' ' << contador << '\n';
    else
        std::cout << "No\n";
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
