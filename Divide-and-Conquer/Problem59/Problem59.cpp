//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tEquilibrado {
    int suma;
    bool esEquilib;
};

// Función auxiliar para contar la cantidad de unos en una submatriz
int contarUnos(int iniFila, int finFila, int iniCol, int finCol, std::vector<std::vector<int>> const& v) {
    int contador = 0;
    for (int i = iniFila; i <= finFila; ++i) {
        for (int j = iniCol; j <= finCol; ++j) {
            contador += v[i][j];
        }
    }
    return contador;
}

// Función recursiva que verifica si la submatriz es equilibrada
tEquilibrado resolver(int iniFila, int finFila, int iniCol, int finCol, std::vector<std::vector<int>> const& v) {
    tEquilibrado sol{ 0, true };

    // Caso base: submatriz 2x2
    if (iniFila == finFila && iniCol == finCol) {
        sol.suma = v[iniFila][iniCol];
        return sol;
    }

    // Dividir la matriz en cuatro submatrices
    int mitadFila = (iniFila + finFila) / 2;
    int mitadCol = (iniCol + finCol) / 2;

    tEquilibrado esqSupIzq = resolver(iniFila, mitadFila, iniCol, mitadCol, v);
    tEquilibrado esqSupDer = resolver(iniFila, mitadFila, mitadCol + 1, finCol, v);
    tEquilibrado esqInfIzq = resolver(mitadFila + 1, finFila, iniCol, mitadCol, v);
    tEquilibrado esqInfDer = resolver(mitadFila + 1, finFila, mitadCol + 1, finCol, v);

    // Verificar condiciones de equilibrio
    if (!esqSupIzq.esEquilib || !esqSupDer.esEquilib || !esqInfIzq.esEquilib || !esqInfDer.esEquilib) {
        sol.esEquilib = false;
        return sol;
    }

    // Verificar condiciones de equilibrio para la submatriz actual
    sol.suma = esqSupIzq.suma + esqSupDer.suma + esqInfIzq.suma + esqInfDer.suma;
    if (sol.suma < ((finFila - iniFila + 1) * (finCol - iniCol + 1) / 4) - 1 ||
        sol.suma > ((finFila - iniFila + 1) * (finCol - iniCol + 1) * 3 / 4)) {
        sol.esEquilib = false;
    }

    // Verificar diferencia de unos entre las submatrices
    int difSup = std::abs(esqSupIzq.suma - esqSupDer.suma);
    int difInf = std::abs(esqInfIzq.suma - esqInfDer.suma);

    if (difSup > 2 || difInf > 2) 
        sol.esEquilib = false;
    

    // Calcular la suma total de unos para la submatriz actual
    

    return sol;
}

// Resuelve un caso de prueba
void resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    std::cin >> tam;
    std::vector<std::vector<int>> v(tam, std::vector<int>(tam));

    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            std::cin >> v[i][j];
        }
    }

    // resolver y mostrar resultado
    auto sol = resolver(0, tam - 1, 0, tam - 1, v);
    if (sol.esEquilib) {
        std::cout << "SI\n";
    }
    else {
        std::cout << "NO\n";
    }
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