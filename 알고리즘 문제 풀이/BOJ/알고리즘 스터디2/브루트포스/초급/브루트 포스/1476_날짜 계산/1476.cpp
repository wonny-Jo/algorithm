#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int E, S, M; cin >> E >> S >> M;
	int result = S;
	while (result % 15 != E % 15 || result % 19 != M % 19)
		result += 28;
	cout << result;
	return 0;
}