#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void solve() {
}

int main() {
    // setIO("test");
    int n;
    scanf("%d", &n);
    map<
        vector<int>,
        int> mp;
    vector<int> tmp(5);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &tmp[j]);
        }
        sort(tmp.begin(), tmp.end());
        if(mp.find(tmp) == mp.end()) {
            mp.insert({tmp, 1});
        } else {
            mp[tmp]++;
        }
    }
    int ans = INT_MIN;
    map<int, int> courses;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        if(courses.find(it->second) == courses.end()) {
            courses.insert({it->second, 1});
        } else {
            courses[it->second]++;
        }
    }

    ans = courses.rbegin()->first * courses.rbegin()->second;
    printf("%d\n", ans);
}
