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

double ans = 0.0;

vector<ll> sheets;
bool possible = true;

void backtrack(int pos, double length, double width, int required) {
    if (pos == sheets.size()) {
        possible = false;
    } else {
        if (sheets[pos] >= required) {
        } else {
            int deficit = required - sheets[pos];
            backtrack(pos + 1, width, length / 2.0, deficit * 2);
        }
        ans += (required / 2.0) * length;
        sheets[pos] -= required;
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    sheets.resize(n - 1);
    for (int i = 0; i < n - 1; i++) scanf("%d", &sheets[i]);
    backtrack(0, pow(2, -3.0 / 4.0), pow(2, -5.0 / 4.0), 2);
    if (!possible) {
        printf("impossible\n");
    } else {
        printf("%lf\n", ans);
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
