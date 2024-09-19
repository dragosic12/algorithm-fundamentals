//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//La ALTURA es la n que es el primer valor que entra al programa, indica la longitud de la linea de lueces a fabricar
//Las RAMAS son los diferentes colores 
//Tambien tenemos que ir marcando para poder saber cuantos objeto hemos añadido de cada tipo

bool esVal(std::vector <int>& sol, std::vector<int> marcas, int k, int i) {
    
    if (k >= 2) {
        if ((sol[k - 2] == sol[k - 1]) && (sol[k-1] == sol[k]))
           return false;
    }
    int j = 0, s = marcas[0], total = 0, min = marcas[0];
    while (j < marcas.size()) {
        if (marcas[j] > 0) total += marcas[j];
        if (marcas[j] > s)  s = marcas[j];
        j++;
    }

    total -= s;
    if (s-total> 1) return false;


    return true;
}


//Condiciones que debe cumplir el problema:
//-Tiras de luces de tal forma que no haya mas de dos luces seguidas del mismo color DONE
//-que se cumpla que en cualquier punto de la tira la suma de las luces de un color no supere en mas de una unidad la suma de las luces de todos los demas colores

void vueltaAtras(int n, int m, int k, std::vector <int> & sol, std::vector <int>& v, std::vector<int> &marcas, int &contador, int consumoTira, int consumoActual) {
    for (int i = 0; i < m; i++) {
        sol[k] = i;
        consumoActual += v[i];
        marcas[i]++;
        if (esVal(sol,marcas,k,i) && consumoActual <= consumoTira) {
            if (k == n - 1) {
                contador++;
            }
            else vueltaAtras(n,m, k + 1, sol, v, marcas,contador,consumoTira,consumoActual);
        }
        marcas[i]--;
        consumoActual -= v[i];
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
    int contador = 0, consumoActual = 0;
    std::vector<int> marcas(numColores);
    vueltaAtras(n, numColores, 0, sol, v,marcas,contador, consumoTira, consumoActual);
    // escribir sol
    std::cout << contador<< '\n';

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
