#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int x1, y1, x2, y2, r1, r2;
	int testNum;
	double r3;
	cin >> testNum;
	int* result=new int[testNum];
	int i=0;
	while (true)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 >= -10000 && x1 <= 10000
			&& y1 >= -10000 && y1 <= 10000
			&& x2 >= -10000 && x2 <= 10000
			&& y2 >= -10000 && y2 <= 10000 
			&& r1 >0 && r1 < 10000 && r2 >0 && r2 < 10000)
		{
			r3 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			if (r3 == 0 && r1 == r2)
				result[i] = -1;
			else if (r1 + r2 > r3&&r1 + r3 > r2&&r2 + r3 > r1)
				result[i] = 2;
			else if (r1 + r2 == r3 || r1 + r3 == r2 || r2 + r3 == r1)
			{ 
				result[i] = 1;
			}
			else
				result[i] = 0;
			++i;
			if (i == testNum)
				break;
		}
	}
	for (int i = 0; i < testNum; ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}