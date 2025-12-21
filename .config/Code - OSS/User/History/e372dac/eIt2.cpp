#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    int r += x / 5;

    if (x % 5 == 0) cout << r << endl;
    else cout << r+1 << endl;

    return 0;
}