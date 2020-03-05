#include<iostream>
#include<string>
using namespace std;

int main()
{
	string document, word;
	getline(cin, document);
	getline(cin, word);
	int count = 0;
	int doc_size = document.size(), word_size = word.size();

	for (int i = 0; i < doc_size - word_size + 1; ++i)
	{
		int j;
		for (j = 0; j < word_size; ++j)
			if (document[i + j] != word[j])	break;
		if (j == word_size)
		{
			++count;
			i += word_size - 1;
		}
	}
	cout << count << endl;

	return 0;
}