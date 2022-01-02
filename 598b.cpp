#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

string shift(string& s, int l, int r, int k) {
    int len = r - l + 1;
    k %= len;
    string t;
    for (int i = 0; i < s.size(); ++i) {
        if (l <= i && i <= r) {
            t.push_back(s[l + (i - l + len - k) % len]);
        } else {
            t.push_back(s[i]);
        }
    }
    return t;
}

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        s = shift(s, l, r, k);
    }
    cout << s << endl;
}