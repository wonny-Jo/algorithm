#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
	int data[1500];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	sort(data, data + N);
	for (int i = 0; i < N; i++)
		cout << data[i]<<endl;
	

	return 0;
}