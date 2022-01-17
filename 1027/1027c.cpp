#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        ll result = 0;
        vector<int> len;
        char before = '0';
        len.push_back(0);
        for (char c : s) {
            if (c == before) {
                len.back() += 1;
            } else {
                len.push_back(1);
            }
            before = c;
        }
        if (len.size() == 1) {
            cout << len[0] * a + (len[0] + 1) * b << endl;
            continue;
        }
        result += len[0] * a + len[0] * b + a;
        for (int i = 1; i < len.size()-1; ++i) {
            if (i % 2 == 1) {
                result += len[i] * a + (len[i] + 1) * 2 * b;
                continue;
            }
            if (len[i] >= 2) {
                result += min(
                        len[i] * a + (len[i] - 1) * b + 2 * a,
                        len[i] * a + (len[i] - 1) * 2 * b);
            } else {
                result += len[i] * a + (len[i] - 1) * 2 * b;
            }
        }
        result += len.back() * a + len.back() * b + a;
        cout << result << endl;
    }
}