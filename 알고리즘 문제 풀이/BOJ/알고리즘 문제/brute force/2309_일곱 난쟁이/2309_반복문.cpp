#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int key[10];
	for (int i = 0; i < 9; ++i)
		cin >> key[i];
	sort(key, key + 9);
	for (int a = 0; a < 3; ++a)
	{
		for (int b = a+1; b < 4; ++b)
		{	
			for (int c = b+1; c < 5; ++c)
			{
				for (int d = c+1; d < 6; ++d)
				{
					for (int e = d+1; e < 7; ++e)
					{
						for (int f = e+1; f < 8; ++f)
						{
							for (int g = f+1; g < 9; ++g)
							{
								if (key[a] + key[b] + key[c] + key[d] + key[e] + key[f] + key[g] == 100)
								{
									cout<< key[a] << endl 
										<< key[b] << endl 
										<< key[c] << endl 
										<< key[d] << endl 
										<< key[e] << endl 
										<< key[f] << endl 
										<< key[g];
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}