#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
    while(y) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int gcd_list(int * a, int n) {
    int res = a[0];
    for (int i = 1; i < n; ++i) {
        res = gcd(res, a[i]);
    }
    return res;
}

int main() {
    int t; cin >> t;

    for (int i = 0; i < t; ++i) {
        int n; cin >> n;

        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b, c;
        for (int i = 0; i < n; ++i) {
            b.push_back(a[i]);
            for (int j = i; j < n )
        }
    }

    return 0;
}
