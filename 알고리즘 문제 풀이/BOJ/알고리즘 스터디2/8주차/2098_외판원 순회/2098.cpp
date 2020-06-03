#include<iostream> 
#include<string.h>
#include<algorithm>
using namespace std; 
int n; 
int route[16][16]; 
int dp[16][1<<16]; 

int dfs(int currentCity, int bit)
{ 
	int& ret = dp[currentCity][bit];
	if (ret != -1)
		return ret;
	
	if (bit == (1 << n) - 1)
	{
		if (route[currentCity][0] != 0)
			return route[currentCity][0];
		else
			return 1000000000;
	}

	ret = 1000000000;
	for(int i = 0; i < n; i++)
	{ 
		if(route[currentCity][i] && !(bit & (1 << i)))
		{ 
			int visit = bit | (1 << i);
			ret = min(ret, dfs(i, visit) + route[currentCity][i]);
		} 
	} 
	return ret; 
} 

int main()
{ 
	cin.sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j++) 
			cin >> route[i][j];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1); 
	return 0; 
}
