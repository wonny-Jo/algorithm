//quick selection or quick search�� �����ϸ� 
//O(n)�� �ð����⵵�� ��������
#include<iostream>
using namespace std;
int arr[5000001];
int N, K;

void Swap(int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// �ǹ��� �������� �������� ���� ū���� ���������� ����
// ��ȯ���� �ǹ��� ��ġ
int partition(int start, int end)
{
	int pivot = arr[start]; //�ǹ��� �� �տ� �ִ� ������ ����
	int left = start + 1;
	int right = end;

	while (left <= right) //���ʰ� ������ ��ġ�� �����Ҷ����� �ݺ�
	{
		while (pivot >= arr[left] && left <= end) //���ʺ��� �ǹ����� ū ���� ��ġ�� ã��
			++left;
		while (pivot <= arr[right] && right >= start + 1) //�����ʺ��� �ǹ����� ���� ���� ��ġ�� ã��
			--right;
		if (left <= right) //���ʰ� �������� �������� �ʾ����� ���� �ٲ�
			Swap(left, right);
	}
	Swap(start, right); //�ǹ��� �������� ���� �ٲ� // �������� �ǹ����� ���� ���� ��ġ�̱⿡
	return right;
}

//�ǹ��� �������� ���� ã�� �ǹ����� ���� �迭�� �ǹ����� ū �迭��
//K�� �ִ� �迭�� �ٽ� ����
int quickSelection(int start, int end)
{
	int pivot = partition(start, end);
	if (pivot == K)
		return arr[pivot];
	else if (pivot > K)
		return quickSelection(start, pivot - 1);
	else if (pivot < K)
		return quickSelection(pivot + 1, end);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	--K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cout << quickSelection(0, N - 1);
	return 0;
}