#include<iostream>
using namespace std;

int main()
{
	long long A, B, V;
	cin >> A >> B >> V;
	long  count = 1,dist=A-B;
	V -= A;
	count+=V/dist;
	if (V%dist != 0)
		++count;
	cout << count;
	return 0;
}