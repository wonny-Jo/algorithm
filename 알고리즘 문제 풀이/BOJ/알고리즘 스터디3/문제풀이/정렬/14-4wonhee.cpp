//3848kb, 76ms
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int data[500001];
	int count[8001] = { 0 };
	double mean = 0;
	bool b_redun = false;
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> data[i];
		++count[data[i] + 4000];
		if (max < count[data[i] + 4000])
		{
			max = count[data[i] + 4000];
			b_redun = false;
		}
		else if (max == count[data[i] + 4000])
			b_redun = true;
		mean += data[i];
	}
	mean /= N;

	int max_count_num;
	for (int i = 0; i < 8001; ++i)
	{
		if (max == count[i])
		{
			if (b_redun == true)
			{
				b_redun = false;
				continue;
			}
			max_count_num = i - 4000;
			break;
		}
	}
	sort(data, data + N);

	cout.precision(0);
	cout << fixed << mean << '\n' << data[N / 2] << '\n' << max_count_num << '\n' << data[N - 1] - data[0];

	return 0;
}