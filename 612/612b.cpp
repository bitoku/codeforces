#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        v[i] = {c, i};
    }
    sort(v.begin(), v.end());
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        result += abs(v[i].second - v[i-1].second);
    }
    cout << result << endl;
}