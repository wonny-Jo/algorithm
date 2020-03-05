#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	string number;
	cin >> number;
	deque<char> deq;

	for (int i = 0; i < N; ++i)
	{
	 	while (K && !deq.empty() && deq.back() < number[i])
		{
			deq.pop_back();
			--K;
		}
		deq.push_back(number[i]);
	}
	int size = deq.size();
	for (int i = 0; i <size-K; ++i)
		cout << deq[i];
	

	return 0;
}