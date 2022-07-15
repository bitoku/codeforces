#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> p(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        p[a].push_back(b);
        p[b].push_back(a);
    }

    vector<bool> done(n);
    vector<int> result = v;

    for (int i = 0; i < n; ++i) {
        if (done[i]) continue;
        done[i] = true;
        deque<int> d;
        vector<int> perm, pos;
        d.push_back(i);
        while (!d.empty()) {
            int x = d.front(); d.pop_front();
            perm.push_back(x);
            pos.push_back(v[x]);
            for (auto y: p[x]) {
                if (done[y]) continue;
                done[y] = true;
                d.push_back(y);
            }
        }
        sort(perm.begin(), perm.end());
        sort(pos.begin(), pos.end(), greater());
        for (int j = 0; j < perm.size(); ++j) {
            result[perm[j]] = pos[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}