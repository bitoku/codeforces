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
    int t = 0;
    if (s[0] == 'a' || s[0] == 'h') {
        if (s[1] == '1' || s[1] == '8') {
            t = 3;
        } else {
            t = 5;
        }
    } else {
        if (s[1] == '1' || s[1] == '8') {
            t = 5;
        } else {
            t = 8;
        }
    }
    cout << t << endl;
}