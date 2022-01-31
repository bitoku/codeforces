#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;



int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int a, b;
        cin >> a >> b;
        int x = 0;
        for (int k = 1 << 20; k > 0; k >>= 1) {
            if ((a & k) && !(b & k)) {
                x += k;
            }
            if (x > 0 && !(a & k) && (b & k)) {
                x -= k;
            }
        }
        int kk = 0;
        int y = 0;
        for (int k = 1 << 20; k > 0; k >>= 1) {
            if (a & k) {
                y = kk + (b & (kk - 1)) - a;
                break;
            }
            if (b & k) kk = k;
        }
        cout << min(b - a, min(y + 1, x + 1)) << '\n';
    }
}