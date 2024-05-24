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
    long long N;
    scanf("%lld", &N);

    priority_queue<
        long long,
        vector<long long>,
        greater<long long>
    > pq;

    for(long long i = 1; i <= sqrt(N); i++) {
        if(N % i == 0) {
            pq.push(i - 1);
            if(i != sqrt(N)) pq.push((N / i) - 1LL);
        }
    }

    while(!pq.empty()) {
        printf("%lld ", pq.top()); pq.pop();
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
