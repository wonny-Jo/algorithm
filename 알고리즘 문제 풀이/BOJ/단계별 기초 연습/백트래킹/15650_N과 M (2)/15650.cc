#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> v;

void print()
{
	for (vector<int>::iterator iter = v.begin(); iter !=v.end() ; iter++)
		cout << *iter << ' ';
	cout << "\n";
}

void search(int num)
{
	if (v.size() == M)
	{
		print();
		return;
	}
	if (num == N + 1)
		return;

	for (int i = num; i < N+1; ++i)
	{
		v.push_back(i);
		search(i + 1);
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	search(1);
	return 0;
}