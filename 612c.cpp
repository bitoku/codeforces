#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

bool open(char c) {
    return c == '[' || c == '{' || c == '<' || c == '(';
}

bool match(char c1, char c2) {
    return (c1 == '(' && c2 == ')') ||
            (c1 == '{' && c2 == '}') ||
            (c1 == '<' && c2 == '>') ||
            (c1 == '[' && c2 == ']');
}

int main() {
    string s;
    cin >> s;
    string t;
    ll result = 0;
    for (char c : s) {
        if (!t.empty() && open(t.back()) && !open(c)) {
            if (!match(t.back(), c)) result++;
            t.pop_back();
            continue;
        }
        t.push_back(c);
    }
    if (t.empty()) {
        cout << result << endl;
        return 0;
    }
    cout << "Impossible" << endl;
}