//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
// NO FINAL (Definicion recursiva)
// 
//                  (n + m)%10                            n < 10 y m < 10
//                  resolver(n/10,m/10)*10 + (n+m)%10     n < 10 y m >= 10
// resolver (n,m)   resolver(n/10,m/10)*10 + (n+m)%10     n >= 10 y m < 10
//                  resolver(n/10,m/10)*10 + (n+m)%10     n >= 10 y m >= 10
//                  
//--------------------                  
//
// COSTE => RECURRENCIA
// n maximo de los dos numeros
// En el caso caso base tiene coste constante ya que es una instruccion de retorno
// El caso recursivo tiene una llamada recursiva en la que el parametro se divide entre 10 (en nuestro caso ambos parametros)
// asi como 4 operaciones de coste constante (multiplicacion, suma, suma y modulo) por lo tanto la recurrencia quedaria asi:
//  
//  T(n) = C1   n<10
//         T(n/10) + c4 n>= 10
//
// C1 -> es una constante que representa el caso base n<10 y m < 10
// C4 -> Es una constante que representa el coste de las instrucciones que acompañan a la llamada 
// recursiva (2 sumas, el producto y el modulo) y el coste de calcular los argumentos (2 divisiones)
// T(n/10) -> Representa el coste de hacer la llamada recursiva con un argumento una unidad menor
// Para obtener el orden de complejidad debemos desplegar la recurrencia:
// T(n) = T(n/10) + C4 = T(n/10^k) + C4 + C4 = T(n/10^k) + C4 + C4 + C4 = ... = T(n/(10^k)) + k*C4 = ... =
// T(10) + log10(n)*c4 ∈O(log(n))
// El coste quedaria del orden de O(log10(n)) = O(log(n)) sinedo n el valor de entrada
int resolver(int n, int m) {
    if (n < 10 && m < 10) //Caso base
        return (n + m) % 10;
    else //Caso recursivo
        return resolver(n / 10, m / 10) * 10 + (n + m) % 10;


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;


    int sol = resolver(n, m);
    // escribir sol
    std::cout << sol << " " << sol << std::endl;

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