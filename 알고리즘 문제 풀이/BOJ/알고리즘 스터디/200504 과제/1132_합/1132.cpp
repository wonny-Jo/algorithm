#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N;
string s[51];
int cnt[13][11] = { 0 };
int alpha[11];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
			++cnt[11 - j][s[i][s[i].size() - j - 1] - 'A']; //���ڸ��� ���ĺ� ���� ��
	}

	long long priority[11] = { 0 }; //�� ���ĺ��� �켱���� üũ
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			priority[j] *= 10;
			priority[j] += cnt[i][j]; 
		}
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //��,��ġ
	for (int i = 0; i < 10; i++)
		if (priority[i])
			pq.push({ priority[i],i });

	if (pq.size() != 10) //0�� ���ʿ� ���� ���
	{
		int num = 10 - pq.size();
		while (!pq.empty())
		{
			alpha[pq.top().second] = num++;
			pq.pop();
		}
	}
	else //0�� ���Ǵ� ���
	{
		bool canNotBeZero[10] = { 0 };
		for (int i = 0; i < N; i++)
			canNotBeZero[s[i][0] - 'A'] = 1;

		//zero�� �� ���ִ� ���� ���� ��ġ ã��
		int num = 1;
		bool findZero = false;
		while (!pq.empty())
		{
			if (!canNotBeZero[pq.top().second] && !findZero)
			{
				alpha[pq.top().second] = 0;
				findZero = true;
			}
			else
				alpha[pq.top().second] = num++;
			pq.pop();
		}
	}

	long long ret = 0;
	for (int i = 0; i < N; i++)
	{
		long long sum = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			sum *= 10;
			sum += alpha[s[i][j] - 'A'];
		}
		ret += sum;
	}
	cout << ret;


	return 0;
}
