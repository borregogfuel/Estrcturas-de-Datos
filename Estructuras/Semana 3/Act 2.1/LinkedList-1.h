// Guillermo Gil Palomar A01199519

#ifndef LINKEDLIST_1_H
#define LINKEDLIST_1_H

template <class T>
class LinkedList {

    private:
        struct Node {
            T data;
            Node* next;
        };

        Node* head;
        int size;

    public:
        LinkedList(){
            head = nullptr;
            size = 0;
        }

        ~LinkedList(){
            deleteAll();
        }

        /*
            Descripcion: mete un nodo nuevo al inicio de la lista.
            Entrada: el dato que se quiere agregar.
            Salida: nada.
            Precondicion: la lista y el dato deben existir.
            Postcondicion: el dato nuevo queda como primer elemento.
            Complejidad: O(1)
        */
        void addFirst(T data){
            head = new Node{data, head};
            size++;
        }

        /*
            Descripcion: camina hasta el ultimo nodo y le pega uno nuevo.
            Entrada: el dato que se quiere agregar.
            Salida: nada.
            Precondicion: la lista y el dato deben existir.
            Postcondicion: el dato nuevo queda como ultimo elemento.
            Complejidad: O(n), porque hay que llegar hasta el final.
        */
        void addLast(T data){

            // si esta vacia es lo mismo que agregar al inicio
            if (head == nullptr){
                addFirst(data);
                return;
            }

            Node* actual = head;

            while (actual->next != nullptr){
                actual = actual->next;
            }

            actual->next = new Node{data, nullptr};
            size++;
        }

        /*
            Descripcion: mete un dato nuevo en la posicion que le pidan.
            Entrada: el dato y la posicion donde va.
            Salida: true si lo pudo meter, false si la posicion se pasa del tamano.
            Precondicion: pos no debe ser negativa.
            Postcondicion: si la posicion era buena, la lista tiene un nodo mas.
            Complejidad: O(n)
        */
        bool add(T data, int pos){

            if (pos > size){
                return false;
            }

            if (pos == 0){
                addFirst(data);
                return true;
            }

            // camino hasta el nodo que queda justo antes de pos
            Node* actual = head;

            for (int i = 0; i < pos - 1; i++){
                actual = actual->next;
            }

            actual->next = new Node{data, actual->next};
            size++;
            return true;
        }

        /*
            Descripcion: quita el primer nodo y libera su memoria.
            Entrada: nada.
            Salida: nada.
            Precondicion: la lista debe existir; si esta vacia no hace nada.
            Postcondicion: el segundo nodo pasa a ser el primero.
            Complejidad: O(1)
        */
        void deleteFirst(){

            if (head == nullptr){
                return;
            }

            Node* aux = head;
            head = head->next;
            delete aux;
            size--;
        }

        /*
            Descripcion: quita el ultimo nodo de la lista.
            Entrada: nada.
            Salida: nada.
            Precondicion: la lista debe existir; si esta vacia no hace nada.
            Postcondicion: el penultimo nodo pasa a ser el ultimo.
            Complejidad: O(n), porque hay que buscar el penultimo.
        */
        void deleteLast(){

            // con 0 o 1 nodos es lo mismo que borrar el primero
            if (size <= 1){
                deleteFirst();
                return;
            }

            // busco el penultimo para cortar ahi
            Node* actual = head;

            while (actual->next->next != nullptr){
                actual = actual->next;
            }

            delete actual->next;
            actual->next = nullptr;
            size--;
        }

        /*
            Descripcion: borra el nodo que esta en la posicion pos.
            Entrada: la posicion que se va a borrar.
            Salida: nada.
            Precondicion: pos debe estar entre 0 y size - 1.
            Postcondicion: la lista tiene un nodo menos y los de atras se recorren un lugar.
            Complejidad: O(n)
        */
        void del(int pos){

            if (pos == 0){
                deleteFirst();
                return;
            }

            Node* actual = head;

            for (int i = 0; i < pos - 1; i++){
                actual = actual->next;
            }

            Node* aux = actual->next;
            actual->next = aux->next;
            delete aux;
            size--;
        }

        /*
            Descripcion: dice si la lista no tiene nodos.
            Entrada: nada.
            Salida: true si esta vacia, false si tiene algo.
            Precondicion: la lista debe existir.
            Postcondicion: ninguna, no cambia nada.
            Complejidad: O(1)
        */
        bool isEmpty(){
            return size == 0;
        }

        /*
            Descripcion: borra todos los nodos, uno por uno desde el inicio.
            Entrada: nada.
            Salida: cuantos nodos borro.
            Precondicion: la lista debe existir.
            Postcondicion: la lista queda vacia.
            Complejidad: O(n)
        */
        int deleteAll(){

            int borrados = size;

            while (head != nullptr){
                deleteFirst();
            }

            return borrados;
        }

