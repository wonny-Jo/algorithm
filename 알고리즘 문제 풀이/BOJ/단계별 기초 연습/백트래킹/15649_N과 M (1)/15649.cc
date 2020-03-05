#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> v;
bool c[9];

void print()
{
	for (vector<int>::iterator iter = v.begin(); iter !=v.end() ; iter++)
		cout << *iter << ' ';
	cout << "\n";
}

void search()
{
	if (v.size() == M)
	{
		print();
		return;
	}

	for (int i = 1; i < N+1; ++i)
	{
		if (c[i] == 0)
		{
			c[i] = 1;
			v.push_back(i);
			search();
			v.pop_back();
			c[i] = 0;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		c[i] = 0;
	search();
	return 0;
}