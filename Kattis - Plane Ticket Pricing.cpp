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
    int N, W, K;
    scanf("%d %d", &N, &W);
    vector<vector<int>> ticketPrices(W + 1), ticketAmounts(W + 1);
    for (int i = 0; i < W + 1; i++) {
        scanf("%d", &K);
        ticketPrices[i].resize(K);
        ticketAmounts[i].resize(K);
        for (int j = 0; j < K; j++) scanf("%d", &ticketPrices[i][j]);
        for (int j = 0; j < K; j++) scanf("%d", &ticketAmounts[i][j]);
    }

    vector<vector<int>> memo(W + 2, vector<int>(N + 1, -1));

    for (int i = 0; i <= W + 1; i++) memo[i][0] = 0;
    for (int n = 1; n <= N; n++) memo[W + 1][n] = 0;

    int firstTicketPrice;
    for (int i = W; i >= 0; i--) {
        for (int n = 1; n <= N; n++) {
            int& ans = memo[i][n];
            for (int j = 0; j < ticketAmounts[i].size(); j++) {
                if (ticketAmounts[i][j] > n) {
                    if (n * ticketPrices[i][j] + memo[i + 1][0] > ans) {
                        ans = n * ticketPrices[i][j] + memo[i + 1][0];
                        if (i == 0) firstTicketPrice = ticketPrices[0][j];
                    }
                } else {
                    if (ticketAmounts[i][j] * ticketPrices[i][j] + memo[i + 1][n - ticketAmounts[i][j]] > ans) {
                        ans = ticketAmounts[i][j] * ticketPrices[i][j] + memo[i + 1][n - ticketAmounts[i][j]];
                        if (i == 0) firstTicketPrice = ticketPrices[0][j];
                    }
                }
            }
        }
    }

    printf("%d\n%d\n", memo[0][N], firstTicketPrice);

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
