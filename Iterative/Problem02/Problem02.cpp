//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


/*
int p=0,q=(int)v.size();
while(p<q){ 
    if(v[p]<=pivote)++p;// elemento del indice izquierdo correcto 
    elseif(v[q-1]>pivote)--q; // elemento del indice derecho correcto 
    else{ //Ambos elementos fuera desitio 
        std::swap(v[p],v[q-1]); 
        ++p;--q; 
    } 
} 
    return p;
*/

// función que resuelve el problema
std::string resolver(std::vector <std::string> datos, std::string casoBuscado) {
    
    int q = (int)datos.size()-1;
    int pos = 1;
    while (0 < q) {
        if (datos[q] == casoBuscado) {

            return std::to_string(pos);
        }
        pos++;
        q--;
    }
    if (q == 0)
        return "NUNCA";

    

}

//// Resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int casosPrueba;
    
    std::cin >> casosPrueba;
    std::vector <std::string> datos ;
    std::string casoBuscado;
    if (casosPrueba == 0)
        return false;
    std::cin >> casoBuscado;
    int n = 0;
    std::string aux;
    while (casosPrueba--) {
        std::cin >> aux;
        datos.push_back(aux);
        n++;
    }

    std::string  sol = resolver(datos, casoBuscado);

    std::cout << sol << std::endl;

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
