#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += (a[i] + 1) / 2;
    }
    int x = w - s;
    if (x < 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return a[x] > a[y];
    });
    vector<int> result(n);
    for (auto i: idx) {
        int l = (a[i] + 1) / 2;
        int e = min(a[i] - l, x);
        result[i] = l + e;
        x -= e;
    }
    for (auto k: result) {
        cout << k << ' ';
    }
    cout << endl;
}