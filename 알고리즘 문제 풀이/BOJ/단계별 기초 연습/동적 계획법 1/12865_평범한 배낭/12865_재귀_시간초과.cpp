#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> v;
int N, K;
int max(int a, int b)
{
	return a > b ? a : b;
}

int search(int num,int sumWeight)
{
	if (num == N)
		return 0;

	int ret = 0;
	for (int i = num; i < N; ++i)
	{
		if (sumWeight + v[i].first <= K)
		{
			ret=max(ret,search(i + 1, sumWeight + v[i].first)+v[i].second);
		}
	}
	return ret;
}



int main()
{
	
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cout << search(0, 0);

	return 0;
}