#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int a, b; cin >> a >> b;
	int ret = 0; //0- 아무것도 아님 , 1- 배수 , 2- 약수
	while (a != 0 || b != 0)
	{
		ret = 0;
		if (a > b)
		{
			if (a == b * (a / b))
				ret = 1;
		}
		else
		{
			if (b == a * (b / a))
				ret = 2;
		}

		if (ret == 1)
			cout << "multiple" << endl;
		else if (ret == 2)
			cout << "factor" << endl;
		else
			cout << "neither" << endl;

		cin >> a >> b;
	}

	return 0;
}