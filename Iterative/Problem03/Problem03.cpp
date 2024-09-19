//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// // función que resuelve el problema
 std::string resolver(std::vector <std::string> & datos) {
     
     std::sort(datos.begin(), datos.end());
     return datos[0];
 }

 // Resuelve un caso de prueba, leyendo de la entrada la
 // configuración, y escribiendo la respuesta
 void resuelveCaso() {
     // leer los datos de la entrada
     int n;
     std::cin >> n;

     std::string s;
     std::vector < std::string > v;
    
     for (int i = 0; i < n; i++) {
         std::cin >> s;
         v.push_back(s);
     }
     std::string sol = resolver(v);
     std::cout << sol << std::endl;
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