// Only solved for L <= 26. Because it's absurd that L can be 10000!?
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FILE_IO

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every manhattan grid!

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
    vector<vector<vector<ll>>> memo(26 + 1, vector<vector<ll>>(10000 + 1, vector<ll>(26 + 1, 0)));

    for (int last = 0; last <= 26; last++) memo[26][0][last] = 1;
    for (int last = 0; last <= 26; last++) {
        for (int S = 1; S <= 10000; S++) memo[26][S][last] = 0;
    }

    for (int i = 25; i >= 0; i--) {
        for (int S = 1; S <= 10000; S++) {
            for (int last = 0; last <= 25; last++) {
                ll& ans = memo[i][S][last];
                for (int j = last + 1; j <= 26; j++) {
                    if (j <= S) ans += memo[i + 1][S - j][j];
                }
            }
        }
    }


    int L, S, TC = 1;
    while (scanf("%d %d", &L, &S), L != 0 || S != 0) {
        printf("Case %d: %lld\n", TC++, memo[26 - L][S][0]);
    }
}

void solve() {
    tc();
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
