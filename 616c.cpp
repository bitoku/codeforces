#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int n, m;

int walk(int r, int c, vector<string>& s, vector<vector<int>>& idx, int& cnt, int k) {
    idx[r][c] = k;
    ++cnt;
    if (r + 1 < n && s[r+1][c] == '.' && idx[r+1][c] == 0) walk(r+1, c, s, idx, cnt, k);
    if (r - 1 >= 0 && s[r-1][c] == '.' && idx[r-1][c] == 0) walk(r-1, c, s, idx, cnt, k);
    if (c + 1 < m && s[r][c+1] == '.' && idx[r][c+1] == 0) walk(r, c+1, s, idx, cnt, k);
    if (c - 1 >= 0 && s[r][c-1] == '.' && idx[r][c-1] == 0) walk(r, c-1, s, idx, cnt, k);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> idx(n, vector<int>(m));
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (idx[i][j] || s[i][j] == '*') continue;
            int cnt = 0;
            int k = i * m + j + 1;
            walk(i, j, s, idx, cnt, k);
            mp[k] = cnt;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                cout << '.';
                continue;
            }
            unordered_set<int> x;
            if (i + 1 < n) x.insert(idx[i+1][j]);
            if (i - 1 >= 0) x.insert(idx[i-1][j]);
            if (j + 1 < m) x.insert(idx[i][j+1]);
            if (j - 1 >= 0) x.insert(idx[i][j-1]);

            int result = 0;
            for (auto k: x) {
                result += mp[k];
            }
            cout << (result + 1) % 10;
        }
        cout << '\n';
    }
}