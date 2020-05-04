#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	long long N, K, Q; cin >> N >> K >> Q;
	for (int i = 0; i < Q; i++)
	{
		long long a, b; cin >> a >> b;
		
		if (K == 1) //1진 트리는 무한루프 돌게되므로 예외처리
			cout << abs(a - b)<<'\n';
		else 
		{
			long long cnt = 0;
			// 두 수의 공통 부모를 찾는다.
			while (a != b)
			{
				//둘 중 더 큰 놈을 부모 위치로 옮김
				if (a > b)
					a = (a + K - 2) / K;
				else
					b = (b + K - 2) / K;
				++cnt;
			}
			cout << cnt << '\n';
		}
	}

	return 0;
}