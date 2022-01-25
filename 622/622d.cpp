#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < (n+1) / 2; i++) {
        v[i] = 2 * i + 1;
        v[n-1-i] = 2 * i + 1;
    }
    for (int i = 0; i < n / 2; i++) {
        v[n+i] = 2 * i + 2;
        v[2*n-2-i] = 2 * i + 2;
    }
    v[2 * n - 1] = n;
    cout << v[0];
    for (int i = 1; i < 2 * n; ++i) {
        cout << ' ' << v[i];
    }
    cout << endl;
}