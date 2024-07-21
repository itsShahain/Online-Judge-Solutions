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
    int l, d, n; scanf("%d %d %d", &l, &d, &n);
    if (l < 12) {
        printf("0\n"); return;
    }

    vector<int> birds(n);
    for (int i = 0; i < n; i++) scanf("%d", &birds[i]);

    vector<pair<int, int>> is; int x;
    is.emplace_back(0, 1); is.emplace_back(6, 0);
    is.emplace_back(l - 6, 1); is.emplace_back(l, 0);

    for (int i = 0; i < n; i++) {
        is.emplace_back(birds[i] - d, 1);
        is.emplace_back(birds[i] + d, 0);
    }

    sort(is.begin(), is.end());
    vector<pair<int, int>> js; stack<int> sk;
    for (int i = 0; i < is.size(); i++) {
        if (is[i].second) sk.push(is[i].first);
        else {
            if (sk.size() == 1) {
                js.emplace_back(sk.top(), is[i].first); sk.pop();
            } else sk.pop();
        }
    }

    int ans = 0;
    for (int j = 0; j < js.size() - 1; j++) {
        ans += (js[j + 1].first - js[j].second) / d + 1;
    }
    printf("%d\n", ans);
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
