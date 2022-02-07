#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

bool is_leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int y;
    cin >> y;
    bool leap = is_leap(y);
    int x = 0;
    do {
        y++;
        if (is_leap(y)) {
            x += 366;
            x %= 7;
        } else {
            x += 365;
            x %= 7;
        }
    } while (x || leap != is_leap(y));
    cout << y << endl;
}