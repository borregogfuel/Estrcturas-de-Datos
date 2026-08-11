#include <bits/stdc++.h>
using namespace std;

int main(){

    int i, f;
    cin >> i >> f;

    int counter = 0;

    for (int x = i; x <= f; x += 15){
        if (x % 3 and x % 5 == 0){
            counter++;
        }
    }

    cout << counter;
}