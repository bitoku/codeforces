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
    int x = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) x++;
    }
    if ((n == 1 && x == 0) || (n > 1 && x == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}