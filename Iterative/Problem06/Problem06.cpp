// DRAGOS IONUT CAMARASAN   
// A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//Función resolver :

//Declaración de variables : O(1) constante
//Inicialización de variables : O(1) constante
//Bucle for que recorre el vector v : O(N) lineal, donde N es el tamaño del vector.
//Dentro del bucle, hay operaciones que son O(1) constante, como comparaciones y asignaciones.
//El coste total de la función resolver es O(N) lineal debido al bucle que recorre el vector v.
std::pair<long long int, int>  resolver(const std::vector<int>& v) {
    std::pair<long long int, int> salida (v[0], 0);
    int minimo = v[0], suma = 1;
    for (int i = 1; i < v.size(); i++) {
        if (minimo > v[i]) {
            minimo = v[i];
            suma = 1;
        }
        else if (minimo == v[i]) 
            suma++;
        
        salida.first = salida.first + v[i];
    }
    int reps = minimo * suma;

    salida.first = salida.first - reps;
    salida.second = v.size() - suma;
    return salida;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector <int> v;
    int aux;
    int n;

    std::cin >> aux;

    //Aqui rellenamos el vector con los elementos que se nos proporciona
    for (int i = 0; i < aux; i ++ ) {
        std::cin >> n;
        v.push_back(n);
    }

    auto sol = resolver(v);

    std::cout << sol.first << " " << sol.second << std::endl;
    
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