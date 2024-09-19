//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// // función que resuelve el problema
int resolver(const std::vector<int> & datos) {
    int suma = 0, sol = -1;
    int i = datos.size() - 1;
    while (i >= 0 && sol == -1) {
        if (suma == datos[i]) 
            sol = i;
        
        suma = suma + datos[i];
        i--;
    }
    if (datos.size() == 1 && datos[0] == 0)
        sol = 0;
    return sol;

}

// // Resuelve un caso de prueba, leyendo de la entrada la
// // configuración, y escribiendo la respuesta
 void resuelveCaso() {
     // leer los datos de la entrada
     std::vector<int> datos;
     int n, aux;
     std::cin >> n;

     for (int i = 0; i < n; i++) {
         std::cin >> aux;
         datos.push_back(aux);
     }

     auto sol = resolver(datos);
     // escribir sol
     if (sol != -1) 
         std::cout << "Si" << " " << sol << std::endl;
     else 
         std::cout << "No" << std::endl;
  

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