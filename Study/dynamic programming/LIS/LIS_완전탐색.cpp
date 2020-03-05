#include<iostream>
using namespace std;
#include<vector>

int max(int a, int b)
{
	return a > b ? a : b;
}

int lis(vector<int> A)
{
	if (A.empty())
		return 0;
	int ret = 0;
	int size = A.size();
	for (int i = 0; i < size; ++i)
	{
		vector<int> B;
		for (int j = i+1; j < size; ++j)
		{
			if (A[i] < A[j])
				B.push_back(A[j]);
		}
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

int main()
{
	

	return 0;
}