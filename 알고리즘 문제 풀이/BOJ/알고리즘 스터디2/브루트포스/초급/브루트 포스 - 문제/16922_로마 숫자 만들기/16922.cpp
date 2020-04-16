#include <iostream>
using namespace std;
int N;
bool arr[1001] = { 0 };
int cnt = 0;
bool c[3] = { 0 };

void dfs(int num1, int num5, int num10)
{

	if (num1 + num5 + num10 <= N)
	{
		if (num1 == N)
			c[0] = 1;
		else if (num5 == N)
			c[1] = 1;
		else if (num10 == N)
			c[2] = 1;

		int sum = num1 + 5 * num5 + 10 * num10 + 50 * (N - num1 - num5 - num10);
		if (!arr[sum])
		{
			++cnt;
			arr[sum] = 1;
		}
	}
	else
		return;

	if(!c[0])
		dfs(num1 + 1, num5, num10);
	if(!c[1])
		dfs(num1, num5 + 1, num10);
	if(!c[2])
		dfs(num1, num5, num10 + 1);
}



int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	
	dfs(0, 0, 0);
	cout << cnt;
	return 0;
}