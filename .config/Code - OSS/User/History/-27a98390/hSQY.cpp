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

int gcd_list(vector<int> a) {
    int res = a[0];
    for (int i = 1; i < a.size(); ++i) {
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

        vector<int> b;
        for (int i = 0; i < n; ++i) {
            b.push_back(a[i]);
            a[i] = 1;

            vector<int> c;
            for (int j = i; j < n; ++j) {
                c.push_back(a[j]);
                a[j] = 2;
            }

            if (gcd_list(b) != gcd_list(c)) {
                cout << "YES" << endl;
                for (int k = 0; k < n; ++k) {
                    cout << a[k];
                }
                cout << endl;
            }

        }
    }

    return 0;
}
