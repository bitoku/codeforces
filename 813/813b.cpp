#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    llu x, y, l, r;
    cin >> x >> y >> l >> r;
    llu xx = 1;
    set<llu> s;
    while (xx <= r) {
        llu yy = 1;
        while (xx + yy <= r) {
            if (l <= xx + yy) {
                s.insert(xx + yy);
            }
            if (r / y < yy) break;
            yy *= y;
        }
        if (r / x < xx) break;
        xx *= x;
    }
    if (s.empty()) {
        cout << r - l + 1 << endl;
        return 0;
    }
    llu left = l;
    llu result = 0;
    for (auto k: s) {
        result = max(result, k - left);
        left = k + 1;
    }
    result = max(result, r - left + 1);
    cout << result << endl;
}