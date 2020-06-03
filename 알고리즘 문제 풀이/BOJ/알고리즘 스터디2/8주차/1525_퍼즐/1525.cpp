#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
int m[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isRange(int y, int x)
{
	if (y < 0 || y >= 3 || x < 0 || x >= 3)
		return false;
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int start = 0; //시작 배열
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;

			//빈 칸을 9로 표시
			if (num == 0)
				num = 9;
			start = start * 10 + num;
		}

	queue<int> q;
	map<int, int> c; //방문한것 체크
	q.push(start);
	c[start] = 0; //체크 및 카운트

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		if (a == 123456789)
			break;

		string s = to_string(a);
		int blank_pos = s.find('9'); //9의 위치가 비어있는 칸

		//9의 좌표 저장
		int y = blank_pos / 3;
		int x = blank_pos % 3;
		for (int i = 0; i < 4; i++)
		{
			//다음 이동 위치 찾기
			int nextY = y + m[i][0];
			int nextX = x + m[i][1];

			if (isRange(nextY, nextX))
			{
				string temp = s;
				swap(temp[y * 3 + x], temp[nextY * 3 + nextX]); //자리 바꾸기
				int next = stoi(temp);
				if (c.count(next) == 0)
				{
					c[next] = c[a] + 1;
					q.push(next);
				}
			}
		}
	}

	if (c.count(123456789) == 0)
		cout << -1;
	else
		cout << c[123456789];

	return 0;
}
