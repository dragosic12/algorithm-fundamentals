// DRAGOS IONUT CAMARASAN   
// A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// El coste de la funcion es lineal con respecto a los elementos del vector
// O(1)
std::vector <int>  resolver(const std::vector<int>& v, int const & ini, int const& fin) {
    std::vector<int> aux;
    int max = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
            aux.push_back(ini + i);
        }
        
    }


    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector <int> v;
    int ini,fin;
    int n;

    std::cin >> ini >> fin;
    int numElems = fin - ini + 1;

    //Aqui rellenamos el vector con los elementos que se nos proporciona
    for (int i = 0; i < numElems; i++) {
        std::cin >> n;
        v.push_back(n);
    }

    auto sol = resolver(v,ini,fin);

    for (int i = 0; i < sol.size(); i++) 
        std::cout << sol[i] << " ";
    

    std::cout << std::endl;

    // escribir sol


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