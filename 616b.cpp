#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int temp = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            temp = min(temp, x);
        }
        result = max(result, temp);
    }
    cout << result << endl;
}