//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

// función que resuelve el problema
//d indica el numero de veces que se puede repetir un vector
//creciente por lo pelos cuando hay una diferencia de 1 entre cada uno de los elementos
bool resolver(const std::vector<int> & v, const int & d, const int max) {
    bool esDivertido = true, esCreciente = true;
    //long long int reps [max][1];
    std::unordered_map<int, int> repetidos;
    int i = 0, tam = v.size()-1;
    while (i < tam && esDivertido && esCreciente) {
        //Comprobar que sea creciente:
        if (v[i] > v[i + 1] || v[i]+1 < v[i+1])
            esCreciente = false;

        //Comprobar que sea divertido:
        repetidos[v[i]]++;
        if (repetidos[v[i]] > d)
            esDivertido = false;

        i++;
    }

    repetidos[v[i]]++;
    if (repetidos[v[i]] > d)
        esDivertido = false;
    return esDivertido && esCreciente;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
     
    int d, elems,aux,max = 0;
    
    std::cin >> d >> elems;
    std::vector<int> v ;

    for (int i = 0; i < elems; i++) {
        std::cin >> aux;
        if (aux > max)
            max = aux;
        v.push_back(aux);
    }
        
    

    auto sol = resolver(v,d,max);
    // escribir sol

    sol ? std::cout << "SI" : std::cout << "NO";
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