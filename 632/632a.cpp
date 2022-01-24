#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, p;
    cin >> n >> p;
    ll result = 0;
    ll apple = 0;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "half") x[i] = 1;
        else x[i] = 2;
    }
    reverse(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        if (x[i] == 1) {
            result += apple * p;
            apple *= 2;
        } else {
            result += apple * p + p / 2;
            apple = apple * 2 + 1;
        }
    }
    cout << result << endl;
}