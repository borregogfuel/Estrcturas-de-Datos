#include <bits/stdc++.h>
using namespace std;

int main () {

    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;


    if (x > a){
        cout << "NO";
    }

    a -= x;

    if (y > a+b){
        cout << "NO";
    }

    a = (a + b - y);

    if ( z > a + c){
        cout << "NO";
    }

    cout << "YES";


}