#include<iostream>
#include<queue>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	priority_queue<int, vector<int>, less<int>> maxHeap; //입력받은 수열중 작은 것들 절반 저장
	priority_queue<int, vector<int>, greater<int>> minHeap; //입력받은 수열중 큰 것들 절반 저장

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a; cin >> a;
		//수의 개수가 짝수라면 절반씩. 
		//홀수라면 maxHeap이 하나 더 가짐. 이래야 항상 maxHeap의 top이 절반의 자리에 위치한다.
		if (maxHeap.size() == minHeap.size()) 
			maxHeap.push(a);
		else
			minHeap.push(a);

		//maxHeap에 minHeap보다 큰게 있으면 서로 swap
		if (!maxHeap.empty()&&!minHeap.empty()&&maxHeap.top() > minHeap.top())
		{
			int x = maxHeap.top(), y = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(y); minHeap.push(x);
		}
		cout << maxHeap.top() << '\n';
	}

	return 0;
}