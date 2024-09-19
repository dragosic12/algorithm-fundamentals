//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
//Acumulamos la suma de los valores 
void resolver(const std::vector <int>& v, std::vector <long long int>& sal) {
    sal[0] = 0;
    for (int i = 1; i < v.size()+1; i++)
        sal[i] = sal[i - 1] + v[i-1];
    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anoIni, anoFin, numCasos, ini,fin;
    std::cin >> anoIni >> anoFin;

    if (anoIni == 0 && anoFin == 0)
        return false;

    std::vector<int> v(anoFin-anoIni+1);

    for (int i = 0; i < anoFin - anoIni + 1; i++)
        std::cin >> v[i];
    
    std::cin >> numCasos;
    
    std::vector <long long int> sal(anoFin - anoIni + 2);

    resolver(v, sal);

    // escribir sol
    for (int i = 0; i < numCasos; i++) {
        std::cin >> ini;
        std::cin >> fin;
        std::cout << sal[fin-anoIni+1] - sal[ini-anoIni] << std::endl;
    }

    std::cout << "---" << std::endl;

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
