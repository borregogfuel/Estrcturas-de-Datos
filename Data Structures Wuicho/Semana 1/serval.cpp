#include <bits/stdc++.h>
using namespace std;

int main() {

    int routes, time, r, t;
    int bestt = INT_MAX;
    int ans = 0;

    cin >> routes >> time;

    for (int i = 1; i <= routes; i++){
        cin >> r >> t;
        while (r < t){
            routes += t;
        }

        if (bestt > r){
            bestt = r;
            ans = i;
        }
    }

    cout << ans;


}