#include <iostream>
#include <string>
#include <vector>
	
using namespace std;

int arr[10000001] = {};
bool nList[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, x;
	int cnt = 0;

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];


	std::cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (x - arr[i] > 0 && nList[x - arr[i]])
			cnt++;
		nList[x - arr[i]] = true;
	}

	std::cout << cnt;

	return 0;
}

// ½Ã°£ º¹Àâµµ : O(N)

