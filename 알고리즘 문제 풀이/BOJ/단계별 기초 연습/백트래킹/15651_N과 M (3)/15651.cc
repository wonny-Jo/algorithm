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

void search()
{
	if (v.size() == M)
	{
		print();
		return;
	}

	for (int i = 1; i < N+1; ++i)
	{
		v.push_back(i);
		search();
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	search();
	return 0;
}