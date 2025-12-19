#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;

	int arr[10] = {};
	for (int i = 0; i < str.length(); i++)
		arr[str[i] - '0']++;

	int cnt = 0;
	for (int i = 0; i < 10; i++)
		if (i == 6 || i == 9)
			continue;
		else
			cnt = std::max(cnt, arr[i]);

	int sixNineCnt = (arr[6] + arr[9] + 1) / 2;
	if (sixNineCnt > cnt)
		cnt = sixNineCnt;

	std::cout << cnt << "\n";

	return 0;
}

// ½Ã°£ º¹Àâµµ : O(N)

