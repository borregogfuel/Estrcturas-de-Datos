#include <iostream>
using namespace std;

/*
    Descripcion: Calcula la sumatoria de 1 hasta n usando un ciclo.
    Entrada: n, entero positivo.
    Salida: la suma 1 + 2 + ... + n como long long.
    Precondicion: n >= 0.
    Postcondicion: retorna la sumatoria; si n es 0 retorna 0.
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
    Descripcion: Calcula la sumatoria de 1 hasta n de forma recursiva.
    Entrada: n, entero positivo.
    Salida: la suma 1 + 2 + ... + n como long long.
    Precondicion: n >= 0.
    Postcondicion: retorna la sumatoria; el caso base n <= 0 retorna 0.
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
    Descripcion: Calcula la sumatoria de 1 hasta n con la formula de Gauss.
    Entrada: n, entero positivo.
    Salida: la suma n*(n+1)/2 como long long.
    Precondicion: n >= 0.
    Postcondicion: retorna la sumatoria en una sola operacion.
    Complejidad: O(1)
*/
long long sumaDirecta(int n) {

    // El cast evita que n*(n+1) se desborde en int cuando n es grande
    return (long long)n * (n + 1) / 2;
}

int main() {

    int s, n;
    cin >> s;

    // Por cada n leido se imprimen los tres resultados separados por espacio
    for (int i = 0; i < s; i++){
        cin >> n;
        cout << sumaIterativa(n) << " " << sumaRecursiva(n) << " " << sumaDirecta(n) << "\n";
    }

    return 0;

}
