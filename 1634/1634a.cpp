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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool palindrome = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                palindrome = false;
            }
        }
        if (palindrome || k == 0) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
        // aab
        // aabbaa baaaab
        // aabbaaaabbaa baaaabbaaaab
    }
}