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
    vector<ll> treeNumber(85 + 1, 1LL);
    treeNumber[1] = treeNumber[2] = 1;
    for (int i = 3; i <= 85; i++) {
        ll& ans = treeNumber[i];
        for (int j = i; j >= 3; j--) {
            ans += treeNumber[1 + i - j];
        }
    }
    int level;
    while (scanf("%d", &level), level != 0) printf("%lld\n", treeNumber[level]);
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
