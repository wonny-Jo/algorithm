#include<iostream>
#include<algorithm>
using namespace std;
int N, K;
int sensor[10001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> sensor[i];
	sort(sensor, sensor + N);

	int dist[10000];
	long long ret = 0;
	for (int i = 0; i < N-1; i++)
		ret += (dist[i] = sensor[i + 1] - sensor[i]);
	sort(dist, dist + N - 1, greater<int>());
	for (int i = 0; i < K-1; i++)
		ret -= dist[i];
	cout << ret;
	return 0;
}