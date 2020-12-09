#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int pos = 0;
	int len = number.size() - k;
	while (k > 0 && answer.size() < len)
	{
		char max_num = '0';
		int cnt = 0;
		for (int i = pos; i <= pos + k; i++)
		{
			if (max_num < number[i])
			{
				max_num = number[i];
				cnt = i - pos;
			}
		}
		pos += cnt + 1;
		answer += number[pos - 1];
		k -= cnt;
	}
	if (k == 0)
		for (int i = pos; i < number.size(); i++)
			answer += number[i];
	return answer;
}