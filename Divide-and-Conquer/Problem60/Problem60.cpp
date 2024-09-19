//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



int merge(std::vector<int>& v, int ini, int m, int fin) {
    int inversiones = 0;
    int n1 = m - ini + 1;
    int n2 = fin - m;

    // Crear vectores temporales
    std::vector<int> izquierda(v.begin() + ini, v.begin() + m + 1);
    std::vector<int> derecha(v.begin() + m + 1, v.begin() + fin + 1);

    // Índices iniciales de los subvectores
    int i = 0, j = 0, k = ini;

    // Combinar las dos mitades ordenadas
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            v[k] = izquierda[i];
            i++;
        }
        else {
            v[k] = derecha[j];
            inversiones += (m - (ini + i) + 1); // Contar inversiones
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de izquierda, si los hay
    while (i < n1) {
        v[k] = izquierda[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de derecha, si los hay
    while (j < n2) {
        v[k] = derecha[j];
        j++;
        k++;
    }

    return inversiones;
}

int mergesort(std::vector<int>& v, int ini, int fin) {
    int inversiones = 0;

    if (ini < fin) {
        int mitad = (ini + fin) / 2;
        inversiones += mergesort(v, ini, mitad);
        inversiones += mergesort(v, mitad + 1, fin);

        inversiones += merge(v, ini, mitad, fin);
    }

    return inversiones;
}

bool resuelveCaso() { // Lectura de los datos 
    int numElem;
    std::cin >> numElem;

    if (!std::cin)
        return false;

    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) std::cin >> v[i]; // Ordena el vector 

    std::cout << mergesort(v,0,v.size()-1) << '\n'; // Escribe los valores ordenados


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