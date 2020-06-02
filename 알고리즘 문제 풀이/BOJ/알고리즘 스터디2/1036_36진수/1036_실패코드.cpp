#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
int ch_cnt[52][36] = { 0 }; //각 자릿수에서 각 문자의 갯수
int priority[36];

//두 문자중 변환할 우선순위 체크
bool compare(int a, int b)
{
	int i = 0;
	int ret_a, ret_b;
	while (i <= 51 && (ret_a = ch_cnt[i][a] * (35 - a)) == (ret_b = ch_cnt[i][b] * (35 - b)))
		++i;
	if (ret_a == ret_b)
		return false;
	return ret_a > ret_b;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	//각 문자의 자릿수별 갯수 저장
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		int size = s.size() - 1;
		for (int j = 0; j <= size; j++)
		{
			if ('0' <= s[j] && s[j] <= '9')
				++ch_cnt[51 - size + j][s[j] - '0'];
			else
				++ch_cnt[51 - size + j][s[j] - 'A' + 10];
		}
	}
	for (int i = 51; i > 0; i--)
		for (int j = 0; j < 36; j++)
			if (ch_cnt[i][j] >= 36)
			{
				ch_cnt[i - 1][j] += ch_cnt[i][j] / 36;
				ch_cnt[i][j] %= 36;
			}

	cin >> K;
	for (int i = 0; i < 36; i++)
		priority[i] = i;

	//제일 높은 자릿수부터 확인. (35 - j) * cnt[j]가 큰 순서대로 선택.
	sort(priority, priority + 35, compare);


	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j <= 51; j++)
		{
			ch_cnt[j][35] += ch_cnt[j][priority[i]];
			ch_cnt[j][priority[i]] = 0;
		}
	}

	int ret[52] = { 0 };
	for (int i = 51; i > 0; i--)
	{
		for (int j = 0; j < 36; j++)
			ret[i] += ch_cnt[i][j] * j;
		ret[i - 1] = ret[i] / 36;
		ret[i] %= 36;
	}

	int start = 0;
	while (ret[start] == 0)
		++start;

	if (start == 52)
	{
		cout << 0;
		return 0;
	}

	for (int i = start; i <= 51; i++)
	{
		if (ret[i] < 10)
			cout << (char)('0' + ret[i]);
		else
			cout << (char)('A' + (ret[i] - 10));
	}

	return 0;
}