#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long length[3];
	cin >> length[0] >> length[1] >> length[2];
	long long temp;
	while (length[0] != 0)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (length[i] > length[i + 1])
				{
					temp = length[i + 1];
					length[i + 1] = length[i];
					length[i] = temp;
				}
			}
		}

		if (length[0]* length[0] + length[1] * length[1] == length[2] * length[2])
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

		cin >> length[0] >> length[1] >> length[2];
	}
	return 0;
}