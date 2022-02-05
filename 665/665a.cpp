#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    string time;
    cin >> time;
    string t;
    int h, m;
    for (char c : time) {
        if (c == ':') {
            h = stoi(t);
            t.clear();
        } else {
            t.push_back(c);
        }
    }
    m = stoi(t);
    m += h * 60;
    int result = 0;
    for (int i = 300; i <= 23 * 60 + 59; i += b) {
        if (m < i + tb && i < m + ta) result++;
    }
    cout << result << endl;
}