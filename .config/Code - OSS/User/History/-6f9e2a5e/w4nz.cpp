#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int gcd_list(int * a) {

    
}

int main() {
    int t; cin >> t;

    for (int i = 0; i < t; ++i) {
        int n; cin >> n;

        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }




    }

    return 0;
}