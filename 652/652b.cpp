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
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < (n+1)/2; ++i) {
        b[2*i] = a[i];
    }
    for (int i = (n+1)/2; i < n; ++i) {
        b[2*n-1 - 2*i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
}