#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    it++;
    while (it != a.end()) {
        cout << delimiter << *it;
        it++;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        deque<int> zero;
        deque<int> one;
        int cnt = 1;
        vector<int> result;
        for (char j : s) {
            if (j == '0') {
                if (one.empty()) {
                    result.push_back(cnt);
                    zero.push_back(cnt);
                    cnt++;
                } else {
                    int tmp = one.front(); one.pop_front();
                    result.push_back(tmp);
                    zero.push_back(tmp);
                }
            } else {
                if (zero.empty()) {
                    result.push_back(cnt);
                    one.push_back(cnt);
                    cnt++;
                } else {
                    int tmp = zero.front(); zero.pop_front();
                    result.push_back(tmp);
                    one.push_back(tmp);
                }
            }
        }
        cout << cnt-1 << endl;
        printIter(result, " ");
    }
}
