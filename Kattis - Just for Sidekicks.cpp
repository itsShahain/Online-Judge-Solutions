#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
}

int N;
vector<vector<int>> fenwick;

vector<int> rsq(int i) {
    vector<int> temp(7, 0);
    for(; i > 0; i -= LSOne(i)) {
        for(int j = 1; j <= 6; j++) {
            temp[j] += fenwick[i][j];
        }
    }
    return temp;
}

void solve() {
    int Q;
    scanf("%d %d", &N, &Q);
    fenwick = vector<vector<int>>(N + 1);
    vector<int> values(7);
    for(int i = 1; i <= 6; i++) {
        scanf("%d", &values[i]);
    }
    scanf("%*c");
    char type;
    vector<int> gemAt(N + 1);
    for(int i = 0; i < N;i ++) {
        scanf("%c", &type);
        vector<int> temp(7, 0);
        temp[type - '0']++;
        gemAt[i + 1] = type - '0';
        fenwick[i + 1] = temp;
    }
    for(int j = 1; j < fenwick.size(); j++) {
        int parent = j + LSOne(j);
        if(parent < fenwick.size()) {
            for(int i = 1; i <= 6; i++) fenwick[parent][i] += fenwick[j][i];
        }
    }

    int queryType, K, P, L, R;
    while(Q--) {
        scanf("%d", &queryType);
        if(queryType == 1) {
            scanf("%d %d", &K, &P);
            int j = K;
            for(;j < fenwick.size(); j += LSOne(j)) {
                fenwick[j][gemAt[K]]--;
                fenwick[j][P]++;
            }
            gemAt[K] = P;
        } else if (queryType == 2) {
            scanf("%d", &P);
            scanf("%d", &values[P]);
        } else if (queryType == 3) {
            scanf("%d %d", &L, &R);
            vector<int> a, b;
            a = rsq(R); b = rsq(L - 1);
            ll value = 0;
            for(int i = 1; i <= 6; i++) {
                value += (a[i] - b[i]) * ((ll) (values[i]));
            }
            printf("%lld\n", value);
        }

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    cout << flush;
}
