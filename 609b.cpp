#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    ll mp[10] = {};
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        mp[--a]++;
    }
    ll result = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = i+1; j < 10; ++j) {
            result += mp[i] * mp[j];
        }
    }
    cout << result << endl;
}