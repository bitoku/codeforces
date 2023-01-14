#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int recur(vector<vector<int>>& v, vector<int>& parent, vector<int>& depth, vector<int>& longest, int cur, int par, int d) {
    longest[cur] = 0;
    for (auto x: v[cur]) {
        if (x == par) continue;
        parent[x] = cur;
        depth[x] = d+1;
        longest[cur] = max(longest[cur], 1 + recur(v, parent, depth, longest, x, cur, d+1));
    }
    return longest[cur];
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> v(n);
    vector<int> depth(n);
    vector<int> parent(n);
    vector<int> longest(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    recur(v, parent, depth, longest, 0, -1, 0);
    int k = (depth[x] - 1) / 2;
    for (int i = 0; i < k; ++i) {
        x = parent[x];
    }
    cout << (depth[x] + longest[x]) * 2 << endl;

    // 0 - 1 - 2 - 3 - 4
}