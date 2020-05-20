#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int arr[101][101];
int numCnt[101];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c, k; cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];

	if (arr[r][c] == k)
	{
		cout << 0;
		return 0;
	}

	int ret;
	int cnt = 0, row = 3, col = 3;

	while (1)
	{
		if (arr[r][c] == k) { ret = cnt; break; }
		if (cnt > 100) { ret = -1; break; }

		vector<int> size;
		if (row >= col) // 정사각형이거나 세로로긴 형태
		{
			for (int i = 1; i <= row; i++)
			{
				vector<pair<int, int>> v;
				memset(numCnt, 0, sizeof(numCnt));
				for (int j = 1; j <= col; j++) 
					++numCnt[arr[i][j]];
				for (int j = 1; j < 101; j++)
				{
					if (numCnt[j] == 0) continue;
					v.push_back(make_pair(numCnt[j], j));
				}
				sort(v.begin(), v.end());
				for (int j = 1; j <= col; j++) 
					arr[i][j] = 0;
				int idx = 1;
				for (int j = 0; j < v.size(); j++)
				{
					arr[i][idx++] = v[j].second;
					arr[i][idx++] = v[j].first;
				}
				--idx;
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			col = size.back();
		}
		else // 가로로 더 긴꼴
		{
			for (int i = 1; i <= col; i++)
			{
				vector<pair<int, int>> v;
				memset(numCnt, 0, sizeof(numCnt));
				for (int j = 1; j <= row; j++) 
					++numCnt[arr[j][i]];
				for (int j = 1; j < 101; j++)
					if (numCnt[j] != 0)
						v.push_back(make_pair(numCnt[j], j));
				
				sort(v.begin(), v.end());
				for (int j = 1; j <= row; j++) 
					arr[j][i] = 0;
				int idx = 1;
				for (int j = 0; j < v.size(); j++)
				{
					arr[idx++][i] = v[j].second;
					arr[idx++][i] = v[j].first;
				}
				--idx;
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			row = size.back();
		}
		++cnt;
	}
	cout << ret;

	return 0;
}