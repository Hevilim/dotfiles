#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int c = 0;
    while (n) {
        cout << n << endl;
        int d = n % 10;
        if (d == 4 || d == 7) c++;
        cout << c << " " << endl;
        n /= 10;
    }

    if (c == 4 || c == 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}