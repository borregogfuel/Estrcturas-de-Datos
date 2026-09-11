#include <iostream>
#include <vector>
using namespace std;

// Guillermo Gil Palomar A01199519

/*
    Descripcion: compara cada numero contra todos los que siguen y los cambia si van al reves.
    Entrada: el vector con los n numeros y el contador de comparaciones.
    Salida: nada, el vector queda ordenado.
    Precondicion: el vector debe contener los n numeros.
    Postcondicion: el vector contendra los datos ya ordenados.
    Complejidad: O(n^2)
*/
void ordenaIntercambio(vector<int> &v, long long &comparaciones) {

    for (int i = 0; i < (int)v.size() - 1; i++){
        for (int j = i + 1; j < (int)v.size(); j++){

            comparaciones++;

            if (v[j] < v[i]){
                swap(v[i], v[j]);
            }
        }
    }
}

/*
    Descripcion: compara vecinos por pasadas y va empujando el mayor hasta el final.
    Entrada: el vector con los n numeros y el contador de comparaciones.
    Salida: nada, el vector queda ordenado.
    Precondicion: el vector debe contener los n numeros.
    Postcondicion: el vector contendra los datos ya ordenados.
    Complejidad: O(n^2), pero O(n) si el vector ya venia ordenado.
*/
void ordenaBurbuja(vector<int> &v, long long &comparaciones) {

    int n = v.size();

    for (int i = 0; i < n - 1; i++){

        bool huboCambio = false;

        for (int j = 0; j < n - 1 - i; j++){

            comparaciones++;

            if (v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                huboCambio = true;
            }
        }

        // si nadie se movio en toda la pasada, ya esta ordenado
        if (!huboCambio){
            break;
        }
    }
}

/*
    Descripcion: junta dos mitades que ya estan ordenadas en una sola.
    Entrada: el vector, los indices izq, medio y der, y el contador.
    Salida: nada, el rango [izq, der] queda ordenado.
    Precondicion: las dos mitades ya deben estar ordenadas.
    Postcondicion: cuenta una comparacion por cada dato que acomoda.
    Complejidad: O(n) sobre el tamano del rango.
*/
void merge(vector<int> &v, int izq, int medio, int der, long long &comparaciones) {

    vector<int> temp;
    int i = izq, j = medio + 1;

    while (i <= medio && j <= der){

        comparaciones++;

        if (v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        }

        else {
            temp.push_back(v[j]);
            j++;
        }
    }

    // lo que sobra de una mitad se copia tal cual
    while (i <= medio){
        comparaciones++;
        temp.push_back(v[i]);
        i++;
    }

    while (j <= der){
        comparaciones++;
        temp.push_back(v[j]);
        j++;
    }

    for (int k = 0; k < (int)temp.size(); k++){
        v[izq + k] = temp[k];
    }
}

/*
    Descripcion: parte el rango a la mitad, ordena cada lado y luego los junta.
    Entrada: el vector, los indices izq y der, y el contador.
    Salida: nada, el rango [izq, der] queda ordenado.
    Precondicion: izq y der deben ser indices validos.
    Postcondicion: el caso base es un rango de un solo elemento.
    Complejidad: O(n log n)
*/
void mergeSort(vector<int> &v, int izq, int der, long long &comparaciones) {

    if (izq >= der){
        return;
    }

    int medio = (izq + der) / 2;

    mergeSort(v, izq, medio, comparaciones);
    mergeSort(v, medio + 1, der, comparaciones);
    merge(v, izq, medio, der, comparaciones);
}

/*
    Descripcion: arranca el merge sort sobre todo el vector.
    Entrada: el vector con los n numeros y el contador de comparaciones.
    Salida: nada, el vector queda ordenado.
    Precondicion: el vector debe contener los n numeros.
    Postcondicion: el vector contendra los datos ya ordenados.
    Complejidad: O(n log n)
*/
void ordenaMerge(vector<int> &v, long long &comparaciones) {

    mergeSort(v, 0, (int)v.size() - 1, comparaciones);
}

/*
    Descripcion: revisa el vector uno por uno hasta encontrar el dato.
    Entrada: el vector donde busca, el dato y el contador.
    Salida: el indice donde esta el dato o -1 si no lo encuentra.
    Precondicion: el vector debe contener los n numeros.
    Postcondicion: ninguna, el vector no se modifica.
    Complejidad: O(n)
*/
int busqSecuencial(const vector<int> &v, int dato, long long &comparaciones) {

    for (int i = 0; i < (int)v.size(); i++){

        comparaciones++;

        if (v[i] == dato){
            return i;
        }
    }

    return -1;
}

/*
    Descripcion: parte el vector a la mitad y se queda con el lado donde puede estar el dato.
    Entrada: el vector ya ordenado, el dato y el contador.
    Salida: el indice donde esta el dato o -1 si no lo encuentra.
    Precondicion: el vector debe estar ordenado de forma ascendente.
    Postcondicion: ninguna, el vector no se modifica.
    Complejidad: O(log n)
*/
int busqBinaria(const vector<int> &v, int dato, long long &comparaciones) {

    int izq = 0, der = (int)v.size() - 1;

    while (izq <= der){

        comparaciones++;
        int medio = (izq + der) / 2;

        if (v[medio] == dato){
            return medio;
        }

        else if (v[medio] < dato){
            izq = medio + 1;
        }

        else {
            der = medio - 1;
        }
    }

    return -1;
}

int main() {

    int n;
    cin >> n;

    vector<int> original(n);

    for (int i = 0; i < n; i++){
        cin >> original[i];
    }

    // cada metodo ordena su propia copia para contar sus comparaciones por separado
    vector<int> porIntercambio = original;
    vector<int> porBurbuja = original;
    vector<int> ordenado = original;

    long long compIntercambio = 0, compBurbuja = 0, compMerge = 0;

    ordenaIntercambio(porIntercambio, compIntercambio);
    ordenaBurbuja(porBurbuja, compBurbuja);
    ordenaMerge(ordenado, compMerge);

    cout << compIntercambio << " " << compBurbuja << " " << compMerge << "\n";

    int b, dato;
    cin >> b;

    for (int i = 0; i < b; i++){

        cin >> dato;

        long long compSec = 0, compBin = 0;

        // la secuencial busca en el arreglo original y la binaria en el ordenado
        int posSec = busqSecuencial(original, dato, compSec);
        int posBin = busqBinaria(ordenado, dato, compBin);

        cout << posSec << " " << compSec << " " << posBin << " " << compBin << "\n";
    }

    return 0;
}
