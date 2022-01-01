#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int b, p, f;
        cin >> b >> p >> f;
        int h, c;
        cin >> h >> c;
        ll result = 0;
        if (h > c) {
            int x = min(b / 2, p);
            result += h * x;
            b -= 2 * x;
            result += c * min(b / 2, f);
        } else {
            int x = min(b / 2, f);
            result += c * x;
            b -= 2 * x;
            result += h * min(b / 2, p);
        }
        cout << result << endl;
    }
}