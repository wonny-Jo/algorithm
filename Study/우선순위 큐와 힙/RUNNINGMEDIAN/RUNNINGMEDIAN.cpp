#include<iostream>
#include<queue>
using namespace std;

struct RNG
{
	int seed, a, b;
	RNG(int _a, int _b ) : a(_a),b(_b),seed(1983){}
	int next()
	{
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};


// rng�� �����ϴ� ù n���� ������ ������ �߰��ϸ� �߰� ���� ����
int runningMedian(int n, RNG rng)
{
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0;

	//�ݺ��� �Һ���:
	//1. maxHeap�� ũ��� minHeap�� ũ��� ���ų� �ϳ� �� ŭ
	//2. maxHeap.top()<=minHeap.top()

	for (int cnt = 1; cnt <= n; ++cnt)
	{
		//�켱 1�� �Һ����� �����Ѵ�.
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());

		//2�� �Һ����� ������ ��� ������Ʈ
		if (!minHeap.empty() && !maxHeap.empty() &&
			minHeap.top() < maxHeap.top())
		{
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}



int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int C; cin >> C;
	for (int i = 0; i < C; ++i)
	{
		int N, a, b; cin >> N >> a >> b;
		RNG rng(a,b);
		cout << runningMedian(N, rng) << endl;
	}

	return 0;
}