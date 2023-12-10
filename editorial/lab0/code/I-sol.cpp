#include "1608.h"
#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> itv;

void init(int n, vector<int> a) {
    sort(begin(a), end(a));
    for (int x : a) {
        if (!itv.empty() and x == itv.back().second + 1) ++itv.back().second;
        else itv.emplace_back(x, x);
    }
}

int remove_min() {
    int ans = itv[0].first++;
    if (itv[0].first > itv[0].second) itv.pop_front();
    return ans;
}

int remove_max() {
    int ans = itv.back().second--;
    if (itv.back().first > itv.back().second) itv.pop_back();
    return ans;
}

int insert_mex() {
    if (itv.empty() or itv[0].first > 1) {
        itv.emplace_front(0, 0);
        return 0;
    }
    else if (itv[0].first == 1) {
        itv[0].first = 0;
        return 0;
    }
    else {
        int ans = ++itv[0].second;
        if ((int)itv.size() >= 2 and itv[0].second + 1 == itv[1].first) itv.pop_front(), itv[0].first = 0;
        return ans;
    }
}
