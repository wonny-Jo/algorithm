#include<iostream>
#include<algorithm>
using namespace std;
int S[21][21];
int N;

int absol(int a)
{
	return a > 0 ? a : -a;
}

int calcDist(bool team[21])
{
	int start = 0, link = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (team[i] == team[j])
			{
				if (team[i] == 0)
					start += S[i][j];
				else
					link += S[i][j];
			}
		}
	}
	return absol(start - link);
}


int makeTeam(bool team[21],int num)
{
	if (num == N)
		return 0;

	int minDist = 40001;
	for (int i = num + 1; i < N; ++i)
	{
		if (!team[i])
		{
			team[i] = 1;
			minDist = min(minDist, calcDist(team));
			minDist = min(minDist, makeTeam(team, num + 1));
			team[i] = 0;
		}
	}
	return minDist;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> S[i][j];

	bool team[21] = { 0 };
	team[0] = 1;
	cout << makeTeam(team, 0);

	return 0;
}