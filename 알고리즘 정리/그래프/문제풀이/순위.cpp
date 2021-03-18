#include<iostream>


#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	bool arr[101][101] = { 0 };
	for (int i = 0; i <= n; i++)
		arr[i][i] = 1;
	for (int i = 0; i < results.size(); i++)
		arr[results[i][0]][results[i][1]] = 1;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] || arr[j][i])
				++cnt;
		}
		if (cnt == n)
			++answer;
	}
	return answer;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
	cout << solution(5, { {4,3},{4, 2},{3, 2},{1, 2},{2, 5} });
    return 0;
}