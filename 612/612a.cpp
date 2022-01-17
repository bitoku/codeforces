#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    for (int i = 0; p * i <= n; ++i) {
        if ((n - p * i) % q == 0) {
            int j = (n - p * i) / q;
            cout << i + j << endl;
            for (int k = 0; k < i; ++k) {
                cout << s.substr(k * p, p) << endl;
            }
            for (int k = 0; k < j; ++k) {
                cout << s.substr(p * i + k * q, q) << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
}