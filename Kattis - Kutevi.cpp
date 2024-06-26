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
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> have(N), target(K);
    for (int i = 0; i < N; i++) scanf("%d", &have[i]);
    for (int i = 0; i < K; i++) scanf("%d", &target[i]);

    for (auto &data: target) {
        vector<vector<bool> > memo(N + 1, vector<bool>(720 + 1, false));
        memo[N][360] = true;
        for (int i = N - 1; i >=0; i--) {
            for (int S = 0; S <= 720; S++) {
                for (int j = -360; j <= 360; j++) {
                    memo[i][S] = memo[i][S] | memo[i + 1][(S - 360 + j * have[i]) % 360 + 360];
                }
            }
        }
        if (memo[0][360 + data]) printf("YES\n");
        else printf("NO\n");
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
