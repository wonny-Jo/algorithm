#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{

	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n; cin >> n;
		string name[26];
		for (int j = 0; j < n; ++j)
			cin >> name[j];
		int d; cin >> d;
		string data[102];
		cin.clear();
		for (int j = 0; j <= d; ++j)
			getline(cin, data[j]);
		bool check[26] = { 0 };
		for (int j = 0; j <= d; ++j)
		{
			string testData;
			stringstream ss(data[j]);
			while ((ss >> testData))
			{
				for (int k = 0; k < n; ++k)
				{
					if (name[k].compare(testData) == 0)
						check[k] = 1;
				}
			}
		}
		cout << "Test set " << i + 1 << ':' << endl;
		for (int j = 0; j < n; ++j)
		{
			cout << name[j];
			if (check[j] == 1)
				cout << " is present" << endl;
			else
				cout << " is absent" << endl;
		}
		cout << endl;
	}

	return 0;
}