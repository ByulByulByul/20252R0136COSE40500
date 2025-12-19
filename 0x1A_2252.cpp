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

int n, m;
queue<int> q;
vector<vector<int>> node;
vector<int> deg;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	node = vector<vector<int>>(n + 1);
	deg = vector<int>(n + 1, 0);

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;

		node[u].push_back(v);
		deg[v]++;
	}

	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			q.push(i);

	while (q.empty() == false)
	{
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < node[cur].size(); i++)
		{
			int nxt = node[cur][i];
			deg[nxt]--;

			if (deg[nxt] == 0)
				q.push(nxt);
		}
	}



	return 0;
}


// 문제점 1. 아무런 부모가 없는 간선이 먼저 들어온다면 어떻게 처리해야 하는가
// 이론 1) first, second를 크기 순으로 정렬해서 시작했지만 그것도 실패함. 


