#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    a = string(1000000 - a.size(), '0') + a;
    b = string(1000000 - b.size(), '0') + b;
    if (a < b) {
        cout << '<' << '\n';
    } else if (a > b) {
        cout << '>' << '\n';
    } else {
        cout << '=' << '\n';
    }
}