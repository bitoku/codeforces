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
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && gcd(a[i], a[i-1]) != 1) {
            b.push_back(1);
        }
        b.push_back(a[i]);
    }
    cout << b.size() - a.size() << endl;
    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
}