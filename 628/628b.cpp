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
    ll result = 0;
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] - '0') % 4 == 0) result++;
    }
    for (int i = 0; i < s.size() - 1; ++i) {
        if (((s[i] - '0') * 10 + (s[i+1] - '0')) % 4 == 0) {
            result += (i + 1);
        }
    }
    cout << result << endl;
}