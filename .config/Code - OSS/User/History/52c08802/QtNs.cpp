#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] > 'a') s[i] = s[i] - 'A' + 'a'
    }

    return 0;
}