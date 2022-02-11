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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0;
    int result = 1;
    for (int r = 1; r < n; ++r) {
        if (a[r] <= a[r-1]) {
            result = max(result, r - l);
            l = r;
        }
    }
    result = max(result, n - l);
    cout << result << endl;
}