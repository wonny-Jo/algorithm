#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		cout << '#' << i + 1 << ' ';
		if (N % 2 == 1)
			cout << N / 2 + 1 << endl;
		else
			cout << -N / 2 << endl;
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}