#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;
struct Line {
    int x, y, val;
};
vector<Line> line;

int ans[maxn] = {};
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        line.push_back({l, r, x});
    }
    sort (line.begin(), line.end(), [](Line a, Line b) {
        return a.x < b.x;
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        while (pq.size() && pq.top().first < line[i].x) {
            mx = max(mx, ans[pq.top().second]);
            pq.pop();
        }
        ans[i] = mx + line[i].val;
        pq.push({line[i].y, i});
    }
    cout << *max_element(ans, ans + n) << '\n';
}
