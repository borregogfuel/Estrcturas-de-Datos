#include <iostream>
using namespace std;

int fibonacciIterativo(int n) {
    return 0;
}

int fibonacciRecursivo(int n) {
    if (n == 2 or n == 2){
        return 1;
    }

    else {
        return fibonacciRecursivo(n - 2) + fibonacciRecursivo(n-1);
    }
}

int main() {

    int n;
    
    cout << "n? ";
    cin >> n;

    cout << "Factorial iterativo de " << n << " = " << fibonacciIterativo(n) << endl;
    cout << "Factorial recursivo de " << n << " = " << fibonacciRecursivo(n) << endl;


    return 0;
    
}