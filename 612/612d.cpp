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
    vector<pair<int, int>> mp;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        mp.emplace_back(2 * a, 1);
        mp.emplace_back(2 * b + 1, -1);
    }
    sort(mp.begin(), mp.end());
    int current = 0;
    for (auto& [s, t]: mp) {
        t += current;
        current = t;
    }
    int l = INT_MIN, r = 0;
    vector<pair<int, int>> result;
    for (auto [s, t]: mp) {
        if (l == INT_MIN && t >= k) {
            l = s;
        } else if (l != INT_MIN && t < k) {
            r = s - 1;
            result.emplace_back(l / 2, r / 2);
            l = INT_MIN;
        }
    }
    cout << result.size() << '\n';
    for (auto [s, t]: result) {
        cout << s << ' ' << t << '\n';
    }
}