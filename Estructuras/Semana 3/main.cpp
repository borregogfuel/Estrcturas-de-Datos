#include <iostream>
using namespace std;
// Guillermo Gil Palomar A01199519 
/*
    Descripcion: suma los numeros del 1 al n con un ciclo.
    Entrada: n, un entero positivo.
    Salida: el resultado de la suma.
    Precondicion: n >= 0.
    Postcondicion: si n es 0 devuelve 0.
    Complejidad: O(n)
*/
long long sumaIterativa(int n) {

    long long suma = 0;

    for (int i = 1; i <= n; i++){
        suma += i;
    }

    return suma;
}

/*
    Descripcion: lo mismo pero llamandose a si misma.
    Entrada: n, un entero positivo.
    Salida: el resultado de la suma.
    Precondicion: n >= 0.
    Postcondicion: el caso base es n <= 0 y devuelve 0.
    Complejidad: O(n)
*/
long long sumaRecursiva(int n) {

    if (n <= 0){
        return 0;
    }

    else {
        return n + sumaRecursiva(n - 1);
    }
}

/*
    Descripcion: usa la formula n*(n+1)/2, sin ciclos.
    Entrada: n, un entero positivo.
    Salida: el resultado de la suma.
    Precondicion: n >= 0.
    Postcondicion: lo saca en una sola cuenta.
    Complejidad: O(1)
*/
long long sumaDirecta(int n) {

    // sin el cast, n*(n+1) se pasa del limite de int cuando n es grande
    return (long long)n * (n + 1) / 2;
}

int main() {

    int s, n;
    cin >> s;

    // leo cada n e imprimo los tres resultados separados por espacio
    for (int i = 0; i < s; i++){
        cin >> n;
        cout << sumaIterativa(n) << " " << sumaRecursiva(n) << " " << sumaDirecta(n) << "\n";
    }

    return 0;

}
