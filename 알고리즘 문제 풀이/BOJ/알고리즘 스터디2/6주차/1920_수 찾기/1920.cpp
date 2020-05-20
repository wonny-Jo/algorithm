#include<iostream>
#include<algorithm>
using namespace std;
int A[100001];
int N, M;




int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a; cin >> a;
		int low = 0, high = N - 1;
		while (low<=high)
		{
			int mid = (low + high) / 2;
			if (a < A[mid])
				high = mid;
			else if (a > A[mid])
				low = mid + 1;
			else
			{
				cout << 1 << '\n';
				break;
			}
		}
		if (low > high)
			cout << 0 << '\n';
	}

	return 0;
}