#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        while (a.size() > 2) {
            vector<int> b;
            for (int i = 0; i < n; i += 4) {
                int w, x, y, z;
                printf("? %d %d %d\n", a[i], a[(i+1) % a.size()], a[(i+2) % a.size()]);
                fflush(stdout);
                cin >> w;
                printf("? %d %d %d\n", a[(i+1) % a.size()], a[(i+2) % a.size()], a[(i+3) % a.size()]);
                fflush(stdout);
                cin >> x;
                printf("? %d %d %d\n", a[i], a[(i+2) % a.size()], a[(i+3) % a.size()]);
                fflush(stdout);
                cin >> y;
                printf("? %d %d %d\n", a[i], a[(i+1) % a.size()], a[(i+3) % a.size()]);
                fflush(stdout);
                cin >> z;
                if (w == x && x == y && y == z) {
                    continue;
                }
                if (x < max({w, y, z})) {
                    b.push_back(a[i]);
                }
                if (y < max({w, x, z})) {
                    if (i + 1 < a.size()) b.push_back(a[i + 1]);
                }
                if (z < max({w, x, y})) {
                    if (i + 2 < a.size()) b.push_back(a[i + 2]);
                }
                if (w < max({x, y, z})) {
                    if (i + 3 < a.size()) b.push_back(a[i + 3]);
                }
            }
            a = b;
        }
        if (a.size() == 1) {
            printf("! %d %d\n", a[0], a[0]);
            fflush(stdout);
        } else {
            printf("! %d %d\n", a[0], a[1]);
            fflush(stdout);
        }
    }
}