//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector <int> const& v, int k) {
    int sol = 0, i = 0, j = 0, contadorUnos = 0, ini = 0;
    bool primerUno = false, encontradoInter = false;
    while (i < v.size() && !primerUno) {//buscamos segmento con k unos (primer intervalo)
        if (v[i]) {
            contadorUnos++;
            primerUno = true;
        }
        i++;
    }

    j = i;
    if (!primerUno)
        return v.size() + 1;
    else
        i--;
    if (contadorUnos == k && k == 1) 
        return 1;
    

    while (j < v.size() && !encontradoInter) {//buscamos intervalo de k
        if (v[j]) {
            contadorUnos++;
            if (contadorUnos == k) {
                sol = j - i + 1;
                encontradoInter = true;
            }
            
        }
        j++;
    }
    if (encontradoInter)
        j--;
    else
        return v.size() + 1;

    while (j < v.size()) {
        if (v[j] && v[i]) {
            i++;
            while(i < v.size() && !v[i] )
                i++;
            j++;
            while ( j < v.size() && !v[j] )
                j++;
            if (sol > j - i + 1 && j != i && j != v.size())
                sol = j - i + 1;
        }
    }

    

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n ,k;
    std::cin >> n;
    if (n == -1)
        return false;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    std::cin >> k;
    int sol = resolver(v,k);
    // escribir sol
    
    std::cout << sol << std::endl;

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
