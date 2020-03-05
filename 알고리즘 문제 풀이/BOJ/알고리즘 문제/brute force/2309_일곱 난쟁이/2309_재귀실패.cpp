#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> key;
int n = 9;
int sumOfDatas(vector<int>& data)
{
	int sum=0;
	int size = data.size();
	for (int i = 0; i < size; ++i)
		sum += data[i];
	return sum;
}

void printData(vector<int>& data)
{
	int size = data.size();
	for (int i = 0; i < size; ++i)
		cout << data[i] << endl;
}


void pick(vector<int>& data, int remainNum)
{
	if (remainNum == 0)
	{
		if(sumOfDatas(data)==100)
			printData(data);
		return;
	}
	int start = data.empty() ? 0 : data.size();
	for (int i = start; i <n; ++i)
	{
		data.push_back(key[i]);
		pick(data, remainNum - 1);
		data.pop_back();
	}
}


int main()
{
	int data;
	for (int i = 0; i < 9; ++i)
	{
		cin >> data;
		key.push_back(data);
	}
	sort(key.begin(), key.end());
	vector<int> key_data;
	pick(key_data, 7);

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}