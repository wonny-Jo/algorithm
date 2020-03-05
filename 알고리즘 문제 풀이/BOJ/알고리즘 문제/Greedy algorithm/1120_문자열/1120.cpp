#include <iostream>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int sizeA = a.size(), sizeB = b.size();
	int min = 50;
	int num = sizeB - sizeA;
	for (int i = 0; i <= num; ++i)
	{
		int count = 0;
		for (int j = 0; j < sizeA; ++j)
		{
			if (a[j] != b[i + j])
				++count;
		}
		if (min > count)
			min = count;
	}
	cout << min << endl;
	return 0;
}