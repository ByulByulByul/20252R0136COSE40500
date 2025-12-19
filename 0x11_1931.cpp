#include <iostream>
#include <string>
#include <vector>
#include <stack>	
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


int n;
vector<pair<int, int>> ts;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ts = vector<pair<int, int>>(n);
	for (int i = 0; i < n; i++)
		cin >> ts[i].second >> ts[i].first;
	::sort(ts.begin(), ts.end());

	vector<pair<int, int>> sol;
	sol.push_back(ts[0]);
	// 끝나는 시간, 시작 시간

	for (int i = 1; i < n; i++)
	{
		if (ts[i].second < sol.back().first)
			continue;
		else
			sol.push_back(ts[i]);
	}

	cout << sol.size() << "\n";

	
	return 0;
}

// 시간 복잡도 : O(NlonN)

