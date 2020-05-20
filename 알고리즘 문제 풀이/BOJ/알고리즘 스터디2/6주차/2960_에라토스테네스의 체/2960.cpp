#include<iostream>
using namespace std;
bool c[1001] = { 0 };

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	int cnt = 0;
	for (int i = 2; i <= N; i++)
	{
		if (!c[i])
		{
			int temp = i;
			while (temp <= N)
			{
				if (!c[temp])
				{
					++cnt;
					if (cnt == K)
					{
						cout << temp;
						return 0;
					}
					c[temp] = 1;
				}
				temp += i;
			}
		}
	}

	return 0;
}