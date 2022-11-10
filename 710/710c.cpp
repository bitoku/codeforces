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
    vector<vector<int>> matrix(n, vector<int>(n));
    int cnt = 1;
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = abs(i - (n / 2)); j < n - abs(i - (n / 2)); ++j) {
                matrix[i][j] = cnt;
                cnt += 2;
            }
        }
    } else {
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 1 + i; j < n - i; ++j) {
                matrix[i][j] = cnt;
                cnt += 2;
            }
        }
        for (int i = n / 2; i < n; ++i) {
            int k = i - n / 2;
            for (int j = k; j < n - k - 1; ++j) {
                matrix[i][j] = cnt;
                cnt += 2;
            }
        }
    }
    cnt = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) continue;
            matrix[i][j] = cnt;
            cnt += 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}