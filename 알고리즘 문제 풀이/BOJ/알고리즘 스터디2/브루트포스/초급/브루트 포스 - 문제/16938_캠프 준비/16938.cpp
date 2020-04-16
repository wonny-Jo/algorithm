#include<iostream>
#include<vector>
#define endl "\n"
#define MAX 15
using namespace std;
int N, L, R, X, Answer;
int Problem_Level[MAX];
bool Select[MAX];
vector<int> V;

void Input()
{
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
	{
		cin >> Problem_Level[i];
	}
}

void DFS(int Idx, int Cnt, int Level_Sum)
{
	if (Cnt >= 2)
	{
		int Min = 987654321;
		int Max = -987654321;
		int Sum = 0;

		for (int i = 0; i < V.size(); i++)
		{
			Sum = Sum + Problem_Level[V[i]];
			if (Problem_Level[V[i]] < Min) Min = Problem_Level[V[i]];
			if (Problem_Level[V[i]] > Max) Max = Problem_Level[V[i]];
		}

		if (L <= Sum && Sum <= R && Max - Min >= X) Answer++;
	}

	for (int i = Idx; i < N; i++)
	{
		if (Select[i] == true) continue;

		if (Level_Sum + Problem_Level[i] <= R)
		{
			Select[i] = true;
			V.push_back(i);
			DFS(i, Cnt + 1, Level_Sum + Problem_Level[i]);
			V.pop_back();
			Select[i] = false;
		}
	}
}

void Solution()
{
	DFS(0, 0, 0);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Solve();

	return 0;
}
