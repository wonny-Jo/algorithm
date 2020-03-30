#include<iostream>
#include<stack>
using namespace std;

int absolNum(int num)
{
	return num > 0 ? num : -num;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n; cin >> n;
		int arr[101][3] = { 0 };//x,y,check
		for (int i = 0; i < n + 2; ++i)
			cin >> arr[i][0] >> arr[i][1];

		//dfs
		arr[0][2] = 1;
		stack<pair<int, int>> s;
		s.push({ arr[0][0],arr[0][1] });

		while (!s.empty())
		{
			int y = s.top().first;
			int x = s.top().second;
			s.pop();
			for (int i = 0; i < n + 2; ++i)
			{
				if (arr[i][2] == 0 &&
					(absolNum(y - arr[i][0]) + absolNum(x - arr[i][1]) <= 1000))
				{
					arr[i][2] = 1;
					s.push({ y,x });
					s.push({ arr[i][0],arr[i][1] });
					break;
				}
			}
		}

		if (arr[n + 1][2])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}