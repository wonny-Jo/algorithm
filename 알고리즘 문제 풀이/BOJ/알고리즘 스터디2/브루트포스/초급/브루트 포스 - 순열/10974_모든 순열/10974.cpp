#include<iostream>
#include<algorithm>
using namespace std;
int N; 
int arr[10];

void print()
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	
	print();
	while (next_permutation(arr, arr + N))
		print();
	
	return 0;
}