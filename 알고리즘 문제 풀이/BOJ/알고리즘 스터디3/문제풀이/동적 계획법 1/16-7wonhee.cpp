//1988kb, 0ms
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int point[302];
int result[302][2]; //0은 한칸 전것을 가져온것, 1은 두칸 전것을 가져온것

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	point[0] = 0;
	for (int i = 1; i <= N; ++i)
		cin >> point[i];
	result[0][0] = 0; result[0][1] = 0;
	result[1][0] = result[1][1] = point[1];
	result[2][0] = result[2][1] = result[1][0] + point[2];
	for (int i = 2; i <= N; ++i)
	{
		result[i][0] = point[i] + result[i - 1][1];
		result[i][1] = point[i] + max(result[i - 2][0], result[i - 2][1]);
	}
	cout << max(result[N][0], result[N][1]);
	return 0;
}