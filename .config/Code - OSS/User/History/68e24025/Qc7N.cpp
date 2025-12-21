#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < 'a') c++;
    }

    if (c < s.size() - c)
        for (int i = 0; i < s.size(); ++i) {
            
        }
    

    return 0;
}