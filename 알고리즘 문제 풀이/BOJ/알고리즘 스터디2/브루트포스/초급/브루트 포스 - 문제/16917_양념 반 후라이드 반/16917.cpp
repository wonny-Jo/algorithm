#include <iostream>
using namespace std;

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	int NumHalf = (X > Y) ? X : Y;

	int ret = 1000000000;
	while (NumHalf>=0)
	{
		int XNum = (X - NumHalf);
		int YNum = (Y - NumHalf);
		if (XNum < 0)	XNum = 0;
		if (YNum < 0)	YNum = 0;
		int sum = A * XNum + B * YNum + C * NumHalf * 2;
		ret = (ret > sum) ? sum : ret;
		--NumHalf;
	}
	cout << ret;

	return 0;
}