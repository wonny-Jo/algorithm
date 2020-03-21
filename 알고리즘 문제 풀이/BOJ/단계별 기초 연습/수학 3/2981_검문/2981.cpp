#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
	return a % b ? gcd(b, a % b) : b;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	int arr[101];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	//M의 범위는 두번째인 arr[1]보다 작다.
	//arr[n]-arr[n-1], arr[n-1]-arr[n-2] ... 들은 모두 M을 약수로 가진다.
	//즉 최대의 M을 찾고 이후에 M의 약수들을 찾는다면 답이 될것이다.
	
	int temp = arr[1] - arr[0];
	for (int i = 1; i < N-1; ++i)
		temp = gcd(temp, arr[i + 1] - arr[i]); //temp는 최대공약수
	
	vector<int> result;
	result.push_back(temp);
	int i;
	for (i = 2; i*i < temp; ++i) //최대공약수의 약수들 모두 출력
	{
		if (temp % i == 0)
		{
			result.push_back(i);
			result.push_back(temp / i);
		}
	}
	if (i * i == temp)
		result.push_back(i);
	
	sort(result.begin(), result.end());
	for (i = 0; i < result.size(); ++i)
		cout << result[i] << ' ';
	
	return 0;
}