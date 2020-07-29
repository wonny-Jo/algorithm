//1984kb, 36ms
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int data[1500];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	sort(data, data + N);
	for (int i = 0; i < N; i++)
		cout << data[i] << endl;

	return 0;
}