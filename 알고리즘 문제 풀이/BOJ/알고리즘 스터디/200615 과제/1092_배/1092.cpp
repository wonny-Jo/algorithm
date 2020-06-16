#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	int w[51];
	for (int i = 0; i < N; i++)
		cin >> w[i];
	sort(w, w + N, greater<int>());
	int M; cin >> M;
	vector<int> boxW;
	int num;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		boxW.push_back(num);
	}
	sort(boxW.begin(), boxW.end(), greater<int>());

	if (w[0] < boxW[0]) //못옮기는 경우
	{
		cout << -1;
		return 0;
	}

	int ret = 0, i;
	while (!boxW.empty())
	{
		i = 0;
		for (int j = 0; j < boxW.size(); j++)
		{
			if (i == N)
				break;

			if (w[i] >= boxW[j])
			{
				boxW.erase(boxW.begin() + j--);
				++i;
			}
		}
		++ret;
	}
	cout << ret;

	return 0;
}