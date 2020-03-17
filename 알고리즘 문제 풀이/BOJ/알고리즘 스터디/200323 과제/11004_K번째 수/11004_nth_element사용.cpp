//quick selection or quick search로 구현하면 
//O(n)의 시간복잡도로 구현가능
//nth_element는 이를 기반으로 한 함수
#include<iostream>
#include<algorithm>
using namespace std;
int arr[5000001];
int N, K;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	--K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	nth_element(arr, arr + K, arr + N);
	cout << arr[K];
	return 0;
}