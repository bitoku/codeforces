#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int v[31][31][51];

int f(int a, int b, int c) {
    if (v[a][b][c] || a*b == c || c == 0) return v[a][b][c];
    int ret = 1e9;
    for (int z = 0; z <= c; ++z) {
        for (int y = 1; y < b; ++y) {
            ret = min(ret, f(a, b-y, c-z) + f(a, y, z) + a * a);
        }
        for (int y = 1; y < a; ++y) {
            ret = min(ret, f(a-y, b, c-z) + f(y, b, z) + b * b);
        }
    }
    v[a][b][c] = ret;
    return ret;
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << f(a, b, c) << endl;
    }
}