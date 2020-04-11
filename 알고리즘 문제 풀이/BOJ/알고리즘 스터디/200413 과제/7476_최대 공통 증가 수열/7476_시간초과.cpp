#include<iostream>
#include<vector>
using namespace std;
int M1, M2;
int arr1[501], arr2[501];
vector<int> v;
vector<int> result;

void update()
{
	if (v.size() <= result.size())
		return;

	int j = 0;
	for (int i = 0; i < M2; ++i)
	{
		if (arr2[i] == v[j])
			++j;
		if (v.size() == j)
			break;
	}
	if (j == v.size())
	{
		if(!result.empty())
			result.clear();
		for (int i = 0; i < v.size(); i++)
			result.push_back(v[i]);
	}

}



void findSequence(int num)
{
	if (num == M1)
		return;

	for (int i = num; i < M1; ++i)
	{
		if (v.empty() || arr1[i] > v[v.size() - 1])
		{
			v.push_back(arr1[i]);
			update();
			findSequence(num + 1);
			v.pop_back();
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> M1;
	for (int i = 0; i < M1; i++)
		cin >> arr1[i];
	cin >> M2;
	for (int i = 0; i < M2; i++)
		cin >> arr2[i];

	findSequence(0);

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	
	return 0;
}