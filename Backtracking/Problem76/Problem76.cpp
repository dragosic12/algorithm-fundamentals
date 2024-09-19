//DRAGOS IONUT CAMARASAN
//A08


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
    int coste;
    int superficie;
};

struct tSol {
    int coste;
    int superficie;
    std::vector<bool> s;
};

class comparador {
public:
    bool operator() (tDatos p1, tDatos p2) {
        return (float)p1.superficie / p1.coste > (float)p2.superficie / p2.coste;
    }
};

int estimar(std::vector<tDatos> const& datos, int costeAct, int presupuesto, int k) {
    int i = k + 1; int sumaCoste = costeAct; int sumaSuperf = 0; 
    while (i < datos.size() && sumaCoste + datos[i].coste <= presupuesto) {
        sumaCoste += datos[i].coste; 
        sumaSuperf += datos[i].superficie;
        ++i; 
    } // La parte que queda sin completar. Como la division es entera se suma 1 al resultado 
      // para asignar una cota superior a la variable entera 
    if ( i < datos.size() && sumaCoste < presupuesto)
        sumaSuperf += datos[i].superficie * (presupuesto -sumaCoste)/datos[i].coste + 1;
    return sumaSuperf; 
}

// función que resuelve el problema
//Arblo binariooooo
//LA DIFICULTAD DEL PROBLEMA ESTA EN INICIALIZAR LA SUPERFICIEMEJOR
//HAY EN ALGUNOS QUE SE INICIALIZA A LA DIAGONAL, HAY OTROS QUE A 0 (MUY POCOS)
//Y HAY OTROS COMO ESTE QUE SE INICIALIZA CON UNA FUNCION
void vueltaAtras(int k, std::vector<tDatos> const& objetos, int const& presupuesto, tSol& sol,
    int& costeMejor, int& superficieMejor, std::vector<bool> & solMejor) {
    //Como solo son 2 los casos vamos a distinguirlos con un if
    //ya que vamos a decidir si tomar el objeto en funcion de su 
    //coste y de su superficie a traves de un arbol de exploracion
    //binario, por lo que por cada objeto estara la opcion de tomarlo (SI)
    //o NO
    sol.s[k] = true;
    sol.coste += objetos[k].coste;
    sol.superficie += objetos[k].superficie;
    if (sol.coste <= presupuesto) {//Si el coste no supera el presupuesto todo bien!
        if (k == sol.s.size() - 1) {//Es una solucion
            if (sol.superficie > superficieMejor) {
                superficieMejor = sol.superficie;
                solMejor = sol.s;
            }

        }
        else
            vueltaAtras(k + 1, objetos, presupuesto, sol, costeMejor, superficieMejor, solMejor);
    }
    sol.superficie -= objetos[k].superficie;
    sol.coste -= objetos[k].coste;

    sol.s[k] = false;
    if (k == sol.s.size() - 1) {
        if (sol.superficie > superficieMejor) {
            superficieMejor = sol.superficie;
            solMejor = sol.s;
        }

    }
    else {
        if (estimar(objetos,sol.coste,presupuesto,k) + sol.superficie > superficieMejor)
            vueltaAtras(k + 1, objetos, presupuesto, sol, costeMejor, superficieMejor, solMejor);
    }


}



//Superficie por unidad de precio. Se hace esta inicilizacion a un valor valido para poder podar
//mas el arbol. Se pueden ordenar los datos para conseguir el mejor y por tanto la sol sera parecida a la final.
//Como se trata de un problema de maximizacion se inicializara al menor valor. Si se trata de minimizacion
//se iniciara al mayor
int inicializarSuperficie(std::vector<tDatos>const& Obj, int costeMax) {
    int i = 0; int sumaSuperficie = 0; int sumaCoste = 0;
    while (i < Obj.size() && sumaCoste + Obj[i].coste <= costeMax) {
        sumaSuperficie += Obj[i].superficie;
        sumaCoste += Obj[i].coste;
        ++i;
    } return sumaSuperficie;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nObjetos, presupuesto;
    std::cin >> nObjetos;

    if (!std::cin)
        return false;

    tSol sol;
    std::cin >> presupuesto;

    std::vector<tDatos>objetos(nObjetos);
    for (int i = 0; i < nObjetos; i++)
        std::cin >> objetos[i].coste >> objetos[i].superficie;



    sol.coste = 0;
    sol.superficie = 0;
    sol.s.assign(nObjetos, false);

    std::sort(objetos.begin(), objetos.end(), comparador());

    int costeMejor = 0, superficieMejor = inicializarSuperficie(objetos, presupuesto);
    std::vector<bool> solMejor;
    vueltaAtras(0, objetos, presupuesto, sol, costeMejor, superficieMejor, solMejor);

    // escribir sol
    std::cout << superficieMejor << '\n';

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