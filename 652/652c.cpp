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
    vector<int> p(n);
    vector<int> pi(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pi[p[i]] = i;
    }
    vector<vector<int>> foe(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        foe[pi[a]].push_back(pi[b]);
        foe[pi[b]].push_back(pi[a]);
    }
    for (int i = 0; i < n; ++i) {
        sort(foe[i].begin(), foe[i].end());
    }
    ll result = 0;
    int l = 0;
    multiset<int> deny;
    for (int r = 0; r < n; ++r) {
        while (deny.find(r) != deny.end()) {
            for (const int x: foe[l]) {
                auto it = deny.find(x);
                deny.erase(it);
            }
            l++;
        }
        result += r - l + 1;
        for (const int x: foe[r]) {
            deny.insert(x);
        }
    }
    cout << result << endl;
}