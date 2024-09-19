//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



 // función que resuelve el problema
//std::pair<int,int> resolver( int m,int ini,int fin, int mitad, std::vector <int> v) {//Busqueda binaria
//    if (mitad == ini+1) {//Caso base de 3 elementos??
//        std::pair<int, int> s(-1,-1);
//        if (v[ini] == m && v[fin-1 ] == m)
//            return { ini,fin-1 };
//        if (v[fin - 1] == m)
//            s.first = fin - 1;
//        else if (v[mitad] == m)
//            s.first = mitad;
//        else if (v[ini] == m)
//            s.first = ini;
//
//        return s;
//    }
//    else {
//        
//        if (v[mitad] > m)//izq
//            return resolver(m, ini, mitad, (ini + mitad) / 2, v);
//        else if (v[mitad] < m) //der
//            return resolver(m, mitad-1, fin, (mitad-1 + fin) / 2, v);
//        //Cuando son iguales primero llamamos a la izquierda y luego a la derecha
//        std::pair<int, int> s2;
//        s2 = resolver(m, ini, mitad, (ini + mitad) / 2, v);
//        std::pair<int, int> s;
//        s = resolver(m, mitad - 1, fin, (mitad - 1 + fin) / 2, v); 
//        return { s2.first,s.second };
//    }
//
//}

int buscarIzq(int m, int ini, int fin, std::vector <int> v) {
    if (ini >= fin) //vector vacio
        return ini;
    else if (ini + 1 == fin) { //Vector 1 elemento
        return ini;
    }
    else {
        int mitad = (ini + fin-1) / 2;
        if (v[mitad] < m)
            return buscarIzq(m, mitad + 1, fin, v);
        else
            return buscarIzq(m, ini, mitad + 1, v);
        
    }
}

int buscarDer(int m, int ini, int fin, std::vector <int> v) {
    if (ini >= fin) //vector vacio
        return ini;
    else if (ini + 1 == fin) { //Vector 1 elemento
        return ini;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] <= m)
            return buscarDer(m, mitad , fin, v);
        else
            return buscarDer(m, ini, mitad, v);

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, m;

    std::cin >> n ;
    if (!std::cin)
        return false;
    std::cin >> m;

    std::vector <int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    int izq = buscarIzq(m,0,n,v);
    
    
    if (izq == n || v[izq] != m) 
        std::cout << "NO EXISTE\n"; 
    else { //Si existe el elemento busca en el lado derecho 
        int der = buscarDer(m, 0, n, v);
        if (izq == der)
            std::cout<< izq <<"\n";
        else 
            std::cout<< izq << " " << der << "\n";
    }


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