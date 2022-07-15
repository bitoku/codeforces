#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ull> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<ull>>> d(n, vector<vector<ull>>(n, vector<ull>(60)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (popcount(a[i] ^ a[j]) % 3 == 0) {
                d[i][j][0] = 1;
            }
        }
    }

    for (int i = 0; i < 59; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                for (int m = 0; m < n; ++m) {
                    d[j][m][i+1] += d[j][l][i] * d[l][m][i] % mod;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                d[j][l][i+1] %= mod;
            }
        }
    }

    vector<vector<ull>> resultm(n, vector<ull>(n));
    for (int i = 0; i < n; ++i) {
        resultm[i][i] = 1;
    }
    ull result = 0;
    for (int i = 0; i < 60; ++i) {
        if ((k-1) & (1ll << i)) {
            vector<vector<ull>> temp(n, vector<ull>(n));
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < n; ++l) {
                    for (int m = 0; m < n; ++m) {
                         temp[j][m] += resultm[j][l] * d[l][m][i] % mod;
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < n; ++l) {
                    temp[j][l] %= mod;
                }
            }
            resultm = temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result += resultm[i][j];
        }
    }
    result %= mod;
    cout << result << endl;
}