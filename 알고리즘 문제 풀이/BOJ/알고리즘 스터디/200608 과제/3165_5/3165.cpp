#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	string N;
	int K;
	cin >> N >> K;
	int NSize = N.size();
	if (NSize < K)
	{
		for (int i = 0; i < K; i++)
			cout << '5';
		return 0;
	}
	else if (NSize == K)
	{
		string s;
		for (int i = 0; i < K; i++)
			s += '5';
		if (N >= s)
			cout << '1' + s;
		else
			cout << s;
		return 0;
	}
	else
	{
		string ret = "";
		bool c[16];
		for (int i = 0; i < NSize-K; i++)
			c[i] = 0;
		for (int i = NSize-K; i < NSize; i++)
			c[i] = 1;
		
		string s;
		for (int i = 0; i < NSize; i++)
		{
			if (c[i])
				s += '5';
			else
				s += '0';
		}
		int idx = NSize;
		for (int i = 0; i < NSize; i++)
		{
			if (s[i] > N[i])
			{
				idx = i;
				break;
			}
		}
		for (int i = 0; i < idx; i++)
			if (!c[i])
				s[i] = N[i];
		for (int i = idx; i < NSize; i++)
			if (!c[i])
				s[i] = '0';
		if (s > N && (ret == "" || ret > s))
			ret = s;
		bool check = false;
		for (int i = NSize - 1; i >= 0; i--)
		{
			if (!c[i])
			{
				if (check)
					s[i] = N[i];
				else
				{
					if (N[i] != '9')
					{
						s[i] = N[i] + 1;
						check = true;
					}
				}
			}
		}
		if (s>N && (ret == "" || ret > s))
			ret = s;
		while (next_permutation(c, c + NSize))
		{
			for (int i = 0; i < NSize; i++)
			{
				if (c[i])
					s[i] = '5';
				else
					s[i] = '0';
			}

			int idx = NSize;
			for (int i = 0; i < NSize; i++)
			{
				if (s[i] > N[i])
				{
					idx = i;
					break;
				}
			}
			for (int i = 0; i < idx; i++)
				if (!c[i])
					s[i] = N[i];
			for (int i = idx; i < NSize; i++)
				if (!c[i])
					s[i] = '0';
			if (s > N && (ret == "" || ret > s))
				ret = s;

			bool check = false;
			for (int i = NSize - 1; i >= 0; i--)
			{
				if (!c[i])
				{
					if (check)
						s[i] = N[i];
					else
					{
						if (s[i] != '9')
						{
							s[i] = N[i] + 1;
							check = true;
						}
					}
				}
			}
			
			if (s>N && (ret == "" || ret > s))
				ret = s;
		}

		if (ret == "")
		{
			cout << '1';
			for (int i = 0; i < NSize - K; i++)
				cout << '0';
			for (int i = NSize - K; i < NSize; i++)
				cout << '5';
		}
		else
			cout << ret;
	}

	return 0;
}