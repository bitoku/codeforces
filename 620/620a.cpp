#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll x, y, x2, y2;
    cin >> x >> y;
    cin >> x2 >> y2;
    if (x == x2 || y == y2) {
        cout << max(abs(x2 - x), abs(y2 - y)) << endl;
    } else if (x2 > x && y2 > y) {
        ll t = min(x2 - x, y2 - y);
        x += t;
        y += t;
        cout << t + max(x2 - x, y2 - y) << endl;
    } else if (x2 > x && y2 < y) {
        ll t = min(x2 - x, y - y2);
        x += t;
        y -= t;
        cout << t + max(x2 - x, y - y2) << endl;
    } else if (x2 < x && y2 > y) {
        ll t = min(x - x2, y2 - y);
        x -= t;
        y += t;
        cout << t + max(x - x2, y2- y) << endl;
    } else if (x2 < x && y2 < y) {
        ll t = min(x - x2, y - y2);
        x -= t;
        y -= t;
        cout << t + max(x - x2, y - y2) << endl;
    }
}