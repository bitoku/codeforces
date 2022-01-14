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

void fill(int r, int c, vector<string>& s, vector<vector<int>>& d, int cnt) {
    d[r][c] = cnt;
    if (r + 1 < n && s[r+1][c] == '.' && d[r+1][c] == 0) fill(r+1, c, s, d, cnt);
    if (r - 1 >= 0 && s[r-1][c] == '.' && d[r-1][c] == 0) fill(r-1, c, s, d, cnt);
    if (c + 1 < m && s[r][c+1] == '.' && d[r][c+1] == 0) fill(r, c+1, s, d, cnt);
    if (c - 1 >= 0 && s[r][c-1] == '.' && d[r][c-1] == 0) fill(r, c-1, s, d, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> d(n, vector<int>(m));
    vector<vector<int>> idx(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] || s[i][j] == '*') continue;
            int cnt = 0;
            walk(i, j, s, idx, cnt, i * m + j + 1);
            fill(i, j, s, d, cnt);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                cout << '.';
                continue;
            }
            int result = 0;
            int right = 0, left = 0, up = 0;
            if (i + 1 < n) {
                result += d[i+1][j];
                right = idx[i+1][j];
            }
            if (i - 1 >= 0 && idx[i-1][j] != right) {
                result += d[i-1][j];
                left = idx[i-1][j];
            }
            if (j + 1 < m && idx[i][j+1] && idx[i][j+1] != right && idx[i][j+1] != left) {
                result += d[i][j+1];
                up = idx[i][j+1];
            }
            if (j - 1 >= 0 && idx[i][j-1] != right && idx[i][j-1] != left && idx[i][j-1] != up) {
                result += d[i][j-1];
            }
            cout << (result + 1) % 10;
        }
        cout << '\n';
    }
}