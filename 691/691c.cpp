#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        // remove leading zeros
        if (s[i] == '0') continue;
        s = s.substr(i, s.size() - i);
        break;
    }
    int b = INT_MAX;
    string a;
    if (s[0] == '.') {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') continue;
            b = -i;
            a = s.substr(i, s.size() - i);
            break;
        }
        if (b == INT_MAX) {
            b = 0;
            a = "0";
        }
    } else {
        for (int i = 0; i < s.size(); ++i) {
            // get integer part
            if (s[i] != '.') continue;

            b = i - 1;
            a = s.substr(0, i);
            a += s.substr(i+1, s.size() - i - 1);
            break;
        }
        if (b == INT_MAX) {
            b = s.size() - 1;
            a = s.substr(0, s.size());
        }
    }
    a.insert(1, ".");
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] == '0') continue;
        a = a.substr(0, i+1);
        break;
    }
    if (a.back() == '.') {
        a.pop_back();
    }
    if (b == 0) {
        cout << a << endl;
    } else {
        cout << a << 'E' << b << endl;
    }
}