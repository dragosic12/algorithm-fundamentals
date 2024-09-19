//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
//Q: {v.size() > 0 y (l: 0 <= l < v.size() : v[l] < v[l+1]) y t >= 0}
//resolver(vector v, int n, int k) returnint res
//P: {#s ={ 0 <= l < v.size() y l < p < v.size() : abs(v[l] - v[p]) == t}}
//O(v.size()) Tiene un orden de complejidad de v.size(), es decir que depende del 
//numero de elementos del vector
int resolver(const std::vector<int> & v, const int & n, const int & k) {
    int sol = 0;
    int i = 0, j = 1;
    if (k != 0) {
        while (i < v.size()-1 && j < v.size()) {
            if (std::abs(v[i] - v[j]) == k) {
                sol++;
                i++;
                j++;
            }
            else if (std::abs(v[i] - v[j]) < k)
                j++;
            else
                i++;
        }
    }
    else 
        sol = v.size();
    
    
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, k;
    std::cin >> n;

    if (n == -1)
        return false;

    std::cin >> k;

    std::vector <int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    

    int sol = resolver(v,n,k);
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
