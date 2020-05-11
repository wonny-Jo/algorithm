#include<iostream>
using namespace std;
int n, ans, c[101], v[101];
string a[101];

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int i, j, k;

	cin >> n;
	for (i = 0; i < n; i++) 
		cin >> c[i];;
	for (i = 0; i < n; i++)
		cin >> a[i];

	for (k = 0; k < n; k++) 
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) 
				a[i][j] |= a[i][k] & a[k][j];

	for (i = 0; i < n; i++) 
		if (!v[i]) 
		{
			k = c[i];
			for (j = 0; j < n; j++) 
				if (a[i][j] & a[j][i] & 1) 
				{
					if (k > c[j]) 
						k = c[j];
					v[j] = 1;
				}
			ans += k;
		}

	cout << ans;

	return 0;
}