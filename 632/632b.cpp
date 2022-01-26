#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    string s;
    cin >> s;
    vector<ll> a(n+1), b(n+1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            a[i+1] = p[i];
        } else {
            b[i+1] = p[i];
        }
        a[i+1] += a[i];
        b[i+1] += b[i];
    }
    ll result = 0;
    for (int i = 0; i < n + 1; ++i) {
        result = max(result, a[n] - a[i] + b[i]);
        result = max(result, a[i] + b[n] - b[i]);
    }
    cout << result << endl;
}