#include<iostream>
using namespace std;

//10�̶�� ���� �ᱹ 2�� 5�� ������ ���� ���� ������ ã�°�.
long long min(long long a, long long b)
{
	return a < b ? a : b;
}

pair<long long, long long> zeroNum(long long n)
{
	int twoNum = 0, fiveNum = 0;
	for (long long i = 2; i <= n; i*=2) //���� ������ ���� n������ ���߿� 2�γ����°��� ����, 4�γ����°��� ���� ���� ������ ������ ����
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
	p[0] = zeroNum(n); //n!�� 2,5�� ����ã��
	p[1] = zeroNum(n - m); //(n-m)!�� 2,5�� ����ã��
	p[2] = zeroNum(m); //m!�� 2,5�� ����ã��

	long long num2 = p[0].first - p[1].first-p[2].first;
	long long num5 = p[0].second - p[1].second- p[2].second;
	
	cout << min(num2, num5);
	return 0;
}