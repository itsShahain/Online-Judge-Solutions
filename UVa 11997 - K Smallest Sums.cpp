#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void merge(vector<int>& nums1, vector<int> nums2, int k) {
    priority_queue<
        pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >,
        greater<pair<int, pair<int, int> > >
    > pq;

    for (int i = 0; i < nums1.size(); i++) {
        pq.push({nums1[i] + nums2[0], {i, 0}});
    }

    vector<int> ans;
    while (k--) {
        pair<int, pair<int, int> > tp = pq.top();
        pq.pop();
        int i = tp.second.first, j = tp.second.second;
        ans.push_back(tp.first);
        if (j + 1 < nums2.size()) pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
    }
    nums1 = ans;
}

void solve(int k) {
    vector<int> A(k), B(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &B[j]);
        }
        sort(B.begin(), B.end());
        merge(A, B, k);
    }

    for(int i = 0; i < k; i++) {
        printf("%d", A[i]);
        if(i < k - 1) printf(" ");
    }
}

int main() {
    // setIO("test");
    int k;
    while (scanf("%d", &k) != EOF) {
        solve(k);
        printf("\n");
    }
}
