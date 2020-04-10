#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int S[21][21];
int N;
int minDist = 40001;
vector<int>start, link;

int absol(int a)
{
	return a > 0 ? a : -a;
}

int calcDist()
{
	int startSum = 0, linkSum = 0;
	for (int i = 0; i < N/2; ++i)
	{
		for (int j = 0; j < N/2; ++j)
		{
			startSum += S[start[i]][start[j]];
			linkSum += S[link[i]][link[j]];
		}
	}
	return absol(startSum-linkSum);
}


void makeTeam(int num)
{
	if (start.size() == N / 2 && link.size() == N / 2)
		minDist = min(minDist, calcDist());
	
	if (num == N)
		return;

	start.push_back(num);
	makeTeam(num + 1);
	start.pop_back();

	link.push_back(num);
	makeTeam(num + 1);
	link.pop_back();
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

	makeTeam(0);
	cout << minDist;
	return 0;
}