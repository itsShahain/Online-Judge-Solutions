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
    int m; ll w, h;
    scanf("%d", &m);
    vector<pair<ll, ll>> dolls;
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &w, &h);
        dolls.emplace_back(w, h);
    }

    auto cmp = [](pair<ll, ll>&a, pair<ll, ll>&b) {
        return a.first < b.first
        ? true
        : a.first > b.first
        ? false
        : a.second > b.second
        ? true
        : false;
    };

    sort(dolls.begin(), dolls.end(), cmp);

    int k = 0; ll currHeight;
    vector<ll> heights(m + 5);
    for (int i = 0; i < dolls.size(); i++) {
        currHeight = dolls[i].second;
        int low = 0, high = k, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (heights[mid] < currHeight) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        heights[low] = currHeight;
        if (low == k) k++;
    }
    printf("%d\n", k);

}

void solve() {
    int TC;
    scanf("%d", &TC);
    while (TC--) tc();
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
