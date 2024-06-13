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

vector<bool> teams;
vector<int> reserved;
int best = INT_MAX;

void allocate(int pos) {
    if (pos == reserved.size()) {
        int tot = 0;
        for(int i = 0; i < teams.size(); i++) {
            if(teams[i] == false) tot++;
        }

        best = min(best, tot);
    } else {
        if (teams[reserved[pos]] == false) {
            teams[reserved[pos]] = true;
            allocate(pos + 1);
            teams[reserved[pos]] = false;
        }

        if (reserved[pos] - 1 >= 0 && teams[reserved[pos] - 1] == false) {
            teams[reserved[pos] - 1] = true;
            allocate(pos + 1);
            teams[reserved[pos] - 1] = false;
        }

        if (reserved[pos] + 1 < teams.size() && teams[reserved[pos] + 1] == false) {
            teams[reserved[pos] + 1] = true;
            allocate(pos + 1);
            teams[reserved[pos] + 1] = false;
        }

        allocate(pos + 1);
    }
}

void solve() {
    int N, S, R;
    scanf("%d %d %d", &N, &S, &R);
    teams.resize(N, true);
    reserved.resize(R);
    int x;
    for (int i = 0; i < S; i++) {
        scanf("%d", &x);
        x--;
        teams[x] = false;
    }

    for (int i = 0; i < R; i++) {
        scanf("%d", &reserved[i]);
        reserved[i]--;
    }

    allocate(0);
    printf("%d\n", best);
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
