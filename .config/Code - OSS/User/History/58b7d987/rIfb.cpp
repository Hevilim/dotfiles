#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int curr; cin >> curr;
            if (j == 0) x += curr;
            else if (j == 1) y += curr;
            else if (j == 2) z += curr;
        }
    }

    if (!x && !y && !z) cout << "YES" << endl;

    return 0;
}