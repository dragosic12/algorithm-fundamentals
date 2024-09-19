// DRAGOS IONUT CAMARASAN
// A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
// El coste de resolver el problema se da en funcion de dos bucles, en el primero
// depende del tamaño de la variable m que se pasa por parametro a la funcion
// ya que este primer bucle da m vueltas por lo tanto es del orden O(m). Como
// hay otro bucle mas abajo que da v.size()-m vueltas y m puede ser igual al 
// tamaño del vector este bucle es del orden de O(v.size()). Al tener los dos bucles
// se suman ambos ordenes obteniendo el coste de la funcion que es O(v.size() + m)
std::pair<int,int> resolver(std::vector <int> const& v, int const & m) {
    std::pair<int, int> sal;
    int sumaParcial = 0;
    for (int i = 0; i < m; i++)
        sumaParcial = sumaParcial + v[i];
    sal.second = sumaParcial;
    for (int j = 0; j < v.size()-m; j++) {
        sumaParcial = sumaParcial + v[j + m];
        sumaParcial = sumaParcial - v[j];
        if (sumaParcial >= sal.second) {
            sal.second = sumaParcial;
            sal.first = j+1;
        }
    }

    return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector <int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    auto sol = resolver(v,m);
    // escribir sol

    std::cout << sol.first << " " << sol.second << std::endl;

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