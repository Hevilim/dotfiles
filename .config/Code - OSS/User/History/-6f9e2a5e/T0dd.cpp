#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd_list(int * nums) {
    int res = nums[0];
    for (int i = 1; i < )

}

int main() {
    int t; cin >> t;

    for (int i = 0; i < t; ++i) {
        int n; cin >> n;

        int nums[n];
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }




    }

    return 0;
}