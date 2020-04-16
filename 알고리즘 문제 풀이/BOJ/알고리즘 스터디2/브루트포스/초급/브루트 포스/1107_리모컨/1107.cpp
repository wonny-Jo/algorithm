#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
#define INF 1000001
bool button[10] = { 0 };

bool possible(int n)
{
	if (n == 0)
		return button[0] ? 0 : 1;

	while (n)
	{
		if (button[n % 10] == 1)
			return 0;
		n /= 10;
	}
	return 1;
}

int find(int n)
{
	int init = abs(n - 100);
	int button_min = INF;
	int temp;
	for (int i = 0; i <= INF; ++i)
	{
		if (possible(i))
		{
			temp = to_string(i).length();
			temp += abs(i - n);
			button_min = min(button_min, temp);
		}
	}
	return min(init, button_min);
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a; cin >> a;
		button[a] = 1;
	}
	cout << find(N);

	return 0;
}