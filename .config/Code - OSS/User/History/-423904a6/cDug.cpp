#include <iostream>

using namespace std;

int main() {
    long n; cin >> n;

    int c = 0;
    while (n) {
        int d = n % 10;
        if (d == 4 || d == 7) c++;
        n /= 10;
    }

    if ()
    return 0;
}