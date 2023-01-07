#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k;
    cin >> k;
    cin.ignore();
    string s;
    getline(cin, s);
    vector<int> l;
    int cnt = 0;
    for (auto c: s) {
        ++cnt;
        if (c == ' ' || c == '-') {
            l.push_back(cnt);
            cnt = 0;
        }
    }
    l.push_back(cnt);

    auto f = [&](int t) {
        int x = 0;
        int num_lines = 1;
        for (int wl : l) {
            if (wl > t) return false;
            if (wl + x > t) {
                x = wl;
                num_lines++;
            } else {
                x += wl;
            }
        }
        if (num_lines <= k) {
            return true;
        }
        return false;
    };
    cout << binsearch(0, (int)s.size(), f) << endl;
}