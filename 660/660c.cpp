#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0;
    int x = 0;
    pair<int, int> p = {-1, -1};
    for (int r = 0; r < n; ++r) {
        if (a[r] == 0) x++;
        while (x > k) {
            if (a[l] == 0) x--;
            l++;
        }
        if (r - l + 1 >= p.second - p.first + 1) {
            p = {l, r};
        }
    }
    if (p.first == -1 && p.second == -1) {
        cout << 0 << endl;
    } else {
        cout << p.second - p.first + 1 << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (p.first <= i && i <= p.second) {
            cout << 1 << ' ';
        } else {
            cout << a[i] << ' ';
        }
    }
    cout << endl;

}