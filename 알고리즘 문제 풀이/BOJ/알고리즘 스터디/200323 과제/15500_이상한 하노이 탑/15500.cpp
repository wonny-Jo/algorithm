#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(vector<pair<int, int>> v)
{
	int size = v.size();
	cout << size << '\n';
	for (int i = 0; i < size; ++i)
		cout << v[i].first << ' ' << v[i].second << '\n';
}
int main()
{
	int N;
	cin >> N;
	int arr[124] = { 0 }; //각 값들이 어디에 저장되어있는지 나타내는 배열
	int a;
	vector<pair<int, int>> v;//움직임을 저장할 벡터
	stack<int> s[4]; //각 위치에 저장할 스택

	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		arr[a] = 1;
		s[1].push(a);
	}

	//아이디어 : 제일 큰 수만 찾아서 3으로 순서대로 옮기면됨
	//만약 제일 큰 수가 아니라면 다른 곳으로 옮기면됨
	//ex) 1의 위치에 있었으면 2로, 2의 위치에 있었으면 1로 옮김
	while (N>0)
	{
		if (arr[N] == 1)
		{
			if (s[1].top() == N)
			{
				v.push_back({ 1,3 });
				s[3].push(s[1].top());
				s[1].pop();
				arr[N] = 3;
				--N;
			}
			else
			{
				v.push_back({ 1,2 });
				s[2].push(s[1].top());
				s[1].pop();
				arr[s[2].top()] = 2;
			}
		}
		else if (arr[N] == 2)
		{
			if (s[2].top() == N)
			{
				v.push_back({ 2,3 });
				s[3].push(s[2].top());
				s[2].pop();
				arr[N] = 3;
				--N;
			}
			else
			{
				v.push_back({ 2,1 });
				s[1].push(s[2].top());
				s[2].pop();
				arr[s[1].top()] = 1;
			}
		}
	}

	print(v);

	return 0;
}