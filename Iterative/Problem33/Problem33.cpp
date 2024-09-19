//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct datos{
    int suma;
    int ini;
    int longitud;
};


// función que resuelve el problema
datos resolver(std::vector<int> const& v) {
    
    int i = 0, suma = 0, longitud = 0, ini = 0, maxSuma = 0,aux = 0;
    while (i < v.size()) {
        suma += v[i];
        if (suma > 0) {
            if (aux == 0 && suma > maxSuma) {//Bien
                ini = i;
            }

            if (maxSuma < suma)//Bien
                maxSuma = suma;
            aux++;
            if (longitud < aux && v[i] > 0) //El problema esta aqui que cuenta mal la longitud
                longitud = aux;
        }
        else {
            aux = 0;
            suma = 0;
        }
        i++;
    }

    datos sal{ maxSuma,ini,longitud};
    return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (!std::cin)
        return false;

    std::vector<int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    auto sol = resolver(v);

    // escribir sol
    std::cout << sol.suma << " " << sol.ini << " " << sol.longitud << std::endl;

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