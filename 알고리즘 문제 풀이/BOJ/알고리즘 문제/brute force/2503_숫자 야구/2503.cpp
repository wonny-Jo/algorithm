#include<iostream>
#include<vector>
using namespace std;
int N;

bool checkPass(vector <pair<int, pair<int, int>>> v, int num[3])
{
	int strike_num, ball_num;
	int checkNum[3];
	for (vector <pair<int, pair<int, int>>>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		int temp=(*iter).first;
		checkNum[2] = temp % 10; temp /= 10;
		checkNum[1] = temp % 10; temp /= 10;
		checkNum[0] = temp;
		strike_num = 0; ball_num = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (num[i] == checkNum[i])
				++strike_num;
			else if (num[i] == checkNum[(i + 1) % 3]|| num[i] == checkNum[(i + 2) % 3])
				++ball_num;
		}
		if (strike_num != (*iter).second.first || ball_num != (*iter).second.second)
			return false;
	}
	return true;
}

int search(vector <pair<int, pair<int, int>>> v)
{
	int num[3];
 	int count = 0;
	for (int i = 1; i < 10; ++i)
	{
		num[0] = i;
		for (int j = 1; j < 10; ++j)
		{
			if (num[0] != j)
			{
				num[1] = j;
				for (int k = 1; k < 10; ++k)
				{
					if (num[0] != k && num[1] != k)
					{
						num[2] = k;
						if (checkPass(v, num))
							++count;
					}
				}
			}
		}
	}
	return count;
}

int main()
{
	cin >> N;
	vector <pair<int, pair<int, int>>> v;
	int num, strike_num, ball_num;
	for (int i = 0; i < N; ++i)
	{
		cin >> num >> strike_num >> ball_num;
		v.push_back({ num,{strike_num , ball_num} });
	}

	cout<< search(v);
	return 0;
}