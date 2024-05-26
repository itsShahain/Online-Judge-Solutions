#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

typedef long long ll;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
}

void solve() {
    ost tree;
    ll d;
    string s;
    int id = 0;
    while(cin >> s) {
        if(s == "#") {
            ost::iterator it = tree.find_by_order(tree.size()/2);
            ll inspect = it->first;
            tree.erase(it);
            cout << inspect << '\n';
        } else {
            stringstream ss(s);
            ss >> d;
            tree.insert({d, id});
            id++;
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
