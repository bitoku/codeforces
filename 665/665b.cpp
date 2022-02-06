#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    deque<int> dq(k);
    for (int i = 0; i < k; ++i) {
        cin >> dq[i];
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            auto it = find(dq.begin(), dq.end(), x);
            result += distance(dq.begin(), it) + 1;
            dq.erase(it);
            dq.push_front(x);
        }
    }
    cout << result << endl;
}