//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

int comprobar(std::vector <int> const& v, int peso) {
    int dias = 1; int i = 0; int suma = 0;
    while (i < (int)v.size()) {
        if (suma + v[i] > peso) {
            dias++;
            suma = v[i];
        }
        else 
            suma += v[i];
        i++;
    }
    return dias;
}

int camion(std::vector<int> const& v, int ini, int fin, int d) {
    if (ini == fin) return ini;//Caso base un elemento
    else {
        int m = (ini + fin) / 2;
        int dias = comprobar(v, m);
        if (dias <= d) 
            return camion(v, ini, m,d);
        else 
            return camion(v, m+1,fin,d);
        
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Función principal para tratar cada caso de prueba
bool resuelveCaso() {
    int n, m;
    std::cin >> n >> m;

    if (n == 0 && m == 0) 
        return false;
    

    std::vector<int> v(n);
    int ini = 0, fin =0 ;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (ini < v[i])
            ini = v[i];
        fin += v[i];
    }

    int c = camion(v, ini,fin,m);
    std::cout << c << '\n';

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
