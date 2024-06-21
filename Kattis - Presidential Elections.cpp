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
}

void solve() {
    int S;
    scanf("%d", &S);
    ll totalDelegates = 0;
    vector<ll> D(S + 1), C(S + 1), F(S + 1), U(S + 1);
    for (int i = 1; i <= S; i++) {
        scanf("%lld %lld %lld %lld", &D[i], &C[i], &F[i], &U[i]);
        totalDelegates += D[i];
    }
    vector<vector<ll> > dp(S + 2, vector<ll>(totalDelegates + 1, INT_MAX));

    for (int state = 1; state <= S + 1; state++) dp[state][0] = 0LL;
    for (int delegates = 1; delegates <= totalDelegates; delegates++) dp[S + 1][delegates] = INT_MAX;

    ll tp;
    for (int state = S; state >= 1; state--) {
        for (ll delegates = 1; delegates <= totalDelegates; delegates++) {
            if (F[state] - C[state] + U[state] < 0) {
                tp = max(0LL, (F[state] - C[state] + U[state]) / 2LL);
            } else {
                tp = (F[state] - C[state] + U[state]) / 2LL + 1;
            }
            if (U[state] >= tp) {
                dp[state][delegates] = min(
                    tp + (ll) (dp[state + 1][max(0LL, delegates - D[state])]),
                    dp[state + 1][delegates]
                );
                // if (dp[3][])
            } else {
                dp[state][delegates] = dp[state + 1][delegates];
            }
        }
    }
    if (dp[1][(totalDelegates) / 2LL + 1LL] >= INT_MAX) {
        // check for draw
        printf("impossible\n");
    } else {
        printf("%lld\n", dp[1][(totalDelegates) / 2LL + 1LL]);
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
