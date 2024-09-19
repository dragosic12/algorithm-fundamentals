//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//La ALTURA es la n que es el primer valor que entra al programa, indica la longitud de la linea de lueces a fabricar
//Las RAMAS son los diferentes colores 
//Tambien tenemos que ir marcando para poder saber cuantos objeto hemos añadido de cada tipo


//Condiciones que debe cumplir el problema:
//-Tiras de luces de tal forma que no haya mas de dos luces seguidas del mismo color DONE
//-que se cumpla que en cualquier punto de la tira la suma de las luces de un color no supere en mas de una unidad la suma de las luces de todos los demas colores
bool esValida(std::vector<int>const& sol, int const& k, int const& consummoTIras, int const& sumaConsumo, std::vector <int>const& marcas) {
    if (sol[k] == sol[k - 1])
        return false;
    if (sumaConsumo > consummoTIras)
        return false;

    return true;
}

// función que resuelve el problema

void vueltaAtras (int k, int m, std::vector <int> & sol, std::vector<int> v, std::vector <int> & marcas, int consummoTIras, int &sal, int &sumaConsumo) {
    for (int i = 0; i < m; i++) {//ramas los diferentes tipos de luces
        sol[k] = i;
        sumaConsumo += v[i];
        marcas[i] += v[i];
        if (esValida(sol,k,consummoTIras, sumaConsumo,marcas)) 
            sal++;
        else
            vueltaAtras(k + 1, m, sol,v, marcas, consummoTIras, sal, sumaConsumo);
        marcas[i] -= v[i];
        sumaConsumo -= v[i];
    }

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (n == 0)
        return false;

    int numColores, consumoTira, sal = 0, aux = 0;

    std::cin >> numColores >> consumoTira;

    std::vector <int> v(numColores);

    for (int& i : v)
        std::cin >> i;
    
    std::vector<int> sol (n);
    std::vector<int> marcas(numColores);

    vueltaAtras(0,numColores,sol,v,marcas,consumoTira, sal, aux);

    // escribir sol
    std::cout << sal << '\n';

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
