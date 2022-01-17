#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


void dfs(vector<vector<int>>& edge, vector<int>& status, vector<int>& result, int cur, set<int>& multi, set<int>& infinite) {
    status[cur] = 1;
    if (result[cur] == 0) result[cur] = 1;
    for (auto x: edge[cur]) {
        if (status[x] == 1) infinite.insert(x);
        if (status[x] == 2) multi.insert(x);
        if (status[x] == 0) dfs(edge, status, result, x, multi, infinite);
    }
    status[cur] = 2;
}

void dfs2(vector<vector<int>>& edge, vector<bool>& done, vector<int>& result, int cur, int stat) {
    done[cur] = true;
    result[cur] = stat;
    for (auto x: edge[cur]) {
        if (done[x]) continue;
        dfs2(edge, done, result, x, stat);
    }
}

int main() {
    ll t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n, m;
        cin >> n >> m;
        vector<vector<int>> edge(n);
        vector<int> result(n);
        vector<int> status(n);
        set<int> multi, infinite;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            edge[a].push_back(b);
        }
        dfs(edge, status, result, 0, multi, infinite);
        vector<bool> done(n);
        for (auto i: infinite) {
            if (done[i]) continue;
            dfs2(edge, done, result, i, -1);
        }
        for (auto i: multi) {
            if (done[i]) continue;
            dfs2(edge, done, result, i, 2);
        }
        cout << result[0];
        for (int i = 1; i < n; ++i) {
            cout << ' ' << result[i];
        }
        cout << endl;
    }
}