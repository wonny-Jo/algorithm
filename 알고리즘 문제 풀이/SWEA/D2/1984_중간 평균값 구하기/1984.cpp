#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	int min, max;
	double sum;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		min = 10000; max = 0; sum = 0;
		int data[10];
		for (int i = 0; i < 10; i++)
		{
			cin >> data[i];
			if (min > data[i])
				min = data[i];
			if (max < data[i])
				max = data[i];
			sum += data[i];
		}
		sum -= min; sum -= max;
		cout << '#' << test_case << ' ' << round(sum / 8) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}