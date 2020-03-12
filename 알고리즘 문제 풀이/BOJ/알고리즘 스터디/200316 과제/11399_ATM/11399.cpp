#include<iostream>
#include<algorithm>
using namespace std;

//시간이 가장 적게 걸리는사람이 가장 먼저 인출하는것이 전체로 보면 가장 적게 걸린다.
//왜냐하면 먼저 한 사람의 시간은 뒷사람이 계속 누적해서 더하기때문에
//누적되는 횟수를 줄이기 위해서는 시간이 적게걸리는 순으로 인출해야한다.
int main()
{
	int P[1001];
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> P[i];
	sort(P, P + N);

	int time = 0;
	int totalTime = 0;
	for (int i = 0; i < N; ++i)
	{
		time += P[i];//순서대로 걸리는 시간
		totalTime += time;
	}
	cout << totalTime;
	return 0;
}