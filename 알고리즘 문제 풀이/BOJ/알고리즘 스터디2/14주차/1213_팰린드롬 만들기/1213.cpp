#include <iostream>
#include <algorithm>
using namespace std;

//���ĺ� ������ ��������.
//���ڿ� ���̰� ¦���ΰ�� : ���ĺ� ������ Ȧ���ΰ��� ������ �ȵȴ�.
//���ڿ� ���̰� Ȧ���ΰ�� : ���ĺ� ������ Ȧ���ΰ��� �ϳ������Ѵ�.
//�� ������ ��� �����غ��� �׳� ���ĺ� ������ Ȧ���ΰ��� �ΰ��̻��̸� �ȵȴ�.
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
