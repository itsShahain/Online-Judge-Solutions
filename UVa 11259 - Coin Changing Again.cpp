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

void tc() {
    int c1, c2, c3, c4, q, d1, d2, d3, d4, v;
    scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &q);
    vector<int> cs;
    cs.push_back(c1);
    cs.push_back(c2);
    cs.push_back(c3);
    cs.push_back(c4);

    vector<vector<ll> > memo(4 + 1, vector<ll>(1e5 + 5, 0LL));

    for (int i = 0; i <= 4; i++) memo[i][0] = 1;
    for (int weight = 1; weight <= 1e5; weight++) memo[4][weight] = 0;

    for (int i = 3; i >= 0; i--) {
        for (int weight = 1; weight <= 1e5; weight++) {
            if (weight >= cs[i]) {
                memo[i][weight] = memo[i][weight - cs[i]] + memo[i + 1][weight];
            } else {
                memo[i][weight] = memo[i + 1][weight];
            }
        }
    }

    ll totalWays, invalidWays;
    while (q--) {
        scanf("%d %d %d %d %d", &d1, &d2, &d3, &d4, &v);
        totalWays = memo[0][v];
        invalidWays = 0LL;
        invalidWays +=
                ((v - (d1 + 1) * c1 >= 0) ? memo[0][v - (d1 + 1) * c1] : 0)
                + ((v - (d2 + 1) * c2 >= 0) ? memo[0][v - (d2 + 1) * c2] : 0)
                + ((v - (d3 + 1) * c3 >= 0) ? memo[0][v - (d3 + 1) * c3] : 0)
                + ((v - (d4 + 1) * c4 >= 0) ? memo[0][v - (d4 + 1) * c4] : 0);

        invalidWays -=
                ((v - (d1 + 1) * c1 - (d2 + 1) * c2 >= 0) ? memo[0][v - (d1 + 1) * c1 - (d2 + 1) * c2] : 0)
                + ((((v - (d2 + 1) * c2 - (d3 + 1) * c3 >= 0)) ? memo[0][v - (d2 + 1) * c2 - (d3 + 1) * c3] : 0))
                + ((((v - (d3 + 1) * c3 - (d4 + 1) * c4 >= 0)) ? memo[0][v - (d3 + 1) * c3 - (d4 + 1) * c4] : 0))
                + ((((v - (d1 + 1) * c1 - (d3 + 1) * c3 >= 0)) ? memo[0][v - (d1 + 1) * c1 - (d3 + 1) * c3] : 0))
                + ((((v - (d2 + 1) * c2 - (d4 + 1) * c4 >= 0)) ? memo[0][v - (d2 + 1) * c2 - (d4 + 1) * c4] : 0))
                + ((((v - (d1 + 1) * c1 - (d4 + 1) * c4 >= 0)) ? memo[0][v - (d1 + 1) * c1 - (d4 + 1) * c4] : 0));
        invalidWays +=
                ((((v - (d1 + 1) * c1 - (d2 + 1) * c2 - (d3 + 1) * c3 >= 0)) ? memo[0][v - (d1 + 1) * c1 - (d2 + 1) * c2 - (d3 + 1) * c3] : 0))
                + ((v - (d2 + 1) * c2 - (d3 + 1) * c3 - (d4 + 1) * c4 >= 0) ? memo[0][v - (d2 + 1) * c2 - (d3 + 1) * c3 - (d4 + 1) * c4] : 0)
                + ((v - (d1 + 1) * c1 - (d2 + 1) * c2 - (d4 + 1) * c4 >= 0) ? memo[0][v - (d1 + 1) * c1 - (d2 + 1) * c2 - (d4 + 1) * c4] : 0)
                + ((v - (d1 + 1) * c1 - (d3 + 1) * c3 - (d4 + 1) * c4 >= 0) ? memo[0][v - (d1 + 1) * c1 - (d3 + 1) * c3 - (d4 + 1) * c4] : 0);
        invalidWays -=
                (((v - (d1 + 1) * c1 - (d2 + 1) * c2 - (d3 + 1) * c3 - (d4 + 1) * c4 >= 0) ? memo[0][v - (d1 + 1) * c1 - (d2 + 1) * c2 - (d3 + 1) * c3 - (d4 + 1) * c4] : 0));
        printf("%lld\n", totalWays - invalidWays);
    }
}

void solve() {
    int N;
    scanf("%d", &N);
    while (N--) tc();
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
