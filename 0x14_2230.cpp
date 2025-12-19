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

int n, m;
vector<int> arr;
int mn = INT32_MAX;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n >> m;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	::sort(arr.begin(), arr.end());
	
	int en = 0;
	for (int st = 0; st < n; st++)
	{
		while (en < n && arr[en] - arr[st] < m)
			en++;
		if (en == n)
			break;
		mn = ::min(mn, arr[en] - arr[st]);
	}

	cout << mn;

	
	return 0;
}

// 시간 복잡도 : O(Nrootk)

