#include <iostream>

using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;

    int cost = 0;
    for (int i = 1; i <= w; ++i) {
        cost += k * i;
    }

    n -= cost;
    if (n < 0) cout << -1 * n << endl;
     
    return 0;
}