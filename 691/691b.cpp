#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i <= s.size() / 2 ; ++i) {
        int j = s.size() - 1 - i;
        if (
                (s[i] == 'b' && s[j] == 'd') ||
                (s[i] == 'd' && s[j] == 'b') ||
                (s[i] == 'p' && s[j] == 'q') ||
                (s[i] == 'q' && s[j] == 'p') ||
                ((s[i] == 'A' || s[i] == 'H' || s[i] == 'I' ||
                 s[i] == 'M' || s[i] == 'O' || s[i] == 'o' ||
                 s[i] == 'T' || s[i] == 'U' || s[i] == 'V' ||
                 s[i] == 'v' || s[i] == 'W' || s[i] == 'w' ||
                 s[i] == 'X' || s[i] == 'x' || s[i] == 'Y') && s[i] == s[j])) {
            continue;
        }
        cout << "NIE" << endl;
        return 0;
    }
    cout << "TAK" << endl;
}