#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std::chrono;
// #define FILE_IO
// #define RUNTIME

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void tc() {
}

void solve() {
    int N;
    scanf("%d", &N);
    struct customComparator {
        bool operator()(const tuple<int, int, string> &a, const tuple<int, int, string> &b) const {
            return get<0>(a) < get<0>(b)
            ? true
            : get<0>(a) > get<0>(b)
            ? false
            : get<1>(a) > get<1>(b)
            ? true
            : false;

        }
    };
    set<
        tuple<int, int, string>,
        customComparator
    > st;

    unordered_map<string, pair<int, int> > mp; // infecction, arrival time

    int command, infection;
    string name;
    int arrivalTime = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &command);
        if (command == 0) {
            cin >> name;
            scanf("%d", &infection);
            mp[name] = {infection, arrivalTime};
            st.insert({infection, arrivalTime, name});
            arrivalTime++;
        } else if (command == 1) {
            cin >> name;
            scanf("%d", &infection);
            st.erase(st.find({mp[name].first, mp[name].second, name}));
            st.insert({mp[name].first + infection, mp[name].second, name});
            mp[name] = {mp[name].first + infection, mp[name].second};
        } else if (command == 2) {
            cin >> name;
            st.erase(st.find({mp[name].first, mp[name].second, name}));
            mp.erase(mp.find(name));
        } else {
            if (!st.empty()) {
                tuple<int, int, string> mn = *st.rbegin();
                printf("%s\n", get<2>(mn).c_str());
            } else {
                printf("The clinic is empty\n");
            }
        }
    }
}


int main() {
    auto start = high_resolution_clock::now();
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
    cout << "\n"
            << "Run time : " << duration.count() << " microseconds";
#endif
}
