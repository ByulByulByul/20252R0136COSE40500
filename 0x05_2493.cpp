#include <iostream>
#include <string>
#include <vector>
#include <stack>	

using namespace std;

stack<pair<int, int>> st;
vector<int> height;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	std::cin >> n;

	st.push({ 0, INT32_MAX });
	for (int i = 0; i < n; i++)
	{
		int h;
		std::cin >> h;

		while (st.top().second < h)
			st.pop();

		height.push_back(st.top().first);
		st.push({ i + 1, h });
	}

	for (int idx : height)
		std::cout << idx << " ";


	return 0;
}
