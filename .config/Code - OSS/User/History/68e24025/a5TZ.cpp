#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < 'a') c++;
    }

    if (c > s.size() - c) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'a') s[i] = s[i] - 'a' + 'A';
            
            cout << s[i];
        }
        cout << endl;
    } else {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < 'a') s[i] = s[i] - 'A' + 'a';
            
            cout << s[i];
        }
        cout << endl;
    }
    

    return 0;
}