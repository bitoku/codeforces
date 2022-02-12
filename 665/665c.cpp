#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

char next(char c) {
    return (c - 'a' + 1) % 26 + 'a';
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    s = "!" + s + "!";
    int l = 0;
    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] != s[i+1]) {
            if ((i - l) % 2 == 0) {
                char c = next(s[i]);
                if (c == s[l]) c = next(c);
                for (int j = 1; l+j <= i; j+=2) {
                    s[l+j] = c;
                }
            } else if ((i - l) % 2 == 1) {
                char c = next(s[i]);
                for (int j = 2; l+j <= i; j += 2) {
                    s[l+j] = c;
                }
            }
            l = i;
        }
    }
    cout << s.substr(1, s.size()-2) << endl;
}