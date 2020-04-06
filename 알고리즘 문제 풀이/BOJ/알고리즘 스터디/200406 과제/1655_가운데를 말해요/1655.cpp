#include<iostream>
#include<queue>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	priority_queue<int, vector<int>, less<int>> maxHeap; //�Է¹��� ������ ���� �͵� ���� ����
	priority_queue<int, vector<int>, greater<int>> minHeap; //�Է¹��� ������ ū �͵� ���� ����

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a; cin >> a;
		//���� ������ ¦����� ���ݾ�. 
		//Ȧ����� maxHeap�� �ϳ� �� ����. �̷��� �׻� maxHeap�� top�� ������ �ڸ��� ��ġ�Ѵ�.
		if (maxHeap.size() == minHeap.size()) 
			maxHeap.push(a);
		else
			minHeap.push(a);

		//maxHeap�� minHeap���� ū�� ������ ���� swap
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