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
        int n;
        cin >> n;
        int k = 1;
        while (k <= n-1) {
            k <<= 1;
        }
        k >>= 1;
        for (int i = n-1; i >= k; --i) {
            cout << i << ' ';
        }
        for (int i = 0; i < k; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}