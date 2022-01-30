#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int h1, h2;
    cin >> h1 >> h2;
    int a, b;
    cin >> a >> b;
    h1 += 8 * a;
    if (h1 < h2 && a <= b) {
        cout << -1 << endl;
        return 0;
    }
    if (h1 >= h2) {
        cout << 0 << endl;
        return 0;
    }
    int days = 0;
    while (h1 < h2) {
        h1 -= 12 * b;
        h1 += 12 * a;
        days++;
    }
    cout << days << endl;
}