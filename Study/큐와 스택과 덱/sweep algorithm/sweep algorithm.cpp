#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> h; //�� ������ ���̸� �����ϴ� �迭

int solveStack() 
{
	stack<int> remaining; //�����ִ� ���ڵ��� ��ġ�� ������
	h.push_back(0);
	int ret = 0;
	for (int i = 0; i < h.size(); ++i)
	{
		//���� ���ڵ� �� ������ �� ���ڰ� h[i]���� ������
		//�� ������ �ִ� �簢���� i���� ������.
		while (!remaining.empty()&&h[remaining.top()]>=h[i])
		{
			int j = remaining.top();
			remaining.pop();
			int width = -1;
			//i��° ���� ���ʿ� ���ڰ� �ϳ��� �� ���� ��쿡�� left[j]=-1
			//�ƴ� ���� left[j]=���� ������ ���� ������ ���� ��ȣ
			if (remaining.empty())
				width = i;
			else
				width = (i - remaining.top() - 1);
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		h.push_back(a);
	}

	cout << solveStack();

	return 0;
}