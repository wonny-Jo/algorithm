#include <iostream>
#include <map>
using namespace std;
map<string, int> map1;
map<int, string> map2;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int K, L; cin >> K >> L;
	for (int i = 1; i <= L; i++)
	{
		string s; cin >> s;
		map1[s] = i;
		map2[i] = s;
	}

	int cnt = 0;
	for (int i = 1; i <= L; i++)
	{
		if (i == map1[map2[i]])
		{
			++cnt;
			cout << map2[i] << '\n';
		}
		if (cnt == K)
			break;
	}
	return 0;
}