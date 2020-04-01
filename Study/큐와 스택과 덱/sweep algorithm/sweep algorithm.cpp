#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> h; //각 판자의 높이를 저장하는 배열

int solveStack() 
{
	stack<int> remaining; //남아있는 판자들의 위치를 저장함
	h.push_back(0);
	int ret = 0;
	for (int i = 0; i < h.size(); ++i)
	{
		//남은 판자들 중 오른쪽 끝 판자가 h[i]보다 높으면
		//이 판자의 최대 사각형은 i에서 끝난다.
		while (!remaining.empty()&&h[remaining.top()]>=h[i])
		{
			int j = remaining.top();
			remaining.pop();
			int width = -1;
			//i번째 판자 왼쪽에 판자가 하나도 안 남은 경우에는 left[j]=-1
			//아닌 경우는 left[j]=남은 판자중 가장 오른쪽 판자 번호
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