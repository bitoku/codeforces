#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        multiset<int> a;
        for (int j = 0; j < n; ++j) {
            int aa;
            cin >> aa;
            a.insert(aa);
        }
        int m = 0;
        for (int s = 1; s <= 2 * n; ++s) {
            int cnt = 0;
            multiset<int> b(a);
            while (!b.empty()) {
                auto first = b.begin();
                int k = *first;
                b.erase(first);
                if (s - k < 0) continue;
                auto it = find(b.begin(), b.end(), s - k);
                if (it != b.end()) {
                    cnt++;
                    b.erase(it);
                }
            }
            m = max(cnt, m);
        }
        cout << m << endl;
    }
}
