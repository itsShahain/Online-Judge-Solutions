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
    string command;

    struct customComparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first < b.first
            ? false
            : a.first > b.first
            ? true
            : a.second >= b.second
            ? true
            : false;
        }
    };



    set<
        pair<int, int>,
        customComparator
    > st;

    int E, G, X;

    for(int i = 0; i < N; i++) {
        cin >> command;
        if(command == "add") {
            scanf("%d %d", &E, &G);
            st.insert({E, G});
        } else {
            scanf("%d", &X);
            long long sum = 0;
            auto it = st.begin();
            while(X > 0 && ((it = st.lower_bound({X, INFINITY})) != st.end())) {
                X -= it->first;
                sum += (it->second);
                st.erase(it);
            }
            printf("%ld\n", sum);
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
