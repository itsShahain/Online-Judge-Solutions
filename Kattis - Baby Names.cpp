#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;

// #define FILE_IO
// #define RUNTIME

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
}

void solve() {
    int command, gender;
    string name, start, end;

    ost maleNames, femaleNames;

    while (cin >> command, command != 0) {
        if (command == 1) {
            cin >> name >> gender;
            if (gender == 1) {
                maleNames.insert(name);
            } else {
                femaleNames.insert(name);
            }
        } else if (command == 2) {
            cin >> name;
            ost::iterator it;
            if ((it = maleNames.find(name)) != maleNames.end()) {
                maleNames.erase(it);
            } else {
                it = femaleNames.find(name);
                femaleNames.erase(it);
            }
        } else {
            ost::iterator i1, i2;
            cin >> start >> end >> gender;
            int ans;
            if (gender == 0) {
                ans = maleNames.order_of_key(end) - maleNames.order_of_key(start) + femaleNames.order_of_key(end) -
                      femaleNames.order_of_key(start);
            } else if (gender == 1) {
                ans = maleNames.order_of_key(end) - maleNames.order_of_key(start);
            } else {
                ans = femaleNames.order_of_key(end) - femaleNames.order_of_key(start);
            }

            cout << ans << '\n';
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
