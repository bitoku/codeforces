#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(1000001);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0;
    int k = 0;
    pair<int, int> range;
    for (int r = 0; r < n; ++r) {
        if (b[a[r]] == 0) k++;
        b[a[r]]++;
        while (k > m) {
            b[a[l]]--;
            if (b[a[l]] == 0) k--;
            l++;
        }
        if (r - l > range.second - range.first) {
            range = {l, r};
        }
    }
    cout << range.first + 1 << ' ' << range.second + 1 << endl;
}