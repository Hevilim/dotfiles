#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if ((a + b + c) % 3 == 0) {
            int m = (a + b + c) / 3;
            c -= m;
            b = b - m + c;
            a = a - m + c;

            if (c == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
        else cout << "NO" << endl;
    }

    return 0;
}