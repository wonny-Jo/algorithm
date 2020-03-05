#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	long long N;
	cin >> N;
	int result[9];
	int count = 0;
	while (N)
	{
		result[count] = N % 10;
		N /= 10;
		++count;
	}
	sort(result, result + count);

	for (int i = count-1; i >= 0; --i)
		cout << result[i];

	return 0;
}