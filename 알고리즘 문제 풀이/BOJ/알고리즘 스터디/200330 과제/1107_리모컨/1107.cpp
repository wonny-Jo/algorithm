#include<iostream>
#include<string>
using namespace std;
#define INF 1000001

bool button[10] = { 0 };

int absol(int a)
{
	return a > 0 ? a : -a;
}

int Min(int a, int b)
{
	return a < b ? a : b;
}

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
	int init = absol(n - 100);
	int button_min = INF;
	int temp;
	for (int i = 0; i <= INF; ++i)
	{
		if (possible(i))
		{
			temp = to_string(i).length();
			temp += absol(i - n);
			button_min = Min(button_min, temp);
		}
	}
	return Min(init, button_min);
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