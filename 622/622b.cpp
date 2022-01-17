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
    string t;
    int x, y;
    for (char i : s) {
        if (isdigit(i)) t.push_back(i);
        else {
            x = stoi(t);
            t.clear();
        }
    }
    y = stoi(t);
    int z;
    cin >> z;
    int ny = (y + z) % 60;
    int nz = (y + z) / 60;
    int nx = (x + nz) % 24;
    printf("%02d:%02d", nx, ny);
}