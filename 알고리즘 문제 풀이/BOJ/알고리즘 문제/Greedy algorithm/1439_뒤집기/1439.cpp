#include<iostream>
using namespace std;

int main()
{
	string case1;
	cin >> case1;
	string case2(case1);

	// 다 1로 만드는 경우
	int count_case1 = 0;
	int size = case1.size();
	for (int i = 0; i < size; ++i)
	{
		bool check = false;
		while (case1[i] == '0')
		{
			case1[i] == '1';
			check = true;
			++i;
		}
		if (check)
			++count_case1;
	}

	// 다 0으로 만드는 경우
	int count_case2 = 0;
	for (int i = 0; i < size; ++i)
	{
		bool check = false;
		while (case2[i] == '1')
		{
			case2[i] == '0';
			check = true;
			++i;
		}
		if (check)
			++count_case2;
	}
	int result = count_case1 < count_case2 ? count_case1 : count_case2;
	cout << result;
	return 0;
}