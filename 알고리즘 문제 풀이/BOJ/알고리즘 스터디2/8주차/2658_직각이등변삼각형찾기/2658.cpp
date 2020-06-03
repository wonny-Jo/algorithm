#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
string s[11];

//�ﰢ���� ����� ���̽��� ������
	//���� ���� ���� ��� �ִ� ���
	//// ������	//// ������	//// ��		////     ��
	//// ����	////   ����	//// ����	////   ����
	//// ��		////     ��	//// ������	//// ������

	//���򿡸� �ִ� ���
	//// ������ ////   ��
	////   ��	//// ������

	//�������� �ִ� ���
	//// ��		////   ��
	//// ����	//// ����
	//// ��		////   ��

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; ++i)
		cin >> s[i];

	int start[11], end[11]; //������ �����Ѵٸ� �� �� ��ġ ����
	memset(start, -1, sizeof(start));
	memset(end, -1, sizeof(end));
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{

			if (s[i][j] == '1')
			{
				if (start[i] == -1)
					start[i] = j;
				end[i] = j;
			}
		}
		if (start[i] != -1)
		{
			for (int j = start[i]; j <= end[i]; j++)
			{
				if (s[i][j] == '0')
				{
					cout << 0;
					return 0;
				}
			}
		}
	}

	//�ﰢ���������� �ľ��ؾ���.
	int startRow = -1; //�� ���� ��ġ
	for (int i = 0; i < 10; ++i)
	{
		if (start[i] != -1)
		{
			startRow = i;
			break;
		}
	}
	if (startRow == -1 || start[startRow + 1] == -1) //�������Ϸθ� �ִ°��
	{
		cout << 0; return 0;
	}

	int startDist = start[startRow + 1] - start[startRow];
	int endDist = end[startRow + 1] - end[startRow];


	vector<pair<int, int>> v;
	bool isTriangle = false;
	//case üũ
	//// ������	
	//// ����	
	//// ��		
	int nextRow = startRow + 1;
	if (start[startRow] != end[startRow] && startDist == 0 && endDist == -1)
	{
		while (1)
		{
			if (start[nextRow + 1] == -1)
			{
				if (start[nextRow] == end[nextRow])
					isTriangle = true;
				break;
			}
			if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
				break;
			++nextRow;
		}
		v.push_back({ startRow + 1,start[startRow] + 1 });
		v.push_back({ startRow + 1,end[startRow] + 1 });
		v.push_back({ nextRow + 1,start[nextRow] + 1 });
	}
	//// ������
	////   ����
	////     ��
	else if (start[startRow] != end[startRow] && endDist == 0 && startDist == 1)
	{
		while (1)
		{
			if (start[nextRow + 1] == -1)
			{
				if (start[nextRow] == end[nextRow])
					isTriangle = true;
				break;
			}
			if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
				break;
			++nextRow;
		}
		v.push_back({ startRow + 1,start[startRow] + 1 });
		v.push_back({ startRow + 1,end[startRow] + 1 });
		v.push_back({ nextRow + 1,start[nextRow] + 1 });
	}
	//// ��		//// ��		
	//// ����	//// ����	
	//// ������	//// ��
	else if (start[startRow] == end[startRow] && startDist == 0 && endDist == 1)
	{
		bool switching = 0;
		while (1)
		{
			if (!switching)
			{
				if (start[nextRow + 1] == -1)
				{
					if (end[nextRow] - start[nextRow] == (nextRow - startRow))
						isTriangle = true;
					break;
				}
				if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
				{
					if (end[nextRow + 1] - end[nextRow] == (-1) * endDist)
					{
						endDist = (-1) * endDist;
						switching = 1;
					}
					else
						break;
				}
			}
			else
			{
				if (start[nextRow + 1] == -1)
				{
					if (start[nextRow] == end[nextRow])
						isTriangle = true;
					break;
				}
				if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
					break;

			}
			++nextRow;
		}

		if (!switching)
		{
			v.push_back({ startRow + 1,start[startRow] + 1 });
			v.push_back({ nextRow + 1,start[nextRow] + 1 });
			v.push_back({ nextRow + 1,end[nextRow] + 1 });
		}
		else
		{
			v.push_back({ startRow + 1,start[startRow] + 1 });
			v.push_back({ (startRow + nextRow) / 2 + 1,end[(startRow + nextRow) / 2] + 1 });
			v.push_back({ nextRow + 1,end[nextRow] + 1 });
		}
	}
	////     ��	////   ��
	////   ����	//// ����
	//// ������	////   ��
	else if (start[startRow] == end[startRow] && endDist == 0 && startDist == -1)
	{
		bool switching = 0;
		while (1)
		{
			if (!switching)
			{
				if (start[nextRow + 1] == -1)
				{
					if (end[nextRow] - start[nextRow] == (nextRow - startRow))
						isTriangle = true;
					break;
				}
				if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
				{
					if (start[nextRow + 1] - start[nextRow] == (-1) * startDist)
					{
						startDist = (-1) * startDist;
						switching = 1;
					}
					else
						break;

				}
			}
			else
			{
				if (start[nextRow + 1] == -1)
				{
					if (start[nextRow] == end[nextRow])
						isTriangle = true;
					break;
				}
				if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
					break;

			}
			++nextRow;
		}

		if (!switching)
		{
			v.push_back({ startRow + 1,end[startRow] + 1 });
			v.push_back({ nextRow + 1,start[nextRow] + 1 });
			v.push_back({ nextRow + 1,end[nextRow] + 1 });
		}
		else
		{
			v.push_back({ startRow + 1,end[startRow] + 1 });
			v.push_back({ (startRow + nextRow) / 2 + 1,start[(startRow + nextRow) / 2] + 1 });
			v.push_back({ nextRow + 1,end[nextRow] + 1 });
		}
	}
	//// ������ 
	////   ��	
	else if (start[startRow] != end[startRow] && startDist == 1 && endDist == -1)
	{
		while (1)
		{
			if (start[nextRow + 1] == -1)
			{
				if (start[nextRow] == end[nextRow])
					isTriangle = true;
				break;
			}
			if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
				break;
			++nextRow;
		}
		v.push_back({ startRow + 1,start[startRow] + 1 });
		v.push_back({ startRow + 1,end[startRow] + 1 });
		v.push_back({ nextRow + 1,start[nextRow] + 1 });
	}
	////   ��
	//// ������
	else if (start[startRow] == end[startRow] && startDist == -1 && endDist == 1)
	{
		while (1)
		{
			if (start[nextRow + 1] == -1)
			{
				if (end[nextRow] - start[nextRow] == 2 * (nextRow - startRow))
					isTriangle = true;
				break;
			}
			if (start[nextRow + 1] - start[nextRow] != startDist || end[nextRow + 1] - end[nextRow] != endDist)
				break;
			++nextRow;
		}
		v.push_back({ startRow + 1,start[startRow] + 1 });
		v.push_back({ nextRow + 1,start[nextRow] + 1 });
		v.push_back({ nextRow + 1,end[nextRow] + 1 });
	}

	if (!isTriangle)
	{
		cout << 0 << endl;
		return 0;
	}
	//�ﰢ���� ��������� ���� ���� ���ٵ� �� �ϳ��� 1�� �ִٸ� false
	else
	{
		int checkRow = nextRow + 1;
		for (int i = checkRow; i < 10; ++i)
		{
			if (start[i] != -1)
			{
				cout << 0 << endl;
				return 0;
			}
		}
	}



	//������ʹ� �ﰢ���� �����ϱ⿡ �� ������ ��ǥ�� ����ϸ�ȴ�.
	for (int i = 0; i < 3; ++i)
		cout << v[i].first << ' ' << v[i].second << endl;

	return 0;
}