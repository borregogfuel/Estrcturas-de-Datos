#include <iostream>
using namespace std;

const int MAX = 100;

class Lista{

    private:
        int data[MAX];
        int size;

    public:
        Lista(){
            size = 0;
        }

        void insert(int valor){
            if (size < MAX){
                data[size] = valor;
                size++;
            }

            else{
                cout << "La lista esta llena\n" << endl;
            }
        }

        void erase(){
            if (size > 0) {
                cout << data[size - 1];
                size--;
            }
        }

        int getData(int pos) const{

            return data[pos];
        }

        int getSize() {
            return size;
        }

        void print(){
            for (int i = 0; i < size; i++){
                cout << "[" << i << "] - " << data[i] << endl;
            }
        }
};

int main() {

    Lista mylist;

    mylist.insert(154);
    mylist.insert(587);
    mylist.insert(874);

    cout << "Cantidad de elementos: " << mylist.getSize() << endl;
    cout << "\n---Lista actual---\n";
    mylist.print();

    cout << "Elimina el elemento: ";
    mylist.erase();

    cout << "\n---Lista despues del erase---\n";
    mylist.print();

    cout << "Primer elemento: " << mylist.getData(0);

    return 0;

}