        /*
            Descripcion: cambia el dato del nodo en pos por uno nuevo.
            Entrada: el dato nuevo y la posicion.
            Salida: el dato que habia antes en esa posicion.
            Precondicion: pos debe estar entre 0 y size - 1.
            Postcondicion: el nodo en pos guarda el dato nuevo.
            Complejidad: O(n)
        */
        T set(T data, int pos){

            Node* actual = head;

            for (int i = 0; i < pos; i++){
                actual = actual->next;
            }

            T anterior = actual->data;
            actual->data = data;
            return anterior;
        }

        /*
            Descripcion: regresa el dato que esta en pos.
            Entrada: la posicion.
            Salida: el dato de esa posicion.
            Precondicion: pos debe estar entre 0 y size - 1.
            Postcondicion: ninguna, la lista no cambia.
            Complejidad: O(n)
        */
        T get(int pos){

            Node* actual = head;

            for (int i = 0; i < pos; i++){
                actual = actual->next;
            }

            return actual->data;
        }

        /*
            Descripcion: intercambia los datos de dos posiciones; los nodos se quedan donde estan.
            Entrada: las dos posiciones.
            Salida: true si las dos posiciones existen y se hizo el cambio, false si no.
            Precondicion: ninguna, si alguna posicion no existe solo regresa false.
            Postcondicion: los datos de pos1 y pos2 quedan intercambiados.
            Complejidad: O(n)
        */
        bool change(int pos1, int pos2){

            if (pos1 < 0 || pos1 >= size || pos2 < 0 || pos2 >= size){
                return false;
            }

            Node* uno = head;
            Node* dos = head;

            for (int i = 0; i < pos1; i++){
                uno = uno->next;
            }

            for (int i = 0; i < pos2; i++){
                dos = dos->next;
            }

            swap(uno->data, dos->data);
            return true;
        }

        /*
            Descripcion: regresa cuantos nodos tiene la lista.
            Entrada: nada.
            Salida: el numero de nodos.
            Precondicion: la lista debe existir.
            Postcondicion: ninguna.
            Complejidad: O(1), porque size se actualiza cada vez que se agrega o borra.
        */
        int getSize(){
            return size;
        }

        /*
            Descripcion: imprime los datos en una sola linea, separados por un espacio.
            Entrada: nada.
            Salida: nada, solo imprime en pantalla.
            Precondicion: la lista debe existir.
            Postcondicion: ninguna.
            Complejidad: O(n)
        */
        void print(){

            Node* actual = head;

            while (actual != nullptr){

                cout << actual->data;

                if (actual->next != nullptr){
                    cout << " ";
                }

                actual = actual->next;
            }

            cout << endl;
        }

        /*
            Descripcion: voltea la lista, el ultimo queda primero y asi.
            Entrada: nada.
            Salida: nada.
            Precondicion: la lista debe existir, puede estar vacia.
            Postcondicion: los datos quedan al reves de como llegaron.
            Complejidad: O(n), con una sola pasada.
        */
        void reverse(){

            Node* anterior = nullptr;
            Node* actual = head;

            // volteo cada next para que apunte al nodo de atras
            while (actual != nullptr){
                Node* siguiente = actual->next;
                actual->next = anterior;
                anterior = actual;
                actual = siguiente;
            }

            head = anterior;
        }

        /*
            Descripcion: recorre la lista n lugares en forma circular. Con n = 2 el de
                         la posicion 0 se va a la 2; con n = -1 el de la 0 se va al final.
            Entrada: n, cuantos lugares se recorre (puede ser negativo).
            Salida: nada.
            Precondicion: la lista debe existir, puede estar vacia.
            Postcondicion: la lista queda recorrida n lugares.
            Complejidad: O(n)
        */
        void shift(int n){

            if (size == 0){
                return;
            }

            // con el modulo k queda entre 0 y size - 1, aunque n venga negativo
            int k = ((n % size) + size) % size;

            if (k == 0){
                return;
            }

            // el nodo en size - k - 1 va a ser el nuevo ultimo
            Node* nuevaCola = head;

            for (int i = 0; i < size - k - 1; i++){
                nuevaCola = nuevaCola->next;
            }

            Node* cola = nuevaCola;

            while (cola->next != nullptr){
                cola = cola->next;
            }

            // pego el final con el inicio y corto despues del nuevo ultimo
            cola->next = head;
            head = nuevaCola->next;
            nuevaCola->next = nullptr;
        }

        /*
            Descripcion: compara dos listas; son iguales si miden lo mismo y tienen
                         los mismos datos en el mismo orden.
            Entrada: la otra lista.
            Salida: true si son iguales, false si no.
            Precondicion: las dos listas deben existir.
            Postcondicion: ninguna, no modifica ninguna de las dos.
            Complejidad: O(n)
        */
        bool operator==(const LinkedList<T> &otra){

            // si no miden lo mismo ni hace falta recorrerlas
            if (size != otra.size){
                return false;
            }

            Node* a = head;
            Node* b = otra.head;

            while (a != nullptr){

                if (a->data != b->data){
                    return false;
                }

                a = a->next;
                b = b->next;
            }

            return true;
        }
};

#endif
