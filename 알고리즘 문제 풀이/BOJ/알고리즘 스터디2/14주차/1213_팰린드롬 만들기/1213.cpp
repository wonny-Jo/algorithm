#include <iostream>
#include <algorithm>
using namespace std;

//알파벳 개수로 생각하자.
//문자열 길이가 짝수인경우 : 알파벳 개수가 홀수인것이 있으면 안된다.
//문자열 길이가 홀수인경우 : 알파벳 개수가 홀수인것이 하나여야한다.
//두 조건을 모두 생각해보면 그냥 알파벳 개수가 홀수인것이 두개이상이면 안된다.
int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int alphabet_cnt[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
		++alphabet_cnt[s[i] - 'A'];

	int odd = 0;
	int mid_index = -1;
	for (int i = 0; i < 26; i++) 
	{
		if (alphabet_cnt[i] > 0&& alphabet_cnt[i] % 2)
		{
			mid_index = i;
			--alphabet_cnt[i];
			odd++;
		}
	}

	if (odd > 1)
		cout << "I'm Sorry Hansoo" << '\n';
	else 
	{
		string ans, temp;
		for (int i = 0; i < 26; i++) 
			if (alphabet_cnt[i] > 0) 
				for (int j = 0; j < alphabet_cnt[i] / 2; j++) 
					ans += i + 'A';
		temp = ans;
		reverse(temp.begin(), temp.end());
		if (mid_index != -1) 
			ans += mid_index + 'A';
		ans += temp;
		cout << ans;
	}
	return 0;
}
