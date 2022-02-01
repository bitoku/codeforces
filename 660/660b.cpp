#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    deque<int> a, b, c, d;
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) {
            if (i < 2 * n) {
                a.push_back(i+1);
            } else {
                b.push_back(i+1);
            }
        } else {
            if (i < 2 * n) {
                d.push_back(i+1);
            } else {
                c.push_back(i+1);
            }
        }
    }
    while (!a.empty() || !b.empty() || !c.empty() || !d.empty()) {
        if (!b.empty()) {
            cout << b.front() << ' ';
            b.pop_front();
        }
        if (!a.empty()) {
            cout << a.front() << ' ';
            a.pop_front();
        }
        if (!c.empty()) {
            cout << c.front() << ' ';
            c.pop_front();
        }
        if (!d.empty()) {
            cout << d.front() << ' ';
            d.pop_front();
        }
    }
    cout << '\n';
}