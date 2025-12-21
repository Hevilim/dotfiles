#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int c;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < 'a') c++;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (c > s.size() - c) {
            
        }
    }
 

    return 0;
}