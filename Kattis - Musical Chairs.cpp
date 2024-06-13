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
int* prof;

int josephus(int n, vector<int>& ks, vector<int>& ns) {
    if (n == 1) {
        return 0;
    } else {
        int tp = 0;
        for(int i = ks.size() - 1; i >= 0; i--) {
            tp = (tp + ks[i]) % ns[i];
        }
        ks.push_back(prof[tp]);
        ns.push_back(n);
        return (josephus(n - 1, ks, ns) + prof[tp]) % n;
    }
}

void solve() {
    scanf("%d", &n);
    prof = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &prof[i]);

    vector<int> ks;
    vector<int> ns;
    printf("%d", josephus(n, ks, ns) + 1);
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
