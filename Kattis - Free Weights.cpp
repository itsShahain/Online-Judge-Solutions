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

int n;
vector<ll> top, bottom;

bool isValid(ll w) {
    stack<ll> stk;
    for (int i = 0; i < n; i++) {
        if (top[i] > w) {
            if (stk.empty()) {
                stk.push(top[i]);
            } else if (stk.top() != top[i]) {
                return false;
            } else {
                stk.pop();
            }
        }
    }
    if (!stk.empty()) return false;

    for (int i = 0; i < n; i++) {
        if (bottom[i] > w) {
            if (stk.empty()) {
                stk.push(bottom[i]);
            } else if (stk.top() != bottom[i]) {
                return false;
            } else {
                stk.pop();
            }
        }
    }

    if (!stk.empty()) return false;

    return true;

}

void solve() {
    scanf("%d", &n);
    top.resize(n);
    bottom.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &top[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &bottom[i]);
    }

    ll low = 0, high = 1e9, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (isValid(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", low);
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
