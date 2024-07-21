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
    vector<pair<int, int>> neg, pos; int x, t;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &t);
        if (x < 0) neg.emplace_back(-x, t);
        else pos.emplace_back(x, t);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    int ans = 0;

    int i, leftOver;

    leftOver = 0;
    i = neg.size() - 1;
    while (i >= 0) {
        if (neg[i].second > 0) {
            if (neg[i].second - leftOver >= 0) {
                neg[i].second -= leftOver;
                leftOver = 0;
                if (neg[i].second % K == 0) {
                    ans += 2 * neg[i].first * neg[i].second / K;
                } else {
                    ans += 2 * neg[i].first * (neg[i].second / K + 1);
                    leftOver = K * (neg[i].second / K + 1) - neg[i].second;
                }
            } else {
                leftOver -= neg[i].second;
            }
        }
        i--;
    }

    leftOver = 0;
    i = pos.size() - 1;
    while (i >= 0) {
        if (pos[i].second > 0) {
            if (pos[i].second - leftOver >= 0) {
                pos[i].second -= leftOver;
                leftOver = 0;
                if (pos[i].second % K == 0) {
                    ans += 2 * pos[i].first * pos[i].second / K;
                } else {
                    ans += 2 * pos[i].first * (pos[i].second / K + 1);
                    leftOver = K * (pos[i].second / K + 1) - pos[i].second;
                }
            } else {
                leftOver -= pos[i].second;
            }
        }
        i--;
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
