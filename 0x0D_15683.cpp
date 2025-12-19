#include <iostream>
#include <string>
#include <vector>
#include <stack>	
#include <queue>
#include <deque>


using namespace std;


int n, m, cnt = 100;
int b1[10][10];
int b2[10][10];

void Copy()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b2[i][j] = b1[i][j];
}

void Count()
{
	int temp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (b2[i][j] == 0)
				temp++;
	cnt = ::min(temp, cnt);
}

vector<pair<int, int>> cctvArr;
vector<vector<int>> totalArr;
int condition;
vector<int> total;

			// 3시부터 시계 방향
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void func(int cur)
{
	if (cur == condition)
	{
		totalArr.push_back(total);

		return;
	}

	pair<int, int> pos = cctvArr[cur];
	if (b1[pos.second][pos.first] == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			total[cur] = i;
			func(cur + 1);
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			total[cur] = i;
			func(cur + 1);
		}
	}

}

void cctv(pair<int, int> cur, int dir)
{
	int nx = cur.first + dx[dir];
	int ny = cur.second + dy[dir];

	while (!(nx < 0 || nx >= m || ny < 0 || ny >= n))
	{
		if (b2[ny][nx] == 6)
			break;

		if (b2[ny][nx] == 0)
			b2[ny][nx] = -1;

		ny += dy[dir];
		nx += dx[dir];
	}
}

void solution()
{
	/*
	vector<pair<int, int>> cctvArr;
	vector<vector<int>> totalArr;
	
	*/
	for (int i = 0; i < totalArr.size(); i++)
	{
		vector<int> arr = totalArr[i];

		for (int j = 0; j < cctvArr.size(); j++)
		{
			pair<int, int> cur = cctvArr[j];

			switch (b1[cur.second][cur.first])
			{
			case 1:
				cctv(cur, arr[j]);
				break;

			case 2:
				if (arr[j] == 0)
				{
					cctv(cur, 0);
					cctv(cur, 2);
				}
				else
				{
					cctv(cur, 1);
					cctv(cur, 3);
				}
				break;

			case 3:
				if (arr[j] == 0)
				{
					cctv(cur, 0);
					cctv(cur, 3);
				}
				else if (arr[j] == 1)
				{
					cctv(cur, 0);
					cctv(cur, 1);
				}
				else if (arr[j] == 2)
				{
					cctv(cur, 1);
					cctv(cur, 2);
				}
				else if (arr[j] == 3)
				{
					cctv(cur, 2);
					cctv(cur, 3);
				}
				break;
			case 4:
				if (arr[j] == 0)
				{
					cctv(cur, 0);
					cctv(cur, 3);
					cctv(cur, 2);
				}
				else if (arr[j] == 1)
				{
					cctv(cur, 0);
					cctv(cur, 1);
					cctv(cur, 3);
				}
				else if (arr[j] == 2)
				{
					cctv(cur, 1);
					cctv(cur, 2);
					cctv(cur, 0);
				}
				else if (arr[j] == 3)
				{
					cctv(cur, 2);
					cctv(cur, 3);
					cctv(cur, 1);
				}
				break;
			case 5:
				cctv(cur, 0);
				cctv(cur, 1);
				cctv(cur, 2);
				cctv(cur, 3);

				break;
			}
		}

		Count();
		Copy();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> b1[i][j];
			if (b1[i][j] != 0 && b1[i][j] != 6)
				cctvArr.push_back({ j, i });
		}
	condition = cctvArr.size();
	total = vector<int>(condition, 0);

	func(0);

	solution();
	cout << cnt << "\n";



	return 0;
}
