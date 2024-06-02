// Josephus problem in disguise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

int josephus(int n, int k, int r) {
    return n == r
    ? (k - 1) % r
    : (josephus(n - 1, k + 1, r) + k) % n;
}

int ans[13];

void tc() {
    int n;
    scanf("%d", &n);
    memset(ans, 0, sizeof ans);
    for(int r = 1; r <= n; r++) {
        ans[josephus(n, 2, r)] = n - r + 1;
    }

    for(int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
}

void solve() {
    int TC;
    scanf("%d", &TC);
    while(TC--) tc();
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
