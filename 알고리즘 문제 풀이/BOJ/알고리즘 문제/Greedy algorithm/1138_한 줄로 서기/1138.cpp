#include <iostream>
using namespace std;

int main()
{
	int tallerNum[20] = { 0 };
	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> tallerNum[i];
	int pos[20] = { 0 };
	for (int i = 1; i <= N; ++i)
	{
		int temp = 1;
		int count = 0;
		while (pos[temp] || count != tallerNum[i])
		{
			if (!pos[temp])
				++count;
			++temp;
			
		}
		pos[temp] = i;
	}
	for (int i = 1; i <= N; ++i)
		cout << pos[i] << ' ';
	return 0;
}