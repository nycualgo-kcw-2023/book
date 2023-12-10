#include <iostream>
#include <vector>
#include <queue>

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define val first
#define idx second

using namespace std;
using ll = long long;
using pli = pair<ll, int>;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k, rating;
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	/**************** input ****************/
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> rating;
		pq.push({rating, i});
	}

	/**************** build schedule ****************/
	vector<vector<int>> battles;
	ll ans = 0;
	int nodeIdx = n;
	while (pq.size() != 1) // until only one member left
	{
		ll sum = 0;												 // value of the new battle
		battles.push_back({});									 // new battle
		while (battles.back().size() < 2 || pq.size() % (k - 1)) // put the k' smallest nodes into battles
		{
			pli node = pq.top();
			pq.pop();
			sum += node.val;
			battles.back().push_back(node.idx);
		}
		ans += sum;
		pq.push({sum, ++nodeIdx});
	}

	/**************** output ****************/
	cout << ans << '\n';
	cout << battles.size() << '\n';
	for(int i = 0; i < battles.size(); i++)
	{
		cout << battles[i].size() << ' ';
		for(int j = 0; j < battles[i].size(); j++)
		{
			cout << battles[i][j] << " \n"[j == battles[i].size() - 1];
		}
	}
	return 0;
}