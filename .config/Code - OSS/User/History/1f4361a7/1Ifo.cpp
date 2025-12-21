#include <iostream>

using namespace std;

int main() {
    string s; cin >> s;

    int c = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) c++;
        else c = 0;

        if (c == 6) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}