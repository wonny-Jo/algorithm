#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000001
int H[MAX]; //높이 정보

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	vector<int> arrowH; //화살 높이
	for (int i = 0; i < N; ++i)
	{
		bool c = false; //풍선이 터졌는지 여부
		if (!arrowH.empty()) //남은 화살 정보들과 현재 높이를 비교함
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