#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll a, b, c;
    cin >> a >> b >> c;
    ll m;
    cin >> m;
    priority_queue<ll, vector<ll>, greater<>> usb, ps2;
    for (int i = 0; i < m; ++i) {
        ll p;
        string t;
        cin >> p >> t;
        if (t == "PS/2") {
            ps2.push(p);
        } else {
            usb.push(p);
        }
    }
    ll num = 0;
    ll result = 0;
    while (a > 0 && !usb.empty()) {
        result += usb.top();
        usb.pop();
        a--;
        num++;
    }
    while (b > 0 && !ps2.empty()) {
        result += ps2.top();
        ps2.pop();
        b--;
        num++;
    }
    while (c > 0) {
        if (usb.empty() && ps2.empty()) break;
        if (ps2.empty() || (!usb.empty() && usb.top() < ps2.top())) {
            result += usb.top();
            usb.pop();
        } else {
            result += ps2.top();
            ps2.pop();
        }
        c--;
        num++;
    }
    cout << num << ' ' << result << endl;
}