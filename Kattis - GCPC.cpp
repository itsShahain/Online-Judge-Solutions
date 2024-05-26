#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

typedef long long ll;


struct customComparator {
    bool operator()(const tuple<ll, ll, int>&a, const tuple<ll, ll, int>& b) const {
        ll aSolved = get<0>(a), aPenalty = get<1>(a), bSolved = get<0>(b), bPenalty = get<1>(b);
        int aNumber = get<2>(a), bNumber = get<2>(b);
        return aSolved > bSolved
        ? true
        : aSolved < bSolved
        ? false
        : aPenalty < bPenalty
        ? true
        : aPenalty > bPenalty
        ? false
        : aNumber < bNumber
        ? true
        : false;

    }
};
typedef tree<tuple<ll, ll, int>, null_type, customComparator, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
}

void solve() {
    ost tree;
    unordered_map<int, tuple<ll, ll>> teams;
    int n, m, t;
    ll p;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> t >> p;
        tuple<ll, ll> teamStat = teams[t];
        tree.erase({get<0>(teamStat), get<1>(teamStat), t});
        teams.erase(teams.find(t));
        teams[t] = {get<0>(teamStat) + 1LL, get<1>(teamStat) + p};
        tree.insert({get<0>(teamStat) + 1LL, get<1>(teamStat) + p, t});
        cout << tree.order_of_key({get<0>(teams[1]), get<1>(teams[1]), 1}) + 1 << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    cout << flush;
}
