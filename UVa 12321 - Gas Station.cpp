#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every manhattan grid!

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc(int L, int G) {
    vector<pair<int, int>> is(G);
    int x, r;
    for (int i = 0; i < G; i++) {
        scanf("%d %d", &x, &r);
        is[i] = {x - r, x + r};
    }

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first
                ? true
                : a.first > b.first
                ? false
                : a.second > b.second;
    };

    sort(is.begin(), is.end(), cmp);

    int covered = 0;
    bool possible = true;
    int minGas = 0;

    for (int i = 0; i < G; i++) {
        if (covered >= L) break;
        if (is[i].second <= covered) continue;
        if (is[i].first <= covered) {
            int max_r = -1;
            for (int j = i; j < G && is[j].first <= covered; j++) {
                if (is[j].second > max_r) {
                    max_r = is[j].second;
                }
            }
            covered = max_r; minGas++;
        } else possible = false;
    }

    if (!possible || covered < L) {
        printf("-1\n");
    } else {
        printf("%d\n", G - minGas);
    }
}

void solve() {
    int L, G;
    while (scanf("%d %d", &L, &G), L != 0 || G != 0) {
        tc(L, G);
    }
}

// WOW: printf("%d%c", miss[i], " \n"[i==n-1]);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    cout << flush;
}
