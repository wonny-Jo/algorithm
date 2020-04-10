#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	double X, Y; cin >> X >> Y;
	int percent = (Y*100) / X;
	if (percent >= 99)
	{
		cout << -1;
		return 0;
	}

	//percent+1<=100*(Y+result)/(X+result)
	//(X+result)*(percent+1)<=100*(Y+result)
	//X*(percent+1)-100*Y<=(99-percent)*result
	//(X*(percent+1)-100*Y)/(99-percent)<=result

	cout <<(int)ceil((X * (percent + 1) - 100 * Y) / (99 - percent));
	return 0;
}