#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int n; cin >> n;
		vector<string> pk1,pk2, ct;
		int arr[1001]; //암호문 순서를 저장하는 배열
		string s;
		for (int j = 0; j < n; ++j)
		{
			cin >> s; pk1.push_back(s);
		}
		for (int j = 0; j < n; ++j)
		{
			cin >> s; pk2.push_back(s);
		}
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (pk1[j] == pk2[k])
				{
					arr[j] = k;
					pk2[k] = " ";
					break;
				}
			}
		}
		for (int j = 0; j < n; ++j)
		{
			cin >> s;
			ct.push_back(s);
		}
		for (int j = 0; j < n; ++j)
			cout << ct[arr[j]] << ' ';
		cout<<endl;
	}
	return 0;
}