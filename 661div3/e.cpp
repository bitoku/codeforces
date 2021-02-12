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
        ll s;
        cin >> n >> s;
        vector<set<int>> verts(n + 1);
        vector<vector<ll>> weight(n+1, vector<ll>(n+1, 0));
        vector<int> parent(n+1);
        vector<ll> nodes(n+1);
        for (int j = 0; j < n - 1; ++j) {
            int v, u;
            ll w;
            cin >> v >> u >> w;
            verts[v].insert(u);
            verts[u].insert(v);
            weight[u][v] = w;
            weight[v][u] = w;
        }
        deque<int> leaves;
        for (int j = 1; j <= n; ++j) {
            if (verts[j].size() == 1) leaves.push_back(j);
        }
        set<int> done;
        for (int leave : leaves) {
            nodes[leave] = 1;
        }
        while (!leaves.empty()) {
            int vert = leaves.front(); leaves.pop_front();
            nodes[parent[vert]] += nodes[vert];
            if (done.find(parent[vert]) != done.end()) continue;
            leaves.push_back(parent[vert]);
            done.insert(parent[vert]);
        }
        // sum, weight, number
        priority_queue<tuple<ll, ll, ll>> pq;
        ll ss = 0;
        for (int j = 1; j <= n; ++j) {
            pq.push(make_tuple(nodes[j] * weight[j][parent[j]], weight[j][parent[j]], nodes[j]));
            ss += nodes[j] * weight[j][parent[j]];
        }
//        printIter(parent, " ");
//        printIter(nodes, " ");
        ll cnt = 0;
        while (ss > s) {
            auto x = pq.top(); pq.pop();
//            cout << get<0>(x) << endl;
            ss -= get<0>(x);
            ll new_weight = get<1>(x) / 2;
            ll ns = get<2>(x);
            ss += new_weight * ns;
            pq.push(make_tuple(ns * new_weight, new_weight, ns));
            cnt++;
        }
        cout << cnt << endl;
    }
}
