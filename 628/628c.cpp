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
    string s;
    cin >> s;
    int mx = 0;
    string t = s;
    for (int i = 0; i < n; ++i) {
        if (k == 0) continue;
        if (s[i] - 'a' > 25 - s[i] + 'a') {
            t[i] = s[i] - min(k, s[i] - 'a');
            k -= min(k, s[i] - 'a');
        } else {
            t[i] = s[i] + min(k, 25 - s[i] + 'a');
            k -= min(k, 25 - s[i] + 'a');
        }
    }
    if (k == 0) {
        cout << t << endl;
    } else {
        cout << -1 << endl;
    }
}