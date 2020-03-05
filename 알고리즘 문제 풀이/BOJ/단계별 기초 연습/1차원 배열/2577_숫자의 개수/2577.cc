#include<iostream>
using namespace std;




int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int multi = A*B*C;
	int digitNum[10] = { 0 };
	int digit;
	while (true)
	{
		if (multi == 0)
			break;
		digit = multi % 10;
		multi /= 10;
		switch (digit)
		{
		case 0:
			++digitNum[0];	break;
		case 1:
			++digitNum[1];	break;
		case 2:
			++digitNum[2];	break;
		case 3:
			++digitNum[3];	break;
		case 4:
			++digitNum[4];	break;
		case 5:
			++digitNum[5];	break;
		case 6:
			++digitNum[6];	break;
		case 7:
			++digitNum[7];	break;
		case 8:
			++digitNum[8];	break;
		case 9:
			++digitNum[9];	break;
		default:
			break;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << digitNum[i] << endl;
	return 0;
}
