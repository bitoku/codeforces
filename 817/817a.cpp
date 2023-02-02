#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll x1, x2, y1, y2, a, b;
    cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
    if ((x2-x1) % a == 0 && (y2-y1) % b == 0 && abs(x2-x1) / a % 2 == abs(y2-y1) / b % 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}