
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct S {
    vector<vector<int>>& v;
    vector<string>& s;
    int cnt;

    void stroll(int r, int c) {
        v[r][c] = 0;

        if (s[r+1][c] == '*') cnt++;
        if (s[r-1][c] == '*') cnt++;
        if (s[r][c+1] == '*') cnt++;
        if (s[r][c-1] == '*') cnt++;

        if (v[r+1][c] == -1 && s[r+1][c] == '.') stroll(r+1, c);
        if (v[r-1][c] == -1 && s[r-1][c] == '.') stroll(r-1, c);
        if (v[r][c+1] == -1 && s[r][c+1] == '.') stroll(r, c+1);
        if (v[r][c-1] == -1 && s[r][c-1] == '.') stroll(r, c-1);
    }

    void fill(int r, int c) {
        v[r][c] = cnt;
        if (v[r+1][c] == 0 && s[r+1][c] == '.') fill(r+1, c);
        if (v[r-1][c] == 0 && s[r-1][c] == '.') fill(r-1, c);
        if (v[r][c+1] == 0 && s[r][c+1] == '.') fill(r, c+1);
        if (v[r][c-1] == 0 && s[r][c-1] == '.') fill(r, c-1);
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<vector<int>> v(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] != -1) continue;
            if (s[i][j] == '*') {
                v[i][j] = 0;
                continue;
            }
            S ss = {v, s, 0};
            ss.stroll(i, j);
            ss.fill(i, j);
        }
    }

    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        cout << v[--r][--c] << endl;
    }
}