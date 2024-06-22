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
    int N;
    scanf("%d", &N);
    vector<int> fee(N);
    for (int i = 0; i < N; i++) scanf("%d", &fee[i]);
    vector<vector<int> > memo(N, vector<int>(N, 5e5));

    for (int prev = 1; prev < N; prev++) memo[N - 1][prev] = fee[N - 1];

    for (int prev = N - 1; prev >= 1; prev--) {
        for (int i = 0; i < N; i++) {
            int &ans = memo[i][prev];
            if (i + prev + 1 < N) ans = min(ans, fee[i] + memo[i + prev + 1][prev + 1]);
            if (i - prev >= 0) ans = min(ans, fee[i] + memo[i - prev][prev]);
        }
    }

    printf("%d\n", memo[1][1]);
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
