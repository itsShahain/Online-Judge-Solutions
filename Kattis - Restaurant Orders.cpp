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
    int n;
    scanf("%d", &n);
    vector<int> coins(n + 1);
    vector<vector<bool> > dp(n + 2, vector<bool>(30001, false));
    vector<vector<int> > transition(n + 2, vector<int>(30001, -1));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }

    for (int weight = 1; weight <= 30000; weight++) {
        dp[n + 1][weight] = false;
    }

    for (int coin = 1; coin <= n + 1; coin++) {
        dp[coin][0] = true;
    }

    for (int coin = n; coin > 0; coin--) {
        for (int weight = 1; weight <= 30000; weight++) {
            if (coin == 2 && weight == 4812) {
                int c = 3;
            }
            if (weight >= coins[coin] && dp[coin][weight - coins[coin]] && dp[coin + 1][weight]) {
                transition[coin][weight] = -1;
                dp[coin][weight] = true;
            } else if (weight >= coins[coin] && dp[coin][weight - coins[coin]]) {
                transition[coin][weight] = 1;
                dp[coin][weight] = true;
            } else if (dp[coin + 1][weight]) {
                transition[coin][weight] = 0;
                dp[coin][weight] = true;
            } else {
                transition[coin][weight] = -1;
                dp[coin][weight] = false;
            }
            // if (weight >= coins[coin]) {
            //     dp[coin][weight] = dp[coin][weight - coins[coin]] || dp[coin + 1][weight];
            // } else {
            //     dp[coin][weight] = dp[coin + 1][weight];
            // }
        }
    }

    int m, order;
    scanf("%d", &m);
    vector<int> actAns;
    bool ok;
    for (int i = 0; i < m; i++) {
        scanf("%d", &order);
        ok = true;
        actAns.resize(0);
        if (dp[1][order]) {
            int coinIDX = 1, weightIDX = order;
            while (true) {
                if (weightIDX == 0) break;
                if (transition[coinIDX][weightIDX] == -1) {
                    ok = false;
                    break;
                } else if (transition[coinIDX][weightIDX] == 0) {
                    coinIDX++;
                } else if (transition[coinIDX][weightIDX] == 1) {
                    actAns.push_back(coinIDX);
                    weightIDX -= coins[coinIDX];
                }
            }
            if (ok) {
                for (int i = 0; i < actAns.size(); i++) printf("%d%c", actAns[i], " \n"[i == actAns.size() - 1]);
            } else {
                printf("Ambiguous\n");
            }
        } else {
            printf("Impossible\n");
        }
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
