#include<iostream>
#include<queue>
using namespace std;

//가장 작은 수 두개를 더하는게 가장 작은 합이 된다.
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	//가장 작은것을 minHeap구조로 가져오자.
	priority_queue<int, vector<int>, greater<int>> pq;
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a; cin >> a;
		pq.push(a);
	}
	int ret = 0;
	for (int i = 0; i < N-1; ++i)
	{
		int temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		pq.push(temp); //더한것을 다시 넣어주는게 중요
		ret += temp;
	}
	cout << ret;
	return 0;
}