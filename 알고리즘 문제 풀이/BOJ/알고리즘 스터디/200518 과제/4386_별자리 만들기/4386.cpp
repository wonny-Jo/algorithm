#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
int Parent[101];
double Answer;
vector<pair<double, double>> Coord;
vector<pair<double, pair<int, int>>> Edge;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double a, b; cin >> a >> b;
		Coord.push_back(make_pair(a, b));
	}
}

double Find_Distance(double x, double y, double xx, double yy)
{
	double dx = (x - xx) * (x - xx);
	double dy = (y - yy) * (y - yy);
	double Dist = sqrt(dx + dy);

	return Dist;
}

int Find_Parent(int A)
{
	if (A == Parent[A]) return A;
	else return Parent[A] = Find_Parent(Parent[A]);
}

bool Same_Parent(int A, int B)
{
	A = Find_Parent(A);
	B = Find_Parent(B);
	if (A == B) return true;
	return false;
}

void Union(int A, int B)
{
	A = Find_Parent(A);
	B = Find_Parent(B);

	Parent[B] = A;
}

void Solution()
{
	for (int i = 0; i < Coord.size(); i++)
	{
		double x = Coord[i].first;
		double y = Coord[i].second;

		for (int j = i + 1; j < Coord.size(); j++)
		{
			double xx = Coord[j].first;
			double yy = Coord[j].second;

			double Dist = Find_Distance(x, y, xx, yy);
			Edge.push_back(make_pair(Dist, make_pair(i, j)));
		}
	}

	for (int i = 0; i < N; i++) Parent[i] = i;
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < Edge.size(); i++)
	{
		double Cost = Edge[i].first;
		int Node1 = Edge[i].second.first;
		int Node2 = Edge[i].second.second;

		if (Same_Parent(Node1, Node2) == false)
		{
			Union(Node1, Node2);
			Answer = Answer + Cost;
		}
	}
	cout << Answer << '\n';
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
	cout << fixed;
	cout.precision(2);
	Solve();

	return 0;
}
