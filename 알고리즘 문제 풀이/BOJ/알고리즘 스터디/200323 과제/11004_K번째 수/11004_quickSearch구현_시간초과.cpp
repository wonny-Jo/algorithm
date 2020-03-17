//quick selection or quick search로 구현하면 
//O(n)의 시간복잡도로 구현가능
#include<iostream>
using namespace std;
int arr[5000001];
int N, K;

void Swap(int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// 피벗을 기준으로 작은것은 왼쪽 큰것은 오른쪽으로 나눔
// 반환값은 피벗의 위치
int partition(int start, int end)
{
	int pivot = arr[start]; //피벗은 맨 앞에 있는 값으로 선정
	int left = start + 1;
	int right = end;

	while (left <= right) //왼쪽과 오른쪽 위치가 교차할때까지 반복
	{
		while (pivot >= arr[left] && left <= end) //왼쪽부터 피벗보다 큰 값의 위치를 찾음
			++left;
		while (pivot <= arr[right] && right >= start + 1) //오른쪽부터 피벗보다 작은 값의 위치를 찾음
			--right;
		if (left <= right) //왼쪽과 오른쪽이 교차되지 않았으면 값을 바꿈
			Swap(left, right);
	}
	Swap(start, right); //피벗과 오른쪽의 값을 바꿈 // 오른쪽은 피벗보다 작은 값의 위치이기에
	return right;
}

//피벗을 기준으로 값을 찾되 피벗보다 작은 배열과 피벗보다 큰 배열중
//K가 있는 배열만 다시 진행
int quickSelection(int start, int end)
{
	int pivot = partition(start, end);
	if (pivot == K)
		return arr[pivot];
	else if (pivot > K)
		return quickSelection(start, pivot - 1);
	else if (pivot < K)
		return quickSelection(pivot + 1, end);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	--K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cout << quickSelection(0, N - 1);
	return 0;
}