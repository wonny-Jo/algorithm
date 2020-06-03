#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
string s[11];

//誌唖莫税 乞丞税 追戚什研 蟹刊檎
	//呪送 呪汝拭 痕戚 乞砧 赤澗 井酔
	//// けけけ	//// けけけ	//// け		////     け
	//// けけ	////   けけ	//// けけ	////   けけ
	//// け		////     け	//// けけけ	//// けけけ

	//呪汝拭幻 赤澗 井酔
	//// けけけ ////   け
	////   け	//// けけけ

	//呪送拭幻 赤澗 井酔
	//// け		////   け
	//// けけ	//// けけ
	//// け		////   け

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; ++i)
		cin >> s[i];

	int start[11], end[11]; //呪汝戚 糎仙廃陥檎 丞 魁 是帖 走舛
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

	//誌唖莫昔走採斗 督焦背醤敗.
	int startRow = -1; //固 性匝 是帖
	for (int i = 0; i < 10; ++i)
	{
		if (start[i] != -1)
		{
			startRow = i;
			break;
		}
	}
	if (startRow == -1 || start[startRow + 1] == -1) //廃匝戚馬稽幻 赤澗井酔
	{
		cout << 0; return 0;
	}

	int startDist = start[startRow + 1] - start[startRow];
	int endDist = end[startRow + 1] - end[startRow];


	vector<pair<int, int>> v;
	bool isTriangle = false;
	//case 端滴
	//// けけけ	
	//// けけ	
	//// け		
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
	//// けけけ
	////   けけ
	////     け
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
	//// け		//// け		
	//// けけ	//// けけ	
	//// けけけ	//// け
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
	////     け	////   け
	////   けけ	//// けけ
	//// けけけ	////   け
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
	//// けけけ 
	////   け	
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
	////   け
	//// けけけ
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
	//誌唖莫戚 幻級嬢遭板 幻鉦 害精 急匝級 掻 馬蟹虞亀 1戚 赤陥檎 false
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



	//食奄採斗澗 誌唖莫戚 糎仙馬奄拭 室 伽走繊 疎妊研 窒径馬檎吉陥.
	for (int i = 0; i < 3; ++i)
		cout << v[i].first << ' ' << v[i].second << endl;

	return 0;
}