#include<iostream>
using namespace std;

int k;
// 찾은 케이스 출력하는 문제
void print(int S[13], bool visited[13])
{
	for (int i = 0; i < k; ++i)
	{
		if (visited[i])
			cout << S[i] << ' ';
	}
	cout << endl;
}
// 모든 케이스 찾는문제
void search(int S[13],bool visited[13],int cnt)
{
	if (cnt == 0)
	{
		print(S, visited);
		return;
	}

	int start = 0;
	for (int i = k - 1; i >= 0; --i)
	{
		if (visited[i])
		{
			start = i+1;
			break;
		}
	}
	for (int i = start; i < k; ++i)
	{
		visited[i] = true;
		search(S, visited, cnt-1);
		visited[i] = false;
	}
}


int main()
{
	while (1)
	{
		cin >> k;
		if (k == 0)
			return 0;
		int S[13];
		for (int i = 0; i < k; ++i)
			cin >> S[i];
		bool visited[13] = { 0 };
		search(S, visited, 6);
		cout << endl;
	}
	return 0;
}