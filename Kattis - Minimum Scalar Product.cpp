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
    int n;
    scanf("%d", &n);
    vector<ll> xs(n), ys(n);
    for (int i = 0; i < n; i++) scanf("%lld", &xs[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &ys[i]);
    sort(xs.begin(), xs.end());
    sort(ys.rbegin(), ys.rend());
    ll ans = 0LL;
    for (int i = 0; i < n; i++) ans += xs[i] * ys[i];
    printf("%lld\n", ans);
}

void solve() {
    int TC;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        printf("Case #%d: ", i + 1); tc();
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
