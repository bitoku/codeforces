#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    ll x;
    for (x = 1; x < 20000000; ++x) {
        if (2 * n <= x * (x + 1)) {
            cout << n - x * (x - 1) / 2 << endl;
            return 0;
        }
    }
}