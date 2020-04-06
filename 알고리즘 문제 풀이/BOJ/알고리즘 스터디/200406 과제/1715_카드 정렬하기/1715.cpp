#include<iostream>
#include<queue>
using namespace std;

//���� ���� �� �ΰ��� ���ϴ°� ���� ���� ���� �ȴ�.
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	//���� �������� minHeap������ ��������.
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
		pq.push(temp); //���Ѱ��� �ٽ� �־��ִ°� �߿�
		ret += temp;
	}
	cout << ret;
	return 0;
}