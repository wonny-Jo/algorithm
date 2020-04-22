#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		int n; cin >> n;
		int arr[100001];
		for (int i = 1; i <= n; i++) //다음 위치 지정
			cin >> arr[i];
		bool visit[100001] = { 0 }; //해당 위치를 방문한 적이 있는가
		int ret[100001] = { 0 }; //서클 이루면 1, 아니면 -1
		for (int i = 1; i <= n; i++)
		{
			if (ret[i]==0) //아직 서클인지 아닌지 모르는 상태
			{
				vector<int> v; //시작점부터 연결된 순서를 저장
				v.push_back(i);
				visit[i] = 1;
				int next = arr[i];
				while (1)
				{
					if (visit[next]) 
					//다음 위치가 이미 방문한 적이 있다면 둘중 하나
					//1. 처음부터 완전한 서클
					//2. 중간부터 서클(이미 완성된 서클에 접근하는 경우도 있다.)
					{
						int ans = -1; //결국 마지막 위치가 접근하는 위치부터 서클을 이루고 그 이전에는 서클을 이루지 못함.
						for (int i = 0; i < v.size(); i++)
						{
							if (v[i] == next)
								ans = 1;
							ret[v[i]] = ans;
						}
						break;
					}
					v.push_back(next);
					visit[next] = 1;
					next = arr[next];
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ret[i] == -1)
				++cnt;
		}
		cout << cnt << '\n';
	}

	return 0;
}