#include <iostream>

using namespace std;

int main() {
    int x, r = 0;
    cin >> x;

    r += x / 5;
    cout << x % 5 << endl;
    if (x % 5 == 0) cout << "f" << endl;
    else cout << r+1 << endl;

    return 0;
}