#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // n == 2, k == any
    // 1 3 5 7
    // 2 4 6 8
    // odd odd odd odd
    // even even even even
    // n == 6, k == 3
    // 0 0 0  3 9 15  6 12 18
    // 1 1 1  1 7 13  4 10 16
    // 2 2 2  2 8 14  5 11 17

    // n == even!!!

    // n == 4, k == 1
    // 0 4
    // 1 1
    // 2 2
    // 3 3

    // n == 4, k == 2

    // 0 0 4 8


    // 0 1 2  3 5 7
    // 0 1 2  1 3
    // 0 1 2
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << '\n';
            }
            continue;
        }
        if (n % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                cout << n * j + i + 1 << ' ';
            }
            cout << '\n';
        }
    }
}