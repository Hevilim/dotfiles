#include <iostream>

using namespace std;

int main() {
    int x, r = 0;
    cin >> x;

    r += x / 5;
    
    if (x % 5 == 0) cout << r << endl;
    else cout << ++r << endl;

    return 0;
}