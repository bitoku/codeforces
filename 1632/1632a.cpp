#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.find("11") != string::npos) {
            cout << "NO" << '\n';
        } else if (s.find("00") != string::npos) {
            cout << "NO" << '\n';
        } else if (s.find("101") != string::npos) {
            cout << "NO" << '\n';
        } else if (s.find("010") != string::npos) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}