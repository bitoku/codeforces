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
    unordered_set<int> s;
    vector<int> seg;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (s.find(a) != s.end()) {
            seg.push_back(i + 1);
            s.clear();
        } else {
            s.insert(a);
        }
    }
    if (seg.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    seg.back() = n;
    cout << seg.size() << '\n';
    int a = 1;
    for (auto b: seg) {
        cout << a << ' ' << b << '\n';
        a = b + 1;
    }
}