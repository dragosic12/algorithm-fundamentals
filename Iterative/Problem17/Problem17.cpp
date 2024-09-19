//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


 // función que resuelve el problema
std::vector <int> resolver(const std::vector <int> & v1, const std::vector <int>& v2) {
    std::vector <int> sal;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {

        if (v1[i] < v2[j]) {
            sal.push_back(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j]) {
            sal.push_back(v2[j]);
            j++;
        }
        else if (v1[i] == v2[j]){
            sal.push_back(v2[j]);
            i++; j++;
        }
    }

    for (i; i < v1.size(); i++)
        sal.push_back(v1[i]);
    for (j; j < v2.size(); j++)
        sal.push_back(v2[j]);

    return sal;
}

 // Resuelve un caso de prueba, leyendo de la entrada la
 // configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int n1, n2;
    std::cin >> n1 >> n2;

    std::vector <int> v1 (n1);
    std::vector <int> v2 (n2);

    for (int i = 0; i < n1; i++)
        std::cin >> v1[i];

    for (int i = 0; i < n2; i++)
        std::cin >> v2[i];

    auto sol = resolver(v1,v2);
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