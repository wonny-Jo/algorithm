#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int min[2], hour[2];
	int result_min, result_hour;
	for (int i = 0; i < T; i++)
	{
		cin >> hour[0] >> min[0] >> hour[1] >> min[1];
		result_hour = hour[0] + hour[1];
		result_min = min[0] + min[1];
		result_hour += result_min / 60;
		result_min %= 60;
		result_hour %= 12;
		if (result_hour == 0)
			result_hour = 12;
		cout << "#" << i + 1 << " " << result_hour << " " << result_min << endl;
	}

	return 0;
}