#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
    while (y) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int gcd_list(const vector<int>& a) {
    int res = a[0];
    for (int i = 1; i < a.size(); ++i) {
        res = gcd(res, a[i]);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        bool found = false;
        for (int i = 1; i < n; ++i) {
            vector<int> b(a.begin(), a.begin() + i);
            vector<int> c(a.begin() + i, a.end());

            if (!b.empty() && !c.empty() && gcd_list(b) != gcd_list(c)) {
                cout << "YES" << endl;
                for (int j = 0; j < n; ++j) {
                    if (j < i) cout << 1 << " ";
                    else cout << 2 << " ";
                }
                cout << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
