#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    map<char, int> alpha;
    string s;
    cin >> s;
    for (char & c : s) {
        alpha[c]++;
    }
    deque<char> dq;
    for (auto [a, b]: alpha) {
        if (b % 2 == 1) dq.push_back(a);
    }
    while (dq.size() >= 2) {
        alpha[dq.back()]--;
        alpha[dq.front()]++;
        dq.pop_back();
        dq.pop_front();
    }
    string result;
    for (auto [a, b]: alpha) {
        result += string(b / 2, a);
    }
    string latter = result;
    if (!dq.empty()) result += string(1, dq.front());
    reverse(latter.begin(), latter.end());
    result += latter;
    cout << result << endl;
}