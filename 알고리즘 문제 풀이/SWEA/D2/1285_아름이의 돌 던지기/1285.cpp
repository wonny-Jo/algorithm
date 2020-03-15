#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int N;
	int pos;
	int minDist;
	int count;
	int distance;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		count = 0;
		minDist = 100000;
		for (int j = 0; j < N; j++)
		{
			cin >> pos;
			distance = (pos > 0) ? pos : -pos;
			if (minDist == distance)
				++count;
			if (minDist > distance)
			{
				minDist = distance;
				count = 1;
			}

		}
		cout << "#" << i + 1 << " " << minDist << " " << count << endl;
	}


	return 0;
}