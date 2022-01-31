#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = i; j >= 0; --j) {
            if (j != i && b[j] == 0) {
                break;
            }
            b[j] = gcd(a[i], b[j]);
            if (b[j] == i - j + 1) {
                b[i] = 0;
                break;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) result++;
        cout << result << ' ';
    }
    cout << '\n';
}