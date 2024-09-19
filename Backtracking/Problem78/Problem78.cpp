// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


// función que resuelve el problema
void resolver(int k, int nNinios, int nJuguetes,
    std::vector<int> const& cantidad,
    std::vector<std::vector<int>> const& satis,
    std::vector<std::string> const& tipo,
    std::vector<int>& sol, std::vector<int>& marcas,
    int minSatis, std::vector<int>& satisActual, int satisTotal, std::vector<std::string> &tipos, bool& entro) {

    for (int i = 0; i < nJuguetes; i++) {
        sol[k] = i;
        //Distinguimos casos, cuadno es el 1 o cuando es el 2
        //En caso de ser el 1 el valor se mete si o si a menos que no quede cantidad y la satisfaccion si inicializa al valor 
        //que esntra
        if (k % 2 == 0) {
            satisActual[k/2] = satis[k / 2][i];
            tipos[k/2] = tipo[i];
            if (marcas[i] > 0) {
                marcas[i]--;
                resolver(k + 1, nNinios, nJuguetes, cantidad, satis, tipo, sol, marcas, minSatis, satisActual, satisTotal, tipos, entro);
                marcas[i]++;
            }

        }
        else {
            satisActual[k/2] += satis[k / 2][i];

            if (marcas[i] > 0 && tipo[i] != tipos[k/2]) {
                marcas[i]--;
                if (satisActual[k/2] >= minSatis && sol[k] > sol[k-1]) {
                    if (k == nNinios * 2 - 1) {
                        for (int j = 0; j < sol.size(); j++)
                            std::cout << sol[j] << ' ';
                        std::cout << '\n';
                        entro = true;
                    }
                    else {
                        resolver(k + 1, nNinios, nJuguetes, cantidad, satis, tipo, sol, marcas, minSatis, satisActual, satisTotal, tipos, entro);
                    }
                }
                marcas[i]++;
            }
            satisActual[k/2] -= satis[k / 2][i];
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nJuguetes, nNinios, minSatis, aux;
    bool entro = false;
    std::cin >> nJuguetes >> nNinios >> minSatis;

    if (!std::cin)
        return false;

    std::vector<int> cantidad(nJuguetes);
    std::vector<std::vector<int>> satis(nNinios, std::vector<int>(nJuguetes));
    std::vector<std::string> tipo(nJuguetes);
    //Hay que meter un vector de marcas
    std::vector<int> marcas(nJuguetes);
    std::vector<bool> tip(nJuguetes, false);

    for (int i = 0; i < nJuguetes; i++) {
        std::cin >> cantidad[i];
        marcas[i] = cantidad[i];
    }

    std::string name;
    for (int i = 0; i < nJuguetes; i++) {
        std::cin >> tipo[i];
    }



    for (int i = 0; i < nNinios; i++)
        for (int j = 0; j < nJuguetes; j++)
            std::cin >> satis[i][j];


    std::vector<std::string> tipos(nNinios);



    std::vector<int> sol(nNinios * 2);

    int satisTotal = 0;
    std::vector<int> satisActual(nNinios);
    //Hay que inicializar el valor de la satisfaccion total

    std::getline(std::cin, name);

    resolver(0, nNinios, nJuguetes, cantidad, satis, tipo, sol, marcas, minSatis, satisActual, satisTotal, tipos, entro);

    if (!entro)
        std::cout << "SIN SOLUCION\n";
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