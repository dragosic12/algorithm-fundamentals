//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// // función que resuelve el problema
bool resolver(const std::vector<int> & datos, const int & pos) {
    
    int tam = datos.size() - 1, i = pos + 1, valor = datos[pos];

    bool encontrado = true;
    while (i < tam && encontrado) {
        if (datos[i] <= valor)
            encontrado = false;
        
        i++;
    }
    
    return encontrado;


}

 // Resuelve un caso de prueba, leyendo de la entrada la
 // configuración, y escribiendo la respuesta
 void resuelveCaso() {
     // leer los datos de la entrada

     int temps, pos,aux;
     std::cin >> temps;
     std::cin >> pos;

     std::vector <int> datos;
     for (int i = 0; i < temps; i++) {
         std::cin >> aux;
         datos.push_back(aux);
     }

     bool sol = resolver(datos,pos);
     // escribir sol

     std::string salida = sol ? "SI" : "NO";

     std::cout << salida << std::endl;


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