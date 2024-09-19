//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;
struct tsolucion {
	lli n1, n2;
};

tsolucion resolver(int n){
	tsolucion sol;
	if (n == 0) { sol.n1 = 0; sol.n2 = 0; }
	else if (n == 1) { sol.n1 = 1; sol.n2 = 0; }
	else {
		sol = resolver(n - 1);
		lli aux = sol.n2;
		sol.n2 = sol.n1;
		sol.n1 = aux + sol.n1;
	}
	return sol;
}
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;
	tsolucion sol = resolver(n);
	std::cout << sol.n1 << std::endl;
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