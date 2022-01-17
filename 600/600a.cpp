#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

bool is_number(string& s) {
    if (s == "0") return true;
    else if (s[0] == '0' || s.empty()) return false;
    return all_of(s.begin(), s.end(), [](char c) { return '0' <= c && c <= '9';});
}

int main() {
    string s;
    cin >> s;
    vector<string> number;
    vector<string> str;
    string t;
    for (auto c: s) {
        if (c == ',' || c == ';') {
            if (is_number(t)) number.push_back(t);
            else str.push_back(t);
            t.clear();
            continue;
        }
        t.push_back(c);
    }
    if (is_number(t)) number.push_back(t);
    else str.push_back(t);

    if (!number.empty()) {
        cout << '"';
        cout << number[0];
        for (int i = 1; i < number.size(); ++i) {
            cout << ',' << number[i];
        }
        cout << '"' << endl;
    } else {
        cout << '-' << endl;
    }
    if (!str.empty()) {
        cout << '"';
        cout << str[0];
        for (int i = 1; i < str.size(); ++i) {
            cout << ',' << str[i];
        }
        cout << '"' << endl;
    } else {
        cout << '-' << endl;
    }
}