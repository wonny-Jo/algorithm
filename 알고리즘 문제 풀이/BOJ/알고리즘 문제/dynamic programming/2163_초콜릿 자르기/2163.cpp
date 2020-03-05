#include<iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	cout << M - 1 + M * (N - 1); //한쪽 먼저 완전히 쪼개고 나머지 하나씩 쪼갬
	return 0;
}