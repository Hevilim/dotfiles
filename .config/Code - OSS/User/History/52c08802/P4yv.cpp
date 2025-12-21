#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] < 'a') s[i] = s[i] - 'A' + 'a';

        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i')
            continue;

        cout << '.' << s[i];
    }
    cout << endl;

    return 0;
}