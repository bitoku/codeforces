#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        string s;
        cin >> s;
        deque<char> dq;
        for (auto c: s) {
            dq.push_back(c);
        }
        while (!dq.empty()) {
            if (dq.front() == dq.size() - 1 + 'a') {
                dq.pop_front();
            } else if (dq.back() == dq.size() - 1 + 'a') {
                dq.pop_back();
            } else {
                break;
            }
        }
        if (dq.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}