#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < 'a') s[i] = s[i] - 'A' + 'a';

        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i')
            continue;

        cout << '.' << s[i];
    }
    cout << endl;

    return 0;
}