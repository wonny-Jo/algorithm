#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int n; cin >> n;
	int arr[40001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	vector<int> ret;
	for (int i = 0; i < n; i++)
	{
		if (ret.empty()|| ret[ret.size() - 1] < arr[i]) //���� ��ȣ���� ũ�� �ϳ� �߰�.
			ret.push_back(arr[i]);
		else if (ret[ret.size() - 1] > arr[i]) //������ȣ ���� �۴ٸ� �߰� ��ġ�� ã�Ƽ� ������Ʈ
		{
			int temp = lower_bound(ret.begin(), ret.end(), arr[i]) - ret.begin();
			ret[temp] = arr[i];
		}
	}
	cout << ret.size();

	return 0;
}
