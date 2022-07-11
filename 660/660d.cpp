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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            auto x = v[i].first - v[j].first;
            auto y = v[i].second - v[j].second;
            if (x < 0 || (x == 0 && y < 0)) {
                x = -x;
                y = -y;
            }
            mp[make_pair(x, y)]++;
        }
    }
    ll result = 0;
    for (auto [p, k]: mp) {
        result += k * (k - 1) / 2;
    }
    cout << result / 2 << endl;
}