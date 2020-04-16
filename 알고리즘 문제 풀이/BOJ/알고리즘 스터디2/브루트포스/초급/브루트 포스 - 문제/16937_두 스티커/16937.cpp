#include<iostream>
#include<vector>
#include<cstring>
#define endl "\n"
#define MAX 100
using namespace std;

int H, W, N, Answer;
bool MAP[MAX][MAX];
bool Select[MAX];
bool Select2[MAX];
vector<pair<pair<int, int>, int>> V;
vector<pair<int, int>> Sticker;

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Input()
{
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		if (a * b >= H * W) continue;

		if (a != b)
		{
			V.push_back(make_pair(make_pair(a, b), i));
			V.push_back(make_pair(make_pair(b, a), i));
		}
		else V.push_back(make_pair(make_pair(a, b), i));
	}
}

void DFS(int Idx, int Cnt)
{
	if (Cnt == 2)
	{
		int x = Sticker[0].first;
		int y = Sticker[0].second;
		int xx = Sticker[1].first;
		int yy = Sticker[1].second;
		int Size = (x * y) + (xx * yy);

		if (x + xx <= H)
		{
			int yyy = Bigger(y, yy);
			if (yyy <= W)
			{
				Answer = Bigger(Answer, Size);
			}
		}

		if (y + yy <= W)
		{
			int xxx = Bigger(x, xx);
			if (xxx <= H)
			{
				Answer = Bigger(Answer, Size);
			}
		}
		return;
	}

	for (int i = Idx; i < V.size(); i++)
	{
		if (Select[i] == true || Select2[V[i].second] == true) continue;
		Select[i] = true;
		Select2[V[i].second] = true;
		Sticker.push_back(make_pair(V[i].first.first, V[i].first.second));
		DFS(i, Cnt + 1);
		Sticker.pop_back();
		Select2[V[i].second] = false;
		Select[i] = false;
	}
}

void Solution()
{
	if (V.size() <= 1)
	{
		cout << 0 << endl;
		return;
	}

	DFS(0, 0);
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
