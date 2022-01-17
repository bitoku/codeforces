#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    ll result = 0;
    for (int i = a; i <= b; ++i) {
        int t = i;
        while (t > 0) {
            int k = t % 10;
            if (k == 0) result += 6;
            if (k == 1) result += 2;
            if (k == 2) result += 5;
            if (k == 3) result += 5;
            if (k == 4) result += 4;
            if (k == 5) result += 5;
            if (k == 6) result += 6;
            if (k == 7) result += 3;
            if (k == 8) result += 7;
            if (k == 9) result += 6;
            t /= 10;
        }
    }
    cout << result << endl;
}