#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000001
int H[MAX]; //���� ����

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	vector<int> arrowH; //ȭ�� ����
	for (int i = 0; i < N; ++i)
	{
		bool c = false; //ǳ���� �������� ����
		if (!arrowH.empty()) //���� ȭ�� ������� ���� ���̸� ����
		{
			for (int j = 0; j < arrowH.size(); ++j)
			{
				if (arrowH[j] == H[i])
				{
					--arrowH[j];
					c = true;
					break;
				}
			}
		}
		
		if(!c)
			arrowH.push_back(H[i] - 1);

	}
	cout << arrowH.size();
	return 0;
}