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
    string s;
    vector<string> words;
    while(getline(cin, s), s != "END") {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] < 'a' || s[i] > 'z') {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        string temp;
        while(ss >> temp) {
            words.push_back(temp);
        }
    }
    unordered_set<string> used;

    for(int i = 0; i < words.size(); i++) {
        used.insert(words[i]);
    }

    struct customComparator {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first < b.first
            ? false
            : a.first > b.first
            ? true
            : a.second.first < b.second.second
            ? false
            : true;
        }
    };

    unordered_set<string> curr;
    unordered_map<string, int> wordCounts;
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        customComparator
    > pq;

    int low = 0, high = 0;

    while(low < words.size() && high < words.size()) {
        curr.insert(words[high]);
        wordCounts[words[high]]++;
        if(curr.size() < used.size()) {
            high++;
        } else {
            // curr.size() == words.size()
            while(low < high) {
                if(wordCounts[words[low]] > 1) {
                    wordCounts[words[low]]--;
                    low++;
                } else break;
            }
            // process high, low
            pq.push({high - low, {low, high}});
            high++;

        }
    }
    pair<int, pair<int, int>> ans = pq.top();
    printf("%d %d\n", ans.second.first + 1, ans.second.second + 1);
}

void solve() {
    int TC;
    scanf("%d", &TC);
    scanf("%*c");

    for(int i = 0; i < TC; i++) {
        printf("Document %d: ", i + 1);
        tc();
    }
}


int main() {
    auto start = high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(0);
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
