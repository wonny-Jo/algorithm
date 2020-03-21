#include<iostream>
using namespace std;

//10이라는 것은 결국 2와 5의 개수중 작은 것의 개수를 찾는것.
long long min(long long a, long long b)
{
	return a < b ? a : b;
}

pair<long long, long long> zeroNum(long long n)
{
	int twoNum = 0, fiveNum = 0;
	for (long long i = 2; i <= n; i*=2) //빠른 구현을 위해 n이하의 수중에 2로나뉘는것의 개수, 4로나뉘는것의 개수 등의 순서로 빠르게 진행
		twoNum += n / i;
	for (long long i = 5; i <= n; i*=5)
		fiveNum += n / i;
	return { twoNum,fiveNum };
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	long long n, m;
	cin >> n >> m;
	
	pair<long long, long long> p[3];
	p[0] = zeroNum(n); //n!의 2,5의 개수찾기
	p[1] = zeroNum(n - m); //(n-m)!의 2,5의 개수찾기
	p[2] = zeroNum(m); //m!의 2,5의 개수찾기

	long long num2 = p[0].first - p[1].first-p[2].first;
	long long num5 = p[0].second - p[1].second- p[2].second;
	
	cout << min(num2, num5);
	return 0;
}