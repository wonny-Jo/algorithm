#include<iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	int a, b;
	while (T--)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}
