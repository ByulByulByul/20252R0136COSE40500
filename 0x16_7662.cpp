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

multiset<int> s;
int t, k;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> k;

		for (int j = 0; j < k; j++)
		{
			char ch;
			int n;

			cin >> ch >> n;

			if (ch == 'I')
			{
				s.insert(n);
			}
			else if(s.empty() == false)
			{
				int f;
				if (n == -1)
					f = *(s.begin());
				else
					f = *(--s.end());

				auto it = s.find(f);
				s.erase(f);
			}
		}


		if (s.empty())
			cout << "EMPTY\n";
		else
		{
			if(s.begin() == --s.end())
				cout << *(s.begin()) << " " << *(s.begin()) << "\n";
			else
				cout << *(--s.end()) << " " << * (s.begin()) << "\n";
		}
		s.clear();
	}


	return 0;
}
// 매우 비효율 적이었다. 1년 전의 나보다. 더 성장할 수 있도록 노력하자. 

