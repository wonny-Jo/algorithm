#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N, K; cin >> N >> K;
	string s;
	vector<int> size[21];
	for (int i = 0; i < N; ++i)//글자 수대로 위치를 순서대로 벡터에 넣음
	{
		cin >> s;
		size[s.size()].push_back(i);
	}

	int ret = 0;
	for (int i = 0; i <= 20; ++i)//글자수
	{
		if (size[i].empty())
			continue;

		queue<int> q;
		for (int j = 0; j < size[i].size(); ++j)
		{
			//새로 들어올 위치와 이전에 저장된 위치들 간에 K이상 차이나는 것들은 제거
			while(!q.empty()&& size[i][j] - q.front() > K) 
				q.pop();
			ret += q.size(); //q에 남은 것들이 새로 들어오는 위치와 쌍을 이루는 갯수
			q.push(size[i][j]);
		}
	}
	cout << ret;
	return 0;
}