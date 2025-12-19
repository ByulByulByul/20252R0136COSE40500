#include <iostream>
#include <string>
#include <vector>
#include <stack>	
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int v, e;

// cost, a, b 순 
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
vector<vector<pair<int, int>>> adj;
vector<bool> chk;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	adj = vector<vector<pair<int, int>>>(v + 1);
	chk = vector<bool>(v + 1, false);

	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		adj[a].push_back({ b, cost });
		adj[b].push_back({ a, cost });
	}

	chk[1] = true;
	for (auto cur : adj[1])
		pq.push({ cur.second, 1, cur.first });
		// cost, a, b 순

	int cnt = 0;
	int ans = 0;
	while (cnt < v - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();

		if (chk[b])
			continue;

		ans += cost;
		chk[b] = true;
		cnt++;

		for (auto nxt : adj[b])
			if (chk[nxt.first] == false)
				pq.push({ nxt.second, b, nxt.first });
	}
	

	cout << ans;

	return 0;
}






