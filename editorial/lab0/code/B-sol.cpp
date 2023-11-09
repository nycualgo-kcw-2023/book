#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const vector<T> &a) {
    for (int i = 0, n = a.size(); i < n; ++i) cout << a[i] << " \n"[i == n-1];
}

void solve01(int n, vector<int> a) {
    sort(begin(a), end(a));
    print(a);
}

void solve02(int n, vector<int> a) {
    reverse(begin(a), end(a));
    print(a);
}

void solve03(int n, vector<int> a) {
    n = unique(begin(a), end(a)) - begin(a);
    a.resize(n);
    print(a);
}

void solve04(int n, vector<int> a) {
    partial_sum(begin(a), end(a), begin(a));
    print(a);
}

void solve05(int n, vector<int> a) {
    int min_id = min_element(begin(a), end(a)) - begin(a);
    int max_id = rend(a) - max_element(rbegin(a), rend(a)) - 1;
    cout << min_id << " " << max_id << "\n";
}

void solve06(int n) {
    string s(n, ' ');
    iota(begin(s), end(s), 'a');
    vector<string> a;
    do a.emplace_back(s); while (next_permutation(begin(s), end(s)));
    reverse(begin(a), end(a));
    print(a);
}

void solve07(int n, vector<int> a, vector<int> b) {
    vector<int> c(2*n);
    merge(begin(a), end(a), begin(b), end(b), begin(c));
    print(c);
}

void solve08(int n, vector<int> a, vector<int> b) {
    set<int> st;
    for (int x : a) st.emplace(x);
    vector<int> ans;
    for (int x : b) {
        if (auto it = st.upper_bound(x); it == end(st)) ans.emplace_back(0);
        else ans.emplace_back(*it);
    }
    print(ans);
}

void solve09(int n, vector<int> a) {
    map<int, int> cnt;
    for (int x : a) ++cnt[x];
    vector<int> ans;
    for (int x : a) ans.emplace_back(cnt[x]);
    print(ans);
}

void solve10(int n, vector<int> a) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for (int x : a) {
        if (x == 0 and !pq.empty()) ans.emplace_back(pq.top()), pq.pop();
        else pq.emplace(x);
    }
    print(ans);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        int op, n; cin >> op >> n;
        
        vector<int> a(n), b(n);
        if (op != 6)            {for (int &x : a) cin >> x;}
        if (op == 7 or op == 8) {for (int &x : b) cin >> x;}
        
        switch (op) {
            case  1: solve01(n, a);    break;
            case  2: solve02(n, a);    break;
            case  3: solve03(n, a);    break;
            case  4: solve04(n, a);    break;
            case  5: solve05(n, a);    break;
            case  6: solve06(n);       break;
            case  7: solve07(n, a, b); break;
            case  8: solve08(n, a, b); break;
            case  9: solve09(n, a);    break;
            case 10: solve10(n, a);    break;
        }
    }
    
    return 0;
}
