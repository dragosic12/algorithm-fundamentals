//*****************
// IMPORTANTE
//
// DRAGOS IONUT CAMARASAN
// A08
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

/*
Mi algoritmo consiste en dividir ambos vectores por la mitad e ir comparando estas mitades entre si para ver si los valores
de ambos vectores en la mitad son iguales, en caso de que sean iguales o el del primer vector mayor hacemos una recurrencia
con la parte derecha de ambos, desde mitad+1 hasta el final. En caso de que sea menor hacemos la recurrencia con la parte
izquierda de ambos con el inicio en la misma posicion que antes y con el fin en la mitad +1. Hay varios casos base.
1-> Cuando el segundo vector esta vacio que devuelve la primera pos del primero
2-> Cuando ini+1==fin lo que significa que el vector tiene un elemento
3-> Dentro del caso base anterior compruebo que las primeras posiciones del vector sean iguales ya que
en caso de que no lo sean significa que el valor que falta es el primero. Hago lo mismo con el ultimo valor.
(Este ultimo punto creo que se podria hacer antes de llamar a la funcion de resolver)

---------------------------------
COSTE DE LA SOLUCION

Esta solucion al tratarse de Divide y venceras ademas de que se va dividiendo los vectores en cada llamada recursiva
tiene un orden O(log n) ya que se hace una llamada recursiva con la parte izquierda o con la derecha en la cual se analizan
los elementos del vector. Esto nos indica que el orden O(log n) siendo n los elementos del vector.

---------------------------------
RECURRECNIA

T(n)= c0            n == 1 || n == 0
      T(n/2) + c1   n > 1


c0 es el tiempo constante para los casos base.
c1 es el tiempo constante para las operaciones realizadas en cada llamada recursiva.
---------------------------------
DESPLEGADO
T(n) = T(n/2) + c1
    = T(n/(2^2) ) + c1 + c1
    = T(n/(2^3) ) + c1 + c1 + c1
    = . . .
    = T(n/(2^k) ) + k ∗ c1
    = . . .
    = T(1) + log(n) ∗ c1 ∈ O(log(n)).

Calculo del numero de veces que se despliega la recurrencia:
n/(2^k) = 1 ⇔ Despejando el valor de n
n = 2^k ⇔ Tomando logaritmos en ambos terminos de la igualdad
log2(n) = log2(2k) ⇔ Aplicando log2(2k) = k log2(2) y log2(2) = 1)
log2(n) = k

*/

// Aqui la funcion recursiva que resuelve el problema
int resolver(int ini, int fin, std::vector<int> const& v1, std::vector<int> const& v2) {
    int m = (ini + fin - 1) / 2;

    if (ini + 1 == fin) //Caso Base vectores 1 elemento
        return v1[ini];
    

    //Vector con 2 o mas elementos
    if (v1[m] < v2[m])
        return resolver(ini, m + 1, v1, v2);
    else if (v1[m] >= v2[m])
        return resolver(m + 1, fin, v1, v2);


}

// Tratar cada caso
void resuelveCaso() {
    int numA;
    // lectura del vector A
    std::cin >> numA;
    std::vector<int> vA(numA);
    for (int i = 0; i < numA; ++i)
        std::cin >> vA[i];
    // lectura del vector B
    std::vector<int> vB(numA - 1);
    for (int j = 0; j < numA - 1; ++j)
        std::cin >> vB[j];
    // resolver
    int n = vA[0];
    if (!vB.empty()) //Vector vacio
        n = resolver(0, numA, vA, vB);

    // mostrar resultado
    std::cout << n << '\n';

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i)
        resuelveCaso();

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}