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


int S, n;
vector<int> coins;
int memo[105][10010];

int least(int i, int amt) {
    if (i == n || amt <= 0) {
        return amt > 0 ? INT_MIN : amt;
    } else {
        int& ans = memo[i][amt];
        if (ans != -1) return ans;
        ans = max(least(i + 1, amt - coins[i]), least(i + 1, amt));
        return ans;
    }
}

void tc() {
    scanf("%d %d", &S, &n);
    coins.resize(n);
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    int target = S - least(0, S);
    vector<vector<int>> memo(n + 1, vector<int>(target + 1));
    for (int i = 0; i <= n; i++) memo[i][0] = 0;
    for (int weight = 1; weight <= target; weight++) memo[n][weight] = 101; // too lazy to deal with int overflow with INT_MAX :P
    for (int i = n - 1; i >= 0; i--) {
        for (int weight = 1; weight <= target; weight++) {
            if (coins[i] <= weight) {
                memo[i][weight] = min(memo[i + 1][weight - coins[i]] + 1, memo[i + 1][weight]);
            } else {
                memo[i][weight] = memo[i + 1][weight];
            }
        }
    }
    printf("%d %d\n", target, memo[0][target]);
}

void solve() {
    int TC;
    scanf("%d", &TC);
    while (TC--) tc();
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
