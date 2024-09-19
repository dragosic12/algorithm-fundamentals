//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool resolver(const std::vector<int>& datos, const int& desnivelMax) {

    bool encontrado = true;

    int i = 1, actual = datos[0], tam = datos.size();
    int desnivel = 0;

    while (i < tam && encontrado) {
        if (actual < datos[i])
            desnivel = desnivel + (datos[i] - actual);
        else 
            desnivel = 0;
        
        if (desnivel > desnivelMax)
            encontrado = false;
        actual = datos[i];
        i++;
    }

    return encontrado;
}


bool resuelveCaso() {
    // leer los datos de la entrada
    int desnivelMax, n, aux;
    std::vector<int> datos;

    std::cin >> desnivelMax;
    std::cin >> n;
    if (!std::cin)
        return false;


    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        datos.push_back(aux);
    }

    bool sol = resolver(datos, desnivelMax);

    // escribir sol
    std::string salida = sol ? "APTA" : "NO APTA";
    std::cout << salida << std::endl;

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