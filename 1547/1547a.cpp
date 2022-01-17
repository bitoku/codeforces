#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll xa, ya;
        cin >> xa >> ya;
        ll xb, yb;
        cin >> xb >> yb;
        ll xf, yf;
        cin >> xf >> yf;
        if ((xa == xb && xb == xf && ((ya < yf && yf < yb) || (yb < yf && yf < ya)))
            || (ya == yb && yb == yf && ((xa < xf && xf < xb) || (xb < xf && xf < xa)))) {
            cout << abs(xa - xb) + abs(ya - yb) + 2 << endl;
        } else {
            cout << abs(xa - xb) + abs(ya - yb) << endl;
        }
    }

}