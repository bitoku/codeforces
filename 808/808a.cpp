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
    int d = 0;
    ll k = n;
    while (k >= 10) {
        d++;
        k /= 10;
    }
    k++;
    for (int i = 0; i < d; ++i) {
        k *= 10;
    }
    cout << k - n << endl;
}