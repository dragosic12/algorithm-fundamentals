//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>


using lli = long long int;

struct tSol {
    lli num;
    bool unos;
};
// función que resuelve el problema
tSol resolver(lli n) {
    if (n < 10) {
        if (n > 1)return { n,false };
        else return { 1,true }; //n == 0 || n == 1
    }
    else {
        lli digito = n % 10;

        tSol sol = resolver(n / 10);

        if (sol.unos)  return { sol.num * 9,true };
        else {
            if (digito > 1) return   { sol.num * 9 - (9 - digito),false };
            else if (digito == 1)  return   { sol.num * 9 - 8,true };
            else return   { sol.num * 9 - 8,false }; // digito == 0
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    long long int n;
    std::cin >> n;
    if (!std::cin)
        return false;

    // escribir sol
    std::cout << resolver(n).num << '\n';


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