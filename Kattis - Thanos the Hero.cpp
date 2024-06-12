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
    ll arr[N];
    for(int i = 0; i < N; i++) scanf("%lld", &arr[i]);

    ll minKilled = 0LL;

    for(int i = N - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) continue;
        if(arr[i + 1] == 0) {
            printf("%d\n", 1);
            return;
        }
        minKilled += arr[i] - (arr[i + 1] - 1LL);
        arr[i] = arr[i + 1] - 1LL;
    }

    printf("%lld\n", minKilled);
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
