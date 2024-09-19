//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
//c1 siempre el vector mas pequeño
std::vector <int> resolver(const std::vector <int>& v1, const std::vector <int>& v2) {
    std::vector <int> sal;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {

        if (v1[i] < v2[j]) 
            i++;
        
        else if (v1[i] > v2[j]) 
            j++;
        
        else if (v1[i] == v2[j]) {
            sal.push_back(v2[j]);
            i++; j++;
        }
    }

    

    return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector <int> c1, c2;
    int aux;
    std::cin >> aux;
    while (aux != 0) {
        c1.push_back(aux);
        std::cin >> aux;
    }
    std::sort(c1.begin(),c1.end());
    
    std::cin >> aux;
    while (aux != 0) {
        c2.push_back(aux);
        std::cin >> aux;
    }
    std::sort(c2.begin(), c2.end());

    std::vector <int> sol;
    if (c1.size() > c2.size()) 
        sol = resolver(c2,c1); 
    else 
        sol = resolver(c1,c2); 

    
    // escribir sol
    for (int i = 0; i < sol.size(); i++)
        std::cout << sol[i] << " ";

    std::cout << std::endl;

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