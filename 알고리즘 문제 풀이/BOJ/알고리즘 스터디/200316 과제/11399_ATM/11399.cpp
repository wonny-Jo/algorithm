#include<iostream>
#include<algorithm>
using namespace std;

//�ð��� ���� ���� �ɸ��»���� ���� ���� �����ϴ°��� ��ü�� ���� ���� ���� �ɸ���.
//�ֳ��ϸ� ���� �� ����� �ð��� �޻���� ��� �����ؼ� ���ϱ⶧����
//�����Ǵ� Ƚ���� ���̱� ���ؼ��� �ð��� ���԰ɸ��� ������ �����ؾ��Ѵ�.
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
		time += P[i];//������� �ɸ��� �ð�
		totalTime += time;
	}
	cout << totalTime;
	return 0;
}