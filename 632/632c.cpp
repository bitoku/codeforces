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
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [](string& s, string& t) {
        return s + t < t + s;
    });
    for (int i = 0; i < n; ++i) {
        cout << s[i];
    }
    cout << endl;
}