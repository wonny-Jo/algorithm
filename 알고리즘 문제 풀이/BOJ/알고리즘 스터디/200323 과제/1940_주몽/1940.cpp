#include<iostream>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	int arr[15001];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int cnt = 0;
	for (int i = 0; i < N-1; ++i)
		for (int j = i+1; j < N; ++j)
			if (arr[i] + arr[j] == M)
				++cnt;
	cout << cnt;
	return 0;
